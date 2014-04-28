// [EXAMPLE] Component
// [PUT DESCRIPTION OF COMPONENT HERE]
//
// Written by [NAME] ([MONTH]-[DAY]-[YEAR])

// Required Headers
#ifndef SFEW_CUSTOM_COMPONENT__SCORE_KEEPER
#define SFEW_CUSTOM_COMPONENT__SCORE_KEEPER
#include "CustomComponent.hpp"
#include <memory>

// System Headers


// SFEW Headers


namespace sfew
{
	namespace component
	{
		class ScoreKeeper : public CustomComponent
		{
		public:

			// Ctor/Dtor ======================

			ScoreKeeper(std::weak_ptr<GameObject> owningGameObject);
			virtual ~ScoreKeeper();

			// Required Routines ==============

			virtual void Start();		// Runs at contruction of component
			virtual void Update();		// Runs every frame
			virtual void Cleanup();		// Runs at destruction of component

			// Run if there is a collision with an object of a different group
			virtual void OnCollision(PhysicsCollisionGroups otherGroup, 
								 std::weak_ptr<PhysicsEntity> otherEntity);

			// Custom Routines ================



			// Properties =====================

			int GetScore() const;
			int GetGemsCollected() const;
			void AddGems(int additionalGems);
			void AddScore(int additionalScore);

		private:

			// Private Routines ========================

			

			// Data ===========================

			int _score;
			int _gems;
			
		};	// End of custom component class header

	} // namespace sfew::component
} // namespace sfew

#endif