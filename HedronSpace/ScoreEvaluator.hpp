// Score Evaluator Component
// Prints the final score amount and final gem amount on Game Over
//
// Written by [NAME] ([MONTH]-[DAY]-[YEAR])

// Required Headers
#ifndef SFEW_CUSTOM_COMPONENT__SCORE_EVALUATOR
#define SFEW_CUSTOM_COMPONENT__SCORE_EVALUATOR
#include "CustomComponent.hpp"
#include <memory>

// System Headers
#include <sstream>

// SFEW Headers
#include "FontRenderer.hpp"

namespace sfew
{
	namespace component
	{
		class ScoreEvaluator : public CustomComponent
		{
		public:

			// Ctor/Dtor ======================

			ScoreEvaluator(std::weak_ptr<GameObject> owningGameObject);
			virtual ~ScoreEvaluator();

			// Required Routines ==============

			virtual void Start();		// Runs at contruction of component
			virtual void Update();		// Runs every frame
			virtual void Cleanup();		// Runs at destruction of component

			// Run if there is a collision with an object of a different group
			virtual void OnCollision(PhysicsCollisionGroups otherGroup, 
								 std::weak_ptr<PhysicsEntity> otherEntity);

			// Custom Routines ================



			// Properties =====================

			

		private:

			// Private Routines ========================

			

			// Data ===========================

			std::weak_ptr<FontRenderer> _fontRenderer;
			std::stringstream hudOut;	// String stream to output to HUD
			
		};	// End of custom component class header

	} // namespace sfew::component
} // namespace sfew

#endif