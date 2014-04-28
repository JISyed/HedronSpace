// ControlPlayer Component
// Used to control the player
//
// Written by [NAME] ([MONTH]-[DAY]-[YEAR])

// Required Headers
#ifndef SFEW_CUSTOM_COMPONENT__CONTROL_PLAYER
#define SFEW_CUSTOM_COMPONENT__CONTROL_PLAYER
#include "CustomComponent.hpp"
#include <memory>

// System Headers


// SFEW Headers
#include "PhysicsEntity.hpp"

namespace sfew
{
	namespace component
	{
		class ControlPlayer : public CustomComponent
		{
		public:

			// Ctor/Dtor ======================

			ControlPlayer(std::weak_ptr<GameObject> owningGameObject);
			virtual ~ControlPlayer();

			// Required Routines ==============

			virtual void Start();		// Runs at contruction of component
			virtual void Update();		// Runs every frame
			virtual void Cleanup();		// Runs at destruction of component

			// Run if there is a collision with an object of a different group
			virtual void OnCollision(PhysicsCollisionGroups otherGroup, 
								 std::weak_ptr<PhysicsEntity> otherEntity);

			// Custom Routines ================



			// Properties =====================

			int GetHealth() const;

		private:

			// Private Routines ========================

			

			// Data ===========================

			std::weak_ptr<PhysicsEntity> _physics;	// Physics properties
			std::weak_ptr<Transform> _transform;	// Player's transform
			float _thrustStrength;					// Linear acceleration
			float _turnStrength;					// Angular acceleration
			bool _spacePressedLastFrame;			// Was Space pressed last frame
			int _health;							// Player's health

		};	// End of custom component class header

	} // namespace sfew::component
} // namespace sfew

#endif