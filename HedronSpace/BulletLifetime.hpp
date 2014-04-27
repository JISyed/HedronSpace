// Bullet Lifetime Component
// Handles the life time of a bullet
//
// Written by [NAME] ([MONTH]-[DAY]-[YEAR])

// Required Headers
#ifndef SFEW_CUSTOM_COMPONENT__BULLET_LIFETIME
#define SFEW_CUSTOM_COMPONENT__BULLET_LIFETIME
#include "CustomComponent.hpp"
#include <memory>

// System Headers


// SFEW Headers
#include "Timer.hpp"

namespace sfew
{
	namespace component
	{
		class BulletLifetime : public CustomComponent
		{
		public:

			// Ctor/Dtor ======================

			BulletLifetime(std::weak_ptr<GameObject> owningGameObject);
			virtual ~BulletLifetime();

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

			std::weak_ptr<Timer> _lifeTimer;
			float _lifeTime;	// In seconds
			
		};	// End of custom component class header

	} // namespace sfew::component
} // namespace sfew

#endif