#include "PlayScene.hpp"
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

namespace sfew
{
	namespace scene
	{
		// Ctor/Dtor ========================================

		// Constructor
		PlayScene::PlayScene()
		{
			
		}

		// Destructor
		PlayScene::~PlayScene()
		{
			
		}

		// Routines =========================================

		// Clears current scene and loads
		bool PlayScene::Load()
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
		bool PlayScene::LoadAdditive()
		{
			// Load the desired GameObjects here

			// Determine the field size
			float fieldSize = 70.0f;
			int fieldSpacing  = 8;

			// Make persistant score keeper (must be set un-persistant at Game Over)
			auto scoreKeeper = GameObjectContainer::Create();
			scoreKeeper._Get()->SetName("ScoreKeeper");
			scoreKeeper._Get()->SetPersistance(true);
			scoreKeeper._Get()->AddCustomComponent<component::ScoreKeeper>();

			// Create the Game Controller (Nessesary for game logic!)
			auto gameCtrlr = GameObjectContainer::Create();
			gameCtrlr._Get()->SetName("GameCtrlr");
			gameCtrlr._Get()->AddCustomComponent<component::ControlGame>();
			auto gameCtrlrCmpt = gameCtrlr._Get()->GetCustomComponent<component::ControlGame>();
			gameCtrlrCmpt._Get()->SetFieldSize(fieldSize);

			// Create the Player
			auto playerPrefab = PrefabricationRegistry::Get<prefab::PlayerPrefab>();
			auto playerObj = playerPrefab._Get()->MakeObject();
			playerObj._Get()->GetTransform()._Get()->Rotate(Vector3(0.0f, 45.0f, 0.0f));

			// Create Gems
			Vector3 newPosition;
			newPosition = Vector3(Random::Range(0.0f, fieldSize), 0.0f, Random::Range(0.0f, fieldSize));
			
			auto gemPrefab = PrefabricationRegistry::Get<prefab::GemPrefab>();
			auto g1 = gemPrefab._Get()->MakeObject();
			g1._Get()->GetTransform()._Get()->SetPosition(newPosition);
			newPosition = Vector3(Random::Range(0.0f, fieldSize), 0.0f, Random::Range(0.0f, fieldSize));
			auto g2 = gemPrefab._Get()->MakeObject();
			g2._Get()->GetTransform()._Get()->SetPosition(newPosition);
			newPosition = Vector3(Random::Range(0.0f, fieldSize), 0.0f, Random::Range(0.0f, fieldSize));
			auto g3 = gemPrefab._Get()->MakeObject();
			g3._Get()->GetTransform()._Get()->SetPosition(newPosition);

			// Create Enemies
			newPosition = Vector3(Random::Range(0.0f, fieldSize), 0.0f, Random::Range(0.0f, fieldSize));
			auto enemyPrefab = PrefabricationRegistry::Get<prefab::EnemyPrefab>();
			auto e1 = enemyPrefab._Get()->MakeObject();
			e1._Get()->GetTransform()._Get()->SetPosition(newPosition);
			newPosition = Vector3(Random::Range(0.0f, fieldSize), 0.0f, Random::Range(0.0f, fieldSize));
			auto e2 = enemyPrefab._Get()->MakeObject();
			e2._Get()->GetTransform()._Get()->SetPosition(newPosition);
			newPosition = Vector3(Random::Range(0.0f, fieldSize), 0.0f, Random::Range(0.0f, fieldSize));
			auto e3 = enemyPrefab._Get()->MakeObject();
			e3._Get()->GetTransform()._Get()->SetPosition(newPosition);

			// Create the object that controls the camera (Player must exist!)
			auto cameraCtrlr = GameObjectContainer::Create();
			cameraCtrlr._Get()->SetName("CameraCtrlr");
			cameraCtrlr._Get()->AddCustomComponent<component::ControlCamera>();

			// Make HUD (Player must exist!)
			auto hudObject = GameObjectContainer::Create();
			hudObject._Get()->SetName("HUD");
			hudObject._Get()->AddComponent<FontRendererComponent>();
			hudObject._Get()->AddCustomComponent<component::DrawHUD>();
			auto hudRenderer = hudObject._Get()->GetComponent<FontRendererComponent>()._Get()->GetRenderer();
			hudRenderer._Get()->SetPosition(10, 10);
			hudRenderer._Get()->SetColor(1.0f, 0.5f, 0.2f, 1.0f);	// Orange

			// Create a grid of tiny cubes for depth perception
			createCubeGrid((int) fieldSize, fieldSpacing);

			return true;
		}

		// Properties =========================================

		// Helpers =========================================

		void PlayScene::createCubeGrid(int gridSize, int spacing)
		{
			auto gridCubePrefab = PrefabricationRegistry::Get<prefab::GridCubePrefab>();
			auto prefabPointer = gridCubePrefab._Get();

			int gridHeight = gridSize;
			int gridWidth = gridSize;
			int gridUnit = spacing;

			for (int i = 0; i < gridWidth; i+=gridUnit)
			{
				for (int j = 0; j < gridHeight; j+=gridUnit)
				{
					auto go = prefabPointer->MakeObject();
					go._Get()->GetTransform()._Get()->SetPosition(
						Vector3((float) i, 0, (float) j)
					);
				}
			}
		}

	} // namespace sfew::scene
} // namespace sfew