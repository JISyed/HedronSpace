#include "ManageGameOver.hpp"
#include <iostream>
#include "GameObject.hpp"

// System Headers not needed in header
#include <SFML/Window.hpp>

// SFEW Headers not needed in header
#include "Random.hpp"
#include "SceneRegistry.hpp"
#include "AudioRegistry.hpp"

namespace sfew
{
	namespace component
	{
		// Ctor/Dtor ========================================

		// Constructor
		ManageGameOver::ManageGameOver(std::weak_ptr<GameObject> owningGameObject) :
			CustomComponent(owningGameObject)
		{
			Start();
		}

		// Destructor
		ManageGameOver::~ManageGameOver()
		{
			Cleanup();
		}

		// Required Routines =========================================

		// Runs at contruction of component
		void ManageGameOver::Start()
		{
			_gameOverSnd = AudioRegistry::GetByName("GameOverSnd");
			_gameOverSnd._Get()->Play();
		}

		// Runs every frame
		void ManageGameOver::Update()
		{
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				SceneRegistry::LoadScene<scene::StartScene>();
			}
		}

		// Runs at destruction of component
		void ManageGameOver::Cleanup()
		{

		}

		// Run if there is a collision with an object of a different group
		void ManageGameOver::OnCollision(PhysicsCollisionGroups otherGroup, 
										 std::weak_ptr<PhysicsEntity> otherEntity)
		{
			
		}

		// Custom Routines =========================================

		// Properties =========================================

		// Private Routines =========================================

	} // namespace sfew::component
} // namespace sfew