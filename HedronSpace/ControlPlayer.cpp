#include "ControlPlayer.hpp"
#include <iostream>
#include "GameObject.hpp"

// System Headers not needed in header
#include <SFML/Window.hpp>

// SFEW Headers not needed in header
#include "Random.hpp"
#include "PrefabricationRegistry.hpp"

namespace sfew
{
	namespace component
	{
		// Ctor/Dtor ========================================

		// Constructor
		ControlPlayer::ControlPlayer(std::weak_ptr<GameObject> owningGameObject) :
			CustomComponent(owningGameObject)
		{
			Start();
		}

		// Destructor
		ControlPlayer::~ControlPlayer()
		{
			Cleanup();
		}

		// Required Routines =========================================

		// Runs at contruction of component
		void ControlPlayer::Start()
		{
			// MAKE SURE that Physics component was added first!
			_physics = GetGameObject()._Get()->GetComponent<PhysicsComponent>()._Get()->GetPhysicsEntity();
			_transform = GetGameObject()._Get()->GetTransform();
			_spacePressedLastFrame = false;
			_thrustStrength = 10.0f;
			_turnStrength = 200.0f;
		}

		// Runs every frame
		void ControlPlayer::Update()
		{
			Vector3 forward = _transform._Get()->Forward();

			// Thrust forward
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
				!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				_physics._Get()->SetAcceleration( forward * _thrustStrength );
			}
			// Thrust backward
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
				!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				_physics._Get()->SetAcceleration( forward * -_thrustStrength );
			}
			// Stop thrusting if not pressing either key
			else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
				!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				_physics._Get()->SetAcceleration( Vector3(0.0f, 0.0f, 0.0f) );
			}

			// Thrust counter clockwise
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
				!sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				_physics._Get()->SetRotationalAcceleration( Transform::WorldUp() * _turnStrength );
			}
			// Thrust clockwise
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
				!sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				_physics._Get()->SetRotationalAcceleration( Transform::WorldUp() * -_turnStrength );
			}
			// Stop thrusting if not pressing either key
			else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
				!sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				_physics._Get()->SetRotationalAcceleration( Vector3(0.0f, 0.0f, 0.0f) );
			}

			// Check if the spacebar was pressed at the moment
			// Then fire a bullet
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !_spacePressedLastFrame)
			{
				auto bulletPrefab = PrefabricationRegistry::Get<prefab::PlayerLaserPrefab>();
				if(!bulletPrefab.expired())
				{
					auto bullet = bulletPrefab._Get()->MakeObject();
					auto bulletTransform = bullet._Get()->GetTransform();
					bulletTransform._Get()->SetPosition(
						GetGameObject()._Get()->GetTransform()._Get()->GetPosition()
					);
					bulletTransform._Get()->SetEulerAngles(
						GetGameObject()._Get()->GetTransform()._Get()->GetEulerAngles()
					);
					bullet._Get()->GetComponent<PhysicsComponent>()._Get()->GetPhysicsEntity()._Get()->SetVelocity(
						Vector3(bullet._Get()->GetTransform()._Get()->Forward() * 20.0f)
					);
				}
			}

			// Keep record of spacebar's state for next frame (This should be last!)
			_spacePressedLastFrame = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
		}

		// Runs at destruction of component
		void ControlPlayer::Cleanup()
		{

		}

		// Run if there is a collision with an object of a different group
		void ControlPlayer::OnCollision(PhysicsCollisionGroups otherGroup, 
										 std::weak_ptr<PhysicsEntity> otherEntity)
		{
			
		}

		// Custom Routines =========================================

		// Properties =========================================

		// Private Routines =========================================

	} // namespace sfew::component
} // namespace sfew