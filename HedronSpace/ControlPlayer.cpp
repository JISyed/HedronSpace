#include "ControlPlayer.hpp"
#include <iostream>
#include "GameObject.hpp"

// System Headers not needed in header
#include <SFML/Window.hpp>

// SFEW Headers not needed in header
#include "Random.hpp"

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
			_thrustStrength = 6.0f;
			_turnStrength = 120.0f;
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