#include "ScoreKeeper.hpp"
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
		ScoreKeeper::ScoreKeeper(std::weak_ptr<GameObject> owningGameObject) :
			CustomComponent(owningGameObject)
		{
			Start();
		}

		// Destructor
		ScoreKeeper::~ScoreKeeper()
		{
			Cleanup();
		}

		// Required Routines =========================================

		// Runs at contruction of component
		void ScoreKeeper::Start()
		{
			_score = 0;
			_gems = 0;
		}

		// Runs every frame
		void ScoreKeeper::Update()
		{
			
		}

		// Runs at destruction of component
		void ScoreKeeper::Cleanup()
		{

		}

		// Run if there is a collision with an object of a different group
		void ScoreKeeper::OnCollision(PhysicsCollisionGroups otherGroup, 
										 std::weak_ptr<PhysicsEntity> otherEntity)
		{
			
		}

		// Custom Routines =========================================

		// Properties =========================================
		
		int ScoreKeeper::GetScore() const
		{
			return _score;
		}

		int ScoreKeeper::GetGemsCollected() const
		{
			return _gems;
		}

		void ScoreKeeper::AddGems(int additionalGems)
		{
			_gems += additionalGems;
		}

		void ScoreKeeper::AddScore(int additionalScore)
		{
			_score += additionalScore;
		}


		// Private Routines =========================================

	} // namespace sfew::component
} // namespace sfew