#include "ControlGame.hpp"
#include <iostream>
#include "GameObject.hpp"

// System Headers not needed in header


// SFEW Headers not needed in header
#include "Random.hpp"

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
			_gemCount = 0;
			_enemyCount = 0;
		}

		// Runs every frame
		void ControlGame::Update()
		{
			
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


		// Private Routines =========================================

	} // namespace sfew::component
} // namespace sfew