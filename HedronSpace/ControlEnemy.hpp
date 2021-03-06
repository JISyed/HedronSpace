// [EXAMPLE] Component
// [PUT DESCRIPTION OF COMPONENT HERE]
//
// Written by [NAME] ([MONTH]-[DAY]-[YEAR])

// Required Headers
#ifndef SFEW_CUSTOM_COMPONENT__CONTROL_ENEMY
#define SFEW_CUSTOM_COMPONENT__CONTROL_ENEMY
#include "CustomComponent.hpp"
#include <memory>

// System Headers


// SFEW Headers
#include "Timer.hpp"
#include "Prefabrication.hpp"
#include "ControlGame.hpp"
#include "AudioSource.hpp"

namespace sfew
{
	namespace component
	{
		class ControlEnemy : public CustomComponent
		{
		public:

			// Ctor/Dtor ======================

			ControlEnemy(std::weak_ptr<GameObject> owningGameObject);
			virtual ~ControlEnemy();

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

			std::weak_ptr<Timer> _shootTimer;
			float _shootInterval;		// In seconds
			std::weak_ptr<ControlGame> _gameCtrlr;
			int _health;
			std::weak_ptr<AudioSource> _laserSnd;
			std::weak_ptr<AudioSource> _deathSnd;
			std::weak_ptr<AudioSource> _hitSnd;

		};	// End of custom component class header

	} // namespace sfew::component
} // namespace sfew

#endif