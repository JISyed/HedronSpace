#include "ControlGem.hpp"
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
		ControlGem::ControlGem(std::weak_ptr<GameObject> owningGameObject) :
			CustomComponent(owningGameObject)
		{
			Start();
		}

		// Destructor
		ControlGem::~ControlGem()
		{
			Cleanup();
		}

		// Required Routines =========================================

		// Runs at contruction of component
		void ControlGem::Start()
		{
			// Find game controller
			auto gameCtrlrObj = GameObjectContainer::GetByName("GameCtrlr");
			if(!gameCtrlrObj.expired())
			{
				_gameCtrlr = gameCtrlrObj._Get()->GetCustomComponent<ControlGame>();

				// Increment Gem count
				_gameCtrlr._Get()->IncrementGem();
			}
		}

		// Runs every frame
		void ControlGem::Update()
		{
			
		}

		// Runs at destruction of component
		void ControlGem::Cleanup()
		{
			// Decrement Gem count
			if(!_gameCtrlr.expired())
			{
				_gameCtrlr._Get()->DecrementGem();
			}
		}

		// Run if there is a collision with an object of a different group
		void ControlGem::OnCollision(PhysicsCollisionGroups otherGroup, 
										 std::weak_ptr<PhysicsEntity> otherEntity)
		{
			// Check if collision is with the player
			if(otherGroup == PhysicsCollisionGroups::GroupA)
			{
				// Delete self no matter what
				this->GetGameObject()._Get()->Destroy();

				// Add the gem to the score keeper
				auto scoreKeeperObj = GameObjectContainer::GetByName("ScoreKeeper");
				auto scoreKeeper = scoreKeeperObj._Get()->GetCustomComponent<component::ScoreKeeper>();
				scoreKeeper._Get()->AddGems(1);
				scoreKeeper._Get()->AddScore(12);
			}
		}

		// Custom Routines =========================================

		// Properties =========================================

		// Private Routines =========================================

	} // namespace sfew::component
} // namespace sfew