#include "ScoreEvaluator.hpp"
#include <iostream>
#include "GameObject.hpp"

// System Headers not needed in header


// SFEW Headers not needed in header
#include "Random.hpp"
#include "ScoreKeeper.hpp"
#include "GameObjectContainer.hpp"

namespace sfew
{
	namespace component
	{
		// Ctor/Dtor ========================================

		// Constructor
		ScoreEvaluator::ScoreEvaluator(std::weak_ptr<GameObject> owningGameObject) :
			CustomComponent(owningGameObject)
		{
			Start();
		}

		// Destructor
		ScoreEvaluator::~ScoreEvaluator()
		{
			Cleanup();
		}

		// Required Routines =========================================

		// Runs at contruction of component
		void ScoreEvaluator::Start()
		{
			// Add a font renderer
			GetGameObject()._Get()->AddComponent<FontRendererComponent>();
			_fontRenderer = GetGameObject()._Get()->GetComponent<FontRendererComponent>()._Get()->GetRenderer();
			
			// Get the ScoreKeeper
			auto scoreKeeperObj = GameObjectContainer::GetByName("ScoreKeeper");
			auto scoreKeeper = scoreKeeperObj._Get()->GetCustomComponent<component::ScoreKeeper>();
			int finalScore = scoreKeeper._Get()->GetScore();
			int finalGems = scoreKeeper._Get()->GetGemsCollected();

			// Write final results
			hudOut.str(std::string());
			hudOut << "Score: " << finalScore << std::endl
				<< "Gems: " << finalGems;
			_fontRenderer._Get()->SetTextString(hudOut.str());
		}

		// Runs every frame
		void ScoreEvaluator::Update()
		{
			
		}

		// Runs at destruction of component
		void ScoreEvaluator::Cleanup()
		{

		}

		// Run if there is a collision with an object of a different group
		void ScoreEvaluator::OnCollision(PhysicsCollisionGroups otherGroup, 
										 std::weak_ptr<PhysicsEntity> otherEntity)
		{
			
		}

		// Custom Routines =========================================

		// Properties =========================================

		// Private Routines =========================================

	} // namespace sfew::component
} // namespace sfew