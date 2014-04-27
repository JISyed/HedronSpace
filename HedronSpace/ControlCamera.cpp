#include "ControlCamera.hpp"
#include <iostream>
#include "GameObject.hpp"

// System Headers not needed in header


// SFEW Headers not needed in header
#include "Random.hpp"
#include "GameObjectContainer.hpp"

namespace sfew
{
	namespace component
	{
		// Ctor/Dtor ========================================

		// Constructor
		ControlCamera::ControlCamera(std::weak_ptr<GameObject> owningGameObject) :
			CustomComponent(owningGameObject)
		{
			Start();
		}

		// Destructor
		ControlCamera::~ControlCamera()
		{
			Cleanup();
		}

		// Required Routines =========================================

		// Runs at contruction of component
		void ControlCamera::Start()
		{
			_camera = Camera::GetInstance();
			retrievePlayer();
			_distanceBehind = 6.0f;
			_height = 4.0f;
		}

		// Runs every frame
		void ControlCamera::Update()
		{
			// Assume the player exists
			if(!_playerGameObject.expired())
			{
				// Set camera position
				Vector3 newPos = _playerTransform._Get()->GetPosition() + (-_distanceBehind * _playerTransform._Get()->Forward()) + Vector3(0.0f, _height, 0.0f);
				_camera._Get()->SetPosition(newPos);

				// Set camera to look at player
				_camera._Get()->LookAtPoint(_playerTransform._Get()->GetPosition());
			}
		}

		// Runs at destruction of component
		void ControlCamera::Cleanup()
		{

		}

		// Run if there is a collision with an object of a different group
		void ControlCamera::OnCollision(PhysicsCollisionGroups otherGroup, 
										 std::weak_ptr<PhysicsEntity> otherEntity)
		{
			
		}

		// Custom Routines =========================================

		// Properties =========================================

		// Private Routines =========================================

		// Get player and it's transform as weak pointers
		void ControlCamera::retrievePlayer()
		{
			_playerGameObject = GameObjectContainer::GetByName("Player");
			if(!_playerGameObject.expired())
			{
				_playerTransform = _playerGameObject._Get()->GetTransform();
			}
		}

	} // namespace sfew::component
} // namespace sfew