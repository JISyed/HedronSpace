#include "EnemyPrefab.hpp"
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
		EnemyPrefab::EnemyPrefab()
		{
			
		}

		// Destructor
		EnemyPrefab::~EnemyPrefab()
		{
			
		}

		// Routines =========================================

		std::weak_ptr<GameObject> EnemyPrefab::MakeObject()
		{
			// Create GameObject and name it
			std::weak_ptr<GameObject> go = GameObjectContainer::Create();
			go._Get()->SetName("Enemy");

			// Setup other properties here
			
			// Add components
			go._Get()->AddComponent<ObjectRendererComponent>();
			go._Get()->AddComponent<PhysicsComponent>();

			// Setup renderer
			auto renderer = go._Get()->GetComponent<ObjectRendererComponent>()._Get()->GetRenderer();
			renderer._Get()->SetMesh(MeshRegistry::GetByName("PrismMesh"));
			renderer._Get()->SetMaterial(MaterialRegistry::GetByName("Enemy"));

			// Setup physics
			auto physics = go._Get()->GetComponent<PhysicsComponent>()._Get()->GetPhysicsEntity();
			physics._Get()->SetCollisionGroup(PhysicsCollisionGroups::GroupC);
			physics._Get()->SetRotationalVelocity(Vector3(0.0f, 600.0f, 0.0f));
			physics._Get()->SetRadius(0.5f);	// 1.0 (scale) X 0.5 (mesh width)

			// Setup transform
			auto transform = go._Get()->GetTransform();
			transform._Get()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));

			// Add enemy controling component
			go._Get()->AddCustomComponent<component::ControlEnemy>();

			// Return weak pointer
			return go;
		}

		// Properties =========================================

		// Helpers =========================================


	} // namespace sfew::prefab
} // namespace sfew