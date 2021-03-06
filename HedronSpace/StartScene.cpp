#include "StartScene.hpp"
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
#include "MaterialRegistry.hpp"
#include "Camera.hpp"

namespace sfew
{
	namespace scene
	{
		// Ctor/Dtor ========================================

		// Constructor
		StartScene::StartScene()
		{
			
		}

		// Destructor
		StartScene::~StartScene()
		{
			
		}

		// Routines =========================================

		// Clears current scene and loads
		bool StartScene::Load()
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
		bool StartScene::LoadAdditive()
		{
			// Load the desired GameObjects here

			// Make a cube GameObject
			auto cube = GameObjectContainer::Create();
			cube._Get()->AddComponent<ObjectRendererComponent>();
			auto renderer = cube._Get()->GetComponent<ObjectRendererComponent>();
			renderer._Get()->GetRenderer()._Get()->SetMaterial(
				MaterialRegistry::GetByName("StartScreen")
			);
			
			// Adjust the camera in front of the cube
			auto theCamera = Camera::GetInstance();
			theCamera._Get()->SetPosition(Vector3(0.0f, 0.0f, 1.0f));
			theCamera._Get()->LookAtPoint(Vector3(0.0f, 0.0f, 0.0f));

			// Add the functionality for the Game Over screen
			auto startScreenCtrlr = GameObjectContainer::Create();
			startScreenCtrlr._Get()->AddCustomComponent<component::ManageStartScreen>();

			return true;
		}

		// Properties =========================================

		// Helpers =========================================


	} // namespace sfew::scene
} // namespace sfew