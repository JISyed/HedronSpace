#include "GameOverScene.hpp"
#include "PrefabricationRegistry.hpp"
#include "Camera.hpp"
#include "GameObjectContainer.hpp"
#include "RendererContainer.hpp"
#include "TimerContainer.hpp"
#include "PhysicsEntityContainer.hpp"
#include "AudioRegistry.hpp"

// System includes not needed in header
#include <iostream>

// SFEW includes not needed in header
#include "Random.hpp"
#include "Camera.hpp"
#include "MaterialRegistry.hpp"

namespace sfew
{
	namespace scene
	{
		// Ctor/Dtor ========================================

		// Constructor
		GameOverScene::GameOverScene()
		{
			
		}

		// Destructor
		GameOverScene::~GameOverScene()
		{
			
		}

		// Routines =========================================

		// Clears current scene and loads
		bool GameOverScene::Load()
		{
			// It is recommended to implement the scene loading in LoadActive()

			// Clear current scene
			PhysicsEntityContainer::RemoveEverything();
			RendererContainer::RemoveEverything();
			TimerContainer::RemoveEverything();
			GameObjectContainer::RemoveEverything();
			AudioRegistry::StopEverything();

			// Load Scene
			bool status = LoadAdditive();

			return status;
		}

		// Loads without clearing current scene
		bool GameOverScene::LoadAdditive()
		{
			// Load the desired GameObjects here

			// Find persistant ScoreKeeper and make un-persistant
			auto scoreKeeper = GameObjectContainer::GetByName("ScoreKeeper");
			if(!scoreKeeper.expired())
			{
				scoreKeeper._Get()->SetPersistance(false);
			}

			// Make a cube GameObject
			auto cube = GameObjectContainer::Create();
			cube._Get()->AddComponent<ObjectRendererComponent>();
			auto renderer = cube._Get()->GetComponent<ObjectRendererComponent>();
			renderer._Get()->GetRenderer()._Get()->SetMaterial(
				MaterialRegistry::GetByName("GameOver")
			);
			
			// Adjust the camera in front of the cube
			auto theCamera = Camera::GetInstance();
			theCamera._Get()->SetPosition(Vector3(0.0f, 0.0f, 1.0f));
			theCamera._Get()->LookAtPoint(Vector3(0.0f, 0.0f, 0.0f));

			// Add the functionality for the Game Over screen
			auto gameOverCtrlr = GameObjectContainer::Create();
			gameOverCtrlr._Get()->AddCustomComponent<component::ManageGameOver>();

			auto scoreEvaluator = GameObjectContainer::Create();
			scoreEvaluator._Get()->AddCustomComponent<component::ScoreEvaluator>();
			auto scoreFontRenderer = scoreEvaluator._Get()->GetComponent<FontRendererComponent>()._Get()->GetRenderer();
			scoreFontRenderer._Get()->SetPosition(190, 487);

			return true;
		}

		// Properties =========================================

		// Helpers =========================================


	} // namespace sfew::scene
} // namespace sfew