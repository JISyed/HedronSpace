// [EXAMPLE] Component
// [PUT DESCRIPTION OF COMPONENT HERE]
//
// Written by [NAME] ([MONTH]-[DAY]-[YEAR])

// Required Headers
#ifndef SFEW_CUSTOM_COMPONENT__DRAW_HUD
#define SFEW_CUSTOM_COMPONENT__DRAW_HUD
#include "CustomComponent.hpp"
#include <memory>

// System Headers
#include <sstream>

// SFEW Headers
#include "FontRenderer.hpp"
#include "ControlPlayer.hpp"

namespace sfew
{
	namespace component
	{
		class DrawHUD : public CustomComponent
		{
		public:

			// Ctor/Dtor ======================

			DrawHUD(std::weak_ptr<GameObject> owningGameObject);
			virtual ~DrawHUD();

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

			std::weak_ptr<FontRenderer> _fontRendering;
			std::weak_ptr<GameObject> _playerGameObject;
			std::weak_ptr<ControlPlayer> _playerComponent;
			std::stringstream hudOut;	// String stream to output to HUD

		};	// End of custom component class header

	} // namespace sfew::component
} // namespace sfew

#endif