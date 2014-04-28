#include "DrawHUD.hpp"
#include <iostream>
#include "GameObject.hpp"

// System Headers not needed in header


// SFEW Headers not needed in header
#include "Random.hpp"
#include "FontRendererComponent.hpp"
#include "GameObjectContainer.hpp"

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
			// Get the player data
			retrievePlayer();

			// Retrieve the score keeper
			auto scoreKeeperObj = GameObjectContainer::GetByName("ScoreKeeper");
			_scoreKeeper = scoreKeeperObj._Get()->GetCustomComponent<component::ScoreKeeper>();

			// Get the font renderer
			_fontRendering = GetGameObject()._Get()->GetComponent<FontRendererComponent>()._Get()->GetRenderer();
		}

		// Runs every frame
		void DrawHUD::Update()
		{
			// Get latest HUD data
			int healthData = 0;
			if(!_playerComponent.expired())
			{
				healthData = _playerComponent._Get()->GetHealth();
			}
			int scoreData = _scoreKeeper._Get()->GetScore();
			int gemData = _scoreKeeper._Get()->GetGemsCollected();

			// Get current FPS and update font renderer string
			hudOut.str(std::string());
			hudOut << "Health: " << healthData << std::endl 
				<< "Score: " << scoreData << std::endl
				<< "Gems: " << gemData << std::endl;
			_fontRendering._Get()->SetTextString(hudOut.str());
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

		// Get player and it's transform as weak pointers
		void DrawHUD::retrievePlayer()
		{
			_playerGameObject = GameObjectContainer::GetByName("Player");
			if(!_playerGameObject.expired())
			{
				_playerComponent = _playerGameObject._Get()->GetCustomComponent<component::ControlPlayer>();
			}
		}

	} // namespace sfew::component
} // namespace sfew