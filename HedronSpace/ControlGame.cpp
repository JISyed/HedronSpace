#include "ControlGame.hpp"
#include <iostream>
#include "GameObject.hpp"

// System Headers not needed in header


// SFEW Headers not needed in header
#include "Random.hpp"
#include "PrefabricationRegistry.hpp"
#include "GameObjectContainer.hpp"
#include "AudioRegistry.hpp"

namespace sfew
{
	namespace component
	{
		// Ctor/Dtor ========================================

		// Constructor
		ControlGame::ControlGame(std::weak_ptr<GameObject> owningGameObject) :
			CustomComponent(owningGameObject)
		{
			Start();
		}

		// Destructor
		ControlGame::~ControlGame()
		{
			Cleanup();
		}

		// Required Routines =========================================

		// Runs at contruction of component
		void ControlGame::Start()
		{
			_fieldSize = 80.0f;
			_gemCount = 0;
			_enemyCount = 0;
			_spawnedGems = 3;
			_spawnedEnemies = 3;
			_maxGems = 20;
			_maxEnemies = 10;

			_startSound = AudioRegistry::GetByName("StartSnd");
			_levelUpSound = AudioRegistry::GetByName("LevelUp");
			_gameMusic = AudioRegistry::GetByName("RollingMus");

			_startSound._Get()->Play();
			_gameMusic._Get()->SetVolume(40.0f);
			_gameMusic._Get()->Play();
		}

		// Runs every frame
		void ControlGame::Update()
		{
			// Spawn more enemies if none
			if(_enemyCount <= 0)
			{
				respawnAllEnemies();
			}

			// Spawn more gems if none
			if(_gemCount <= 0)
			{
				respawnAllGems();
			}
		}

		// Runs at destruction of component
		void ControlGame::Cleanup()
		{

		}

		// Run if there is a collision with an object of a different group
		void ControlGame::OnCollision(PhysicsCollisionGroups otherGroup, 
										 std::weak_ptr<PhysicsEntity> otherEntity)
		{
			
		}

		// Custom Routines =========================================

		// Properties =========================================

		void ControlGame::IncrementGem()
		{
			_gemCount++;
		}

		void ControlGame::DecrementGem()
		{
			_gemCount--;
		}

		void ControlGame::IncrementEnemy()
		{
			_enemyCount++;
		}

		void ControlGame::DecrementEnemy()
		{
			_enemyCount--;
		}

		void ControlGame::SetFieldSize(float newSize)
		{
			_fieldSize = newSize;
		}

		// Private Routines =========================================

		void ControlGame::respawnAllEnemies()
		{
			// Increase the amount of enemies to spawn
			_spawnedEnemies++;
			if(_spawnedEnemies > _maxEnemies) _spawnedEnemies = _maxEnemies;

			// Spawn them
			for (int i = 0; i < _spawnedEnemies; i++)
			{
				spawnOneEnemy();
			}
		}

		void ControlGame::respawnAllGems()
		{
			// Increase the amount of enemies to spawn
			_spawnedGems++;
			if(_spawnedGems > _maxGems) _spawnedGems = _maxGems;

			// Spawn them
			for (int i = 0; i < _spawnedGems; i++)
			{
				spawnOneGem();
			}

			// Increment level
			auto scoreKeeperObj = GameObjectContainer::GetByName("ScoreKeeper");
			auto scoreKeeper = scoreKeeperObj._Get()->GetCustomComponent<component::ScoreKeeper>();
			scoreKeeper._Get()->IncrementLevel();
			_levelUpSound._Get()->Play();

			// Make more enemies
			respawnSomeEnemiesIfGemsCleared();
		}

		void ControlGame::respawnSomeEnemiesIfGemsCleared()
		{
			// Spawn only as many enemies as to match _spawnedEnemies
			_spawnedEnemies++;
			int missingEnemies = _spawnedEnemies - _enemyCount;
			if(missingEnemies <= 0) return;
			for (int i= 0; i < missingEnemies; i++)
			{
				spawnOneEnemy();
			}
		}

		void ControlGame::spawnOneEnemy()
		{
			auto enemyPrefab = PrefabricationRegistry::Get<prefab::EnemyPrefab>();
			auto e1 = enemyPrefab._Get()->MakeObject();
			Vector3 newPosition = Vector3(
				Random::Range(0.0f, _fieldSize),
				0.0f,
				Random::Range(0.0f, _fieldSize)
			);
			e1._Get()->GetTransform()._Get()->SetPosition(newPosition);
		}

		void ControlGame::spawnOneGem()
		{
			auto gemPrefab = PrefabricationRegistry::Get<prefab::GemPrefab>();
			auto g1 = gemPrefab._Get()->MakeObject();
			Vector3 newPosition = Vector3(
				Random::Range(0.0f, _fieldSize),
				0.0f,
				Random::Range(0.0f, _fieldSize)
			);
			g1._Get()->GetTransform()._Get()->SetPosition(newPosition);
		}

	} // namespace sfew::component
} // namespace sfew