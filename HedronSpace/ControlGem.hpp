// Control Gem Component
// Increments and decrements Gem count in ControlGame component
//
// Written by [NAME] ([MONTH]-[DAY]-[YEAR])

// Required Headers
#ifndef SFEW_CUSTOM_COMPONENT__CONTROL_GEM
#define SFEW_CUSTOM_COMPONENT__CONTROL_GEM
#include "CustomComponent.hpp"
#include <memory>

// System Headers


// SFEW Headers
#include "ControlGame.hpp"
#include "AudioSource.hpp"

namespace sfew
{
	namespace component
	{
		class ControlGem : public CustomComponent
		{
		public:

			// Ctor/Dtor ======================

			ControlGem(std::weak_ptr<GameObject> owningGameObject);
			virtual ~ControlGem();

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

			std::weak_ptr<ControlGame> _gameCtrlr;
			std::weak_ptr<AudioSource> _collectSound;
			
		};	// End of custom component class header

	} // namespace sfew::component
} // namespace sfew

#endif