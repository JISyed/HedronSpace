// Control Game Component
// Counts the Gems and Enemies and respawns objects
//
// Written by [NAME] ([MONTH]-[DAY]-[YEAR])

// Required Headers
#ifndef SFEW_CUSTOM_COMPONENT__CONTROL_GAME
#define SFEW_CUSTOM_COMPONENT__CONTROL_GAME
#include "CustomComponent.hpp"
#include <memory>

// System Headers


// SFEW Headers
#include "AudioSource.hpp"

namespace sfew
{
	namespace component
	{
		class ControlGame : public CustomComponent
		{
		public:

			// Ctor/Dtor ======================

			ControlGame(std::weak_ptr<GameObject> owningGameObject);
			virtual ~ControlGame();

			// Required Routines ==============

			virtual void Start();		// Runs at contruction of component
			virtual void Update();		// Runs every frame
			virtual void Cleanup();		// Runs at destruction of component

			// Run if there is a collision with an object of a different group
			virtual void OnCollision(PhysicsCollisionGroups otherGroup, 
								 std::weak_ptr<PhysicsEntity> otherEntity);

			// Custom Routines ================

			

			// Properties =====================

			void IncrementGem();
			void DecrementGem();
			void IncrementEnemy();
			void DecrementEnemy();
			void SetFieldSize(float newSize);

		private:

			// Private Routines ========================

			void respawnAllEnemies();
			void respawnAllGems();
			void respawnSomeEnemiesIfGemsCleared();
			void spawnOneEnemy();
			void spawnOneGem();

			// Data ===========================

			int _gemCount;
			int _enemyCount;
			int _spawnedGems;
			int _spawnedEnemies;
			int _maxGems;
			int _maxEnemies;
			float _fieldSize;
			std::weak_ptr<AudioSource> _startSound;
			std::weak_ptr<AudioSource> _levelUpSound;
			std::weak_ptr<AudioSource> _gameMusic;
			
		};	// End of custom component class header

	} // namespace sfew::component
} // namespace sfew

#endif