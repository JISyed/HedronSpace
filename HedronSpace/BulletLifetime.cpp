#include "BulletLifetime.hpp"
#include <iostream>
#include "GameObject.hpp"

// System Headers not needed in header


// SFEW Headers not needed in header
#include "Random.hpp"
#include "TimerContainer.hpp"

namespace sfew
{
	namespace component
	{
		// Ctor/Dtor ========================================

		// Constructor
		BulletLifetime::BulletLifetime(std::weak_ptr<GameObject> owningGameObject) :
			CustomComponent(owningGameObject)
		{
			Start();
		}

		// Destructor
		BulletLifetime::~BulletLifetime()
		{
			Cleanup();
		}

		// Required Routines =========================================

		// Runs at contruction of component
		void BulletLifetime::Start()
		{
			// Mark itself for deletion after cetain number of seconds
			_lifeTime = 4.0f;
			_lifeTimer = TimerContainer::Create(
				sf::seconds(_lifeTime),
				[this]()
				{
					this->GetGameObject()._Get()->Destroy();
				}
			);
		}

		// Runs every frame
		void BulletLifetime::Update()
		{
			
		}

		// Runs at destruction of component
		void BulletLifetime::Cleanup()
		{
			if(!_lifeTimer.expired())
			{
				_lifeTimer._Get()->Destroy();
			}
		}

		// Run if there is a collision with an object of a different group
		void BulletLifetime::OnCollision(PhysicsCollisionGroups otherGroup, 
										 std::weak_ptr<PhysicsEntity> otherEntity)
		{
			
		}

		// Custom Routines =========================================

		// Properties =========================================

		// Private Routines =========================================

	} // namespace sfew::component
} // namespace sfew