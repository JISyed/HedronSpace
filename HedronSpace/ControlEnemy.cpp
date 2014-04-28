#include "ControlEnemy.hpp"
#include <iostream>
#include "GameObject.hpp"

// System Headers not needed in header


// SFEW Headers not needed in header
#include "Random.hpp"
#include "TimerContainer.hpp"
#include "PrefabricationRegistry.hpp"

namespace sfew
{
	namespace component
	{
		// Ctor/Dtor ========================================

		// Constructor
		ControlEnemy::ControlEnemy(std::weak_ptr<GameObject> owningGameObject) :
			CustomComponent(owningGameObject)
		{
			Start();
		}

		// Destructor
		ControlEnemy::~ControlEnemy()
		{
			Cleanup();
		}

		// Required Routines =========================================

		// Runs at contruction of component
		void ControlEnemy::Start()
		{
			// Make a timer for shooting bullets every time interval in seconds
			_shootInterval = 1.2f;
			_shootTimer = TimerContainer::Create(
				sf::seconds(_shootInterval),
				[this]()
				{
					auto bulletPrefab = PrefabricationRegistry::Get<sfew::prefab::EnemyLaserPrefab>();
					auto bullet = bulletPrefab._Get()->MakeObject();
					float chosenAngle = Random::Range(0.0f, 359.9f);
					bullet._Get()->GetTransform()._Get()->Rotate(Vector3(0.0f, chosenAngle, 0.0f));
					bullet._Get()->GetTransform()._Get()->SetPosition(
						this->GetGameObject()._Get()->GetTransform()._Get()->GetPosition()
					);
					bullet._Get()->GetComponent<PhysicsComponent>()._Get()->GetPhysicsEntity()._Get()->SetVelocity(
						Vector3(bullet._Get()->GetTransform()._Get()->Forward() * 8.5f)
					);
				}
			);
			_shootTimer._Get()->SetLooping(true);
		}

		// Runs every frame
		void ControlEnemy::Update()
		{
			
		}

		// Runs at destruction of component
		void ControlEnemy::Cleanup()
		{
			_shootTimer._Get()->Destroy();
		}

		// Run if there is a collision with an object of a different group
		void ControlEnemy::OnCollision(PhysicsCollisionGroups otherGroup, 
										 std::weak_ptr<PhysicsEntity> otherEntity)
		{
			
		}

		// Custom Routines =========================================

		// Properties =========================================

		// Private Routines =========================================

	} // namespace sfew::component
} // namespace sfew