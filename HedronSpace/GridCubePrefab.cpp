#include "GridCubePrefab.hpp"
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
		GridCubePrefab::GridCubePrefab()
		{
			
		}

		// Destructor
		GridCubePrefab::~GridCubePrefab()
		{
			
		}

		// Routines =========================================

		std::weak_ptr<GameObject> GridCubePrefab::MakeObject()
		{
			// Create GameObject and name it
			std::weak_ptr<GameObject> go = GameObjectContainer::Create();
			go._Get()->SetName("GridCube");

			// Setup other properties here

			// Add components
			go._Get()->AddComponent<ObjectRendererComponent>();

			// Setup renderer
			auto renderer = go._Get()->GetComponent<ObjectRendererComponent>()._Get()->GetRenderer();
			renderer._Get()->SetMesh(MeshRegistry::GetByName("CubeMesh"));
			renderer._Get()->SetMaterial(MaterialRegistry::GetByName("CubeGrid"));

			// Setup transform
			auto transform = go._Get()->GetTransform();
			transform._Get()->SetPosition(Vector3(0.0f, 0.0f, 0.0f));
			transform._Get()->SetScale(Vector3(0.02f, 0.02f, 0.02f));

			// Return weak pointer
			return go;
		}

		// Properties =========================================

		// Helpers =========================================


	} // namespace sfew::prefab
} // namespace sfew