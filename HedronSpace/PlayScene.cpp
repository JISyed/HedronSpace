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
			float camStart = 1.4f;
			theCamera._Get()->SetPosition(
				sfew::Vector3(camStart, camStart, camStart)
			);
			theCamera._Get()->LookAtPoint(sfew::Vector3(0.0f, 0.0f, 0.0f));

			// Example cube
			auto cubePrefab = PrefabricationRegistry::Get<prefab::CubePrefab>();
			cubePrefab._Get()->MakeObject();

			return true;
		}

		// Properties =========================================

		// Helpers =========================================


	} // namespace sfew::scene
} // namespace sfew