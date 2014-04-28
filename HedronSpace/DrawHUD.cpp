#include "DrawHUD.hpp"
#include <iostream>
#include "GameObject.hpp"

// System Headers not needed in header


// SFEW Headers not needed in header
#include "Random.hpp"
#include "FontRendererComponent.hpp"

namespace sfew
{
	namespace component
	{
		// Ctor/Dtor ========================================

		// Constructor
		DrawHUD::DrawHUD(std::weak_ptr<GameObject> owningGameObject) :
			CustomComponent(owningGameObject)
		{
			Start();
		}

		// Destructor
		DrawHUD::~DrawHUD()
		{
			Cleanup();
		}

		// Required Routines =========================================

		// Runs at contruction of component
		void DrawHUD::Start()
		{
			// Get the font renderer
			_fontRendering = GetGameObject()._Get()->GetComponent<FontRendererComponent>()._Get()->GetRenderer();
		}

		// Runs every frame
		void DrawHUD::Update()
		{
			
		}

		// Runs at destruction of component
		void DrawHUD::Cleanup()
		{

		}

		// Run if there is a collision with an object of a different group
		void DrawHUD::OnCollision(PhysicsCollisionGroups otherGroup, 
										 std::weak_ptr<PhysicsEntity> otherEntity)
		{
			
		}

		// Custom Routines =========================================

		// Properties =========================================

		// Private Routines =========================================

	} // namespace sfew::component
} // namespace sfew