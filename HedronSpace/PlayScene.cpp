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

			// Setup the camera
			auto theCamera = Camera::GetInstance();
			float camStart = 6.4f;
			theCamera._Get()->SetPosition(
				sfew::Vector3(camStart, camStart, camStart)
			);
			theCamera._Get()->LookAtPoint(sfew::Vector3(0.0f, 0.0f, 0.0f));

			// Create the Player
			auto playerPrefab = PrefabricationRegistry::Get<prefab::PlayerPrefab>();
			auto playerObj = playerPrefab._Get()->MakeObject();
			playerObj._Get()->GetTransform()._Get()->Rotate(Vector3(0.0f, 34.0f, 0.0f));

			// Create test objects
			auto gemPrefab = PrefabricationRegistry::Get<prefab::GemPrefab>();
			gemPrefab._Get()->MakeObject();

			auto enemyPrefab = PrefabricationRegistry::Get<prefab::EnemyPrefab>();
			enemyPrefab._Get()->MakeObject();

			auto playerLaserPrefab = PrefabricationRegistry::Get<prefab::PlayerLaserPrefab>();
			playerLaserPrefab._Get()->MakeObject();

			auto enemyLaserPrefab = PrefabricationRegistry::Get<prefab::EnemyLaserPrefab>();
			enemyLaserPrefab._Get()->MakeObject();

			// Create the object that controls the camera (Player must exist!)
			auto cameraCtrlr = GameObjectContainer::Create();
			cameraCtrlr._Get()->SetName("CameraCtrlr");
			cameraCtrlr._Get()->AddCustomComponent<component::ControlCamera>();

			// Create a grid of tiny cubes for depth perception
			createCubeGrid(50);

			return true;
		}

		// Properties =========================================

		// Helpers =========================================

		void PlayScene::createCubeGrid(int gridSize)
		{
			auto gridCubePrefab = PrefabricationRegistry::Get<prefab::GridCubePrefab>();
			auto prefabPointer = gridCubePrefab._Get();

			int gridHeight = gridSize;
			int gridWidth = gridSize;

			for (int i = 0; i < gridWidth; i+=4)
			{
				for (int j = 0; j < gridHeight; j+=4)
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