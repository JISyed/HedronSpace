#include "PlayerPrefab.hpp"
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
		PlayerPrefab::PlayerPrefab()
		{
			
		}

		// Destructor
		PlayerPrefab::~PlayerPrefab()
		{
			
		}

		// Routines =========================================

		std::weak_ptr<GameObject> PlayerPrefab::MakeObject()
		{
			// Create GameObject and name it
			std::weak_ptr<GameObject> go = GameObjectContainer::Create();
			go._Get()->SetName("Player");

			// Setup other properties here

			// Add components
			go._Get()->AddComponent<ObjectRendererComponent>();
			go._Get()->AddComponent<PhysicsComponent>();
			go._Get()->AddCustomComponent<component::ControlPlayer>();

			// Setup renderer
			auto renderer = go._Get()->GetComponent<ObjectRendererComponent>()._Get()->GetRenderer();
			renderer._Get()->SetMesh(MeshRegistry::GetByName("TetrahedronMesh"));
			renderer._Get()->SetMaterial(MaterialRegistry::GetByName("Player"));

			// Setup physics
			auto physics = go._Get()->GetComponent<PhysicsComponent>()._Get()->GetPhysicsEntity();
			physics._Get()->SetCollisionGroup(PhysicsCollisionGroups::GroupA);
			physics._Get()->SetLinearDrag(1.0f);
			physics._Get()->SetAngularDrag(2.0f);
			physics._Get()->SetRadius(0.5f);	// 1.0 (scale) X 0.5 (mesh width)
			//physics._Get()->SetRotationalVelocity(Vector3(0.0f, 50.0f, 0.0f));

			// Setup transform
			auto transform = go._Get()->GetTransform();
			transform._Get()->SetPosition(Vector3(-1.0f, 0.0f, -1.0f));

			// Return weak pointer
			return go;
		}

		// Properties =========================================

		// Helpers =========================================


	} // namespace sfew::prefab
} // namespace sfew