#include "PlayerLaserPrefab.hpp"
#include "GameObjectContainer.hpp"
#include "MaterialRegistry.hpp"
#include "MeshRegistry.hpp"
#include "AudioRegistry.hpp"
#include "FontRegistry.hpp"
#include "SceneRegistry.hpp"
#include "PrefabricationRegistry.hpp"
#include "ShaderRegistry.hpp"
#include "TextureRegistry.hpp"

// System Includes not needed in header


// SFEW Includes not needed in header
#include "Random.hpp"


namespace sfew
{
	namespace prefab
	{
		// Ctor/Dtor ========================================

		// Constructor
		PlayerLaserPrefab::PlayerLaserPrefab()
		{
			
		}

		// Destructor
		PlayerLaserPrefab::~PlayerLaserPrefab()
		{
			
		}

		// Routines =========================================

		std::weak_ptr<GameObject> PlayerLaserPrefab::MakeObject()
		{
			// Create GameObject and name it
			std::weak_ptr<GameObject> go = GameObjectContainer::Create();
			go._Get()->SetName("PlayerLaser");

			// Setup other properties here
			
			// Add components
			go._Get()->AddComponent<ObjectRendererComponent>();
			go._Get()->AddComponent<PhysicsComponent>();

			// Setup renderer
			auto renderer = go._Get()->GetComponent<ObjectRendererComponent>()._Get()->GetRenderer();
			renderer._Get()->SetMesh(MeshRegistry::GetByName("CubeMesh"));
			renderer._Get()->SetMaterial(MaterialRegistry::GetByName("PlayerLaser"));

			// Setup physics
			auto physics = go._Get()->GetComponent<PhysicsComponent>()._Get()->GetPhysicsEntity();
			physics._Get()->SetRotationalVelocity(Vector3(0.0f, 50.0f, 0.0f));

			// Setup transform
			auto transform = go._Get()->GetTransform();
			transform._Get()->SetPosition(Vector3(-1.0f, 0.0f, 0.2f));
			transform._Get()->SetScale(Vector3(0.2f, 0.2f, 0.2f));

			// Return weak pointer
			return go;
		}

		// Properties =========================================

		// Helpers =========================================


	} // namespace sfew::prefab
} // namespace sfew