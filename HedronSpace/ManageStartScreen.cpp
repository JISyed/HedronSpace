#include "ManageStartScreen.hpp"
#include <iostream>
#include "GameObject.hpp"

// System Headers not needed in header
#include <SFML/Window.hpp>

// SFEW Headers not needed in header
#include "Random.hpp"
#include "SceneRegistry.hpp"

namespace sfew
{
	namespace component
	{
		// Ctor/Dtor ========================================

		// Constructor
		ManageStartScreen::ManageStartScreen(std::weak_ptr<GameObject> owningGameObject) :
			CustomComponent(owningGameObject)
		{
			Start();
		}

		// Destructor
		ManageStartScreen::~ManageStartScreen()
		{
			Cleanup();
		}

		// Required Routines =========================================

		// Runs at contruction of component
		void ManageStartScreen::Start()
		{
			
		}

		// Runs every frame
		void ManageStartScreen::Update()
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				SceneRegistry::LoadScene<scene::PlayScene>();
			}
		}

		// Runs at destruction of component
		void ManageStartScreen::Cleanup()
		{

		}

		// Run if there is a collision with an object of a different group
		void ManageStartScreen::OnCollision(PhysicsCollisionGroups otherGroup, 
										 std::weak_ptr<PhysicsEntity> otherEntity)
		{
			
		}

		// Custom Routines =========================================

		// Properties =========================================

		// Private Routines =========================================

	} // namespace sfew::component
} // namespace sfew