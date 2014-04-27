// Control Camera Component
// Makes the camera follow behind the player if exists
//
// Written by [NAME] ([MONTH]-[DAY]-[YEAR])

// Required Headers
#ifndef SFEW_CUSTOM_COMPONENT__CONTROL_CAMERA
#define SFEW_CUSTOM_COMPONENT__CONTROL_CAMERA
#include "CustomComponent.hpp"
#include <memory>

// System Headers


// SFEW Headers
#include "Camera.hpp"

namespace sfew
{
	namespace component
	{
		class ControlCamera : public CustomComponent
		{
		public:

			// Ctor/Dtor ======================

			ControlCamera(std::weak_ptr<GameObject> owningGameObject);
			virtual ~ControlCamera();

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

			void retrievePlayer();

			// Data ===========================

			std::weak_ptr<GameObject> _playerGameObject;
			std::weak_ptr<Transform> _playerTransform;
			std::weak_ptr<Camera> _camera;
			float _distanceBehind;			// Distance behind player
			float _height;					// Height in the scene
			
		};	// End of custom component class header

	} // namespace sfew::component
} // namespace sfew

#endif