#include "GemPrefab.hpp"
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
		GemPrefab::GemPrefab()
		{
			
		}

		// Destructor
		GemPrefab::~GemPrefab()
		{
			
		}

		// Routines =========================================

		std::weak_ptr<GameObject> GemPrefab::MakeObject()
		{
			// Create GameObject and name it
			std::weak_ptr<GameObject> go = GameObjectContainer::Create();
			go._Get()->SetName("Gem");

			// Setup other properties here
			

			// Return weak pointer
			return go;
		}

		// Properties =========================================

		// Helpers =========================================


	} // namespace sfew::prefab
} // namespace sfew