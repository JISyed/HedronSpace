#include "ControlEnemy.hpp"
#include <iostream>
#include "GameObject.hpp"

// System Headers not needed in header


// SFEW Headers not needed in header
#include "Random.hpp"
#include "TimerContainer.hpp"
#include "PrefabricationRegistry.hpp"
#include "GameObjectContainer.hpp"
#include "AudioRegistry.hpp"

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
			// Find game controller
			auto gameCtrlrObj = GameObjectContainer::GetByName("GameCtrlr");
			if(!gameCtrlrObj.expired())
			{
				_gameCtrlr = gameCtrlrObj._Get()->GetCustomComponent<ControlGame>();

				// Increment Enemy count
				_gameCtrlr._Get()->IncrementEnemy();

				_laserSnd = AudioRegistry::GetByName("EnemyLaserSnd");
				_deathSnd = AudioRegistry::GetByName("EnemyDeathSnd");
			}

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
					_laserSnd._Get()->Play();
				}
			);
			_shootTimer._Get()->SetLooping(true);

			// Set health
			_health = 3;
		}

		// Runs every frame
		void ControlEnemy::Update()
		{
			
		}

		// Runs at destruction of component
		void ControlEnemy::Cleanup()
		{
			// Decrement Enemy count
			if(!_gameCtrlr.expired())
			{
				_gameCtrlr._Get()->DecrementEnemy();
			}

			// Mark timer for deletion
			_shootTimer._Get()->Destroy();
		}

		// Run if there is a collision with an object of a different group
		void ControlEnemy::OnCollision(PhysicsCollisionGroups otherGroup, 
										 std::weak_ptr<PhysicsEntity> otherEntity)
		{
			// Check if collision was with a player bullet
			if(otherGroup == PhysicsCollisionGroups::GroupB)
			{
				// Delete the bullet no matter what
				otherEntity._Get()->GetGameObject()._Get()->Destroy();

				// Decrement health
				_health--;

				// Add points for hitting enemy
				auto scoreKeeperObj = GameObjectContainer::GetByName("ScoreKeeper");
				auto scoreKeeper = scoreKeeperObj._Get()->GetCustomComponent<component::ScoreKeeper>();
				scoreKeeper._Get()->AddScore(5);

				// Shoot a bullet to counter the player (if player exists)
				auto playerGameObject = GameObjectContainer::GetByName("Player");
				if(!playerGameObject.expired())
				{
					Vector3 playerPos = playerGameObject._Get()->GetTransform()._Get()->GetPosition();
					auto bulletPrefab = PrefabricationRegistry::Get<sfew::prefab::EnemyLaserPrefab>();
					auto bullet = bulletPrefab._Get()->MakeObject();
					bullet._Get()->GetTransform()._Get()->SetPosition(
						this->GetGameObject()._Get()->GetTransform()._Get()->GetPosition()
					);
					Vector3 playerDirection = playerPos - bullet._Get()->GetTransform()._Get()->GetPosition();
					playerDirection = glm::normalize(playerDirection);
					bullet._Get()->GetComponent<PhysicsComponent>()._Get()->GetPhysicsEntity()._Get()->SetVelocity(
						Vector3(playerDirection * 7.0f)
					);
					_laserSnd._Get()->Play();
				}

				// Check if health ran out
				if(_health < 0)
				{
					// Add points for killing enemy
					auto scoreKeeperObj = GameObjectContainer::GetByName("ScoreKeeper");
					auto scoreKeeper = scoreKeeperObj._Get()->GetCustomComponent<component::ScoreKeeper>();
					scoreKeeper._Get()->AddScore(75);

					// Delete self
					this->GetGameObject()._Get()->Destroy();

					_deathSnd._Get()->Play();
				}
			}
		}

		// Custom Routines =========================================

		// Properties =========================================

		// Private Routines =========================================

	} // namespace sfew::component
} // namespace sfew