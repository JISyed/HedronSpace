#include "MaterialRegistry.hpp"

#include <iostream>
#include <SFML/System.hpp>

#include "ShaderRegistry.hpp"
#include "TextureRegistry.hpp"

namespace sfew
{
	// Static data ========================================

	MaterialRegistry* MaterialRegistry::_instance = NULL;

	// Ctor/Dtor ========================================

	// Ctor
	MaterialRegistry::MaterialRegistry()
	{
		if(MaterialRegistry::_instance != NULL)
		{
			std::cout << "ERROR: MaterialRegistry being instantiated more than once!\n";
			std::cout << "Aborting in 11 seconds...";

			sf::sleep(sf::seconds(11.0f));

			exit(1);
		}

		// Assign the internal singleton
		MaterialRegistry::_instance = this;
	}

	// Dtor
	MaterialRegistry::~MaterialRegistry()
	{
		// Clear the internal singleton
		MaterialRegistry::_instance = NULL;
	}

	// Routines =========================================

	// Load all the resources
	bool MaterialRegistry::Load()
	{
		// Load a blank texture
		std::shared_ptr<Material> blankMaterial(new Material(ShaderRegistry::GetByName("BasicShader"),
															 TextureRegistry::GetByName("Blank")));
		blankMaterial->SetName("Blank");
		_resourceList.push_front(blankMaterial);

		// Load a cubeGrid texture
		std::shared_ptr<Material> cubeGridMaterial(new Material(ShaderRegistry::GetByName("BasicShader"),
															 TextureRegistry::GetByName("Blank")));
		cubeGridMaterial->SetName("CubeGrid");
		_resourceList.push_front(cubeGridMaterial);
		cubeGridMaterial->SetColor(Vector4(0.0f, 0.9f, 1.0f, 1.0f));

		// Load Game Over Material
		std::shared_ptr<Material> gameOverMaterial(new Material(ShaderRegistry::GetByName("BasicShader"),
																TextureRegistry::GetByName("GameOver")));
		gameOverMaterial->SetName("GameOver");
		_resourceList.push_front(gameOverMaterial);

		// Load Start Screen Material
		std::shared_ptr<Material> startScreenMaterial(new Material(ShaderRegistry::GetByName("BasicShader"),
																   TextureRegistry::GetByName("StartScreen")));
		startScreenMaterial->SetName("StartScreen");
		_resourceList.push_front(startScreenMaterial);

		// Load Gems Material
		std::shared_ptr<Material> gemsMaterial(new Material(ShaderRegistry::GetByName("BasicShader"),
															TextureRegistry::GetByName("Gems")));
		gemsMaterial->SetName("Gems");
		_resourceList.push_front(gemsMaterial);
		gemsMaterial->SetColor(Vector4(1.0f, 0.01f, 0.5f, 1.0f));

		// Load Player Material
		std::shared_ptr<Material> playerMaterial(new Material(ShaderRegistry::GetByName("BasicShader"),
															  TextureRegistry::GetByName("Player")));
		playerMaterial->SetName("Player");
		_resourceList.push_front(playerMaterial);
		playerMaterial->SetColor(Vector4(0.01f, 0.9f, 0.5f, 1.0f));

		// Load Enemy Material
		std::shared_ptr<Material> enemyMaterial(new Material(ShaderRegistry::GetByName("BasicShader"),
															 TextureRegistry::GetByName("Patches")));
		enemyMaterial->SetName("Enemy");
		_resourceList.push_front(enemyMaterial);
		enemyMaterial->SetColor(Vector4(0.9f, 1.0f, 0.01f, 1.0f));

		// Load Player Laser Material
		std::shared_ptr<Material> playerLaserMaterial(new Material(ShaderRegistry::GetByName("BasicShader"),
																   TextureRegistry::GetByName("Bullets")));
		playerLaserMaterial->SetName("PlayerLaser");
		_resourceList.push_front(playerLaserMaterial);
		playerLaserMaterial->SetColor(Vector4(0.05f, 1.0f, 0.6f, 1.0f));

		// Load Enemy Laser Material
		std::shared_ptr<Material> enemyLaserMaterial(new Material(ShaderRegistry::GetByName("BasicShader"),
																  TextureRegistry::GetByName("Bullets")));
		enemyLaserMaterial->SetName("EnemyLaser");
		_resourceList.push_front(enemyLaserMaterial);
		enemyLaserMaterial->SetColor(Vector4(1.0f, 1.0f, 0.02f, 1.0f));

		// Assumes that the resources were successfully loaded
		_resourcesLoaded = true;

		return _resourcesLoaded;
	}

	// Unload all the resources
	void MaterialRegistry::Unload()
	{
		// Skip unloading of list if empty
		if(_resourceList.empty()) return;

		// Empty the list
		_resourceList.clear();

		// Mark the resources as unloaded
		_resourcesLoaded = false;
	}

	// Properties =========================================

	// STATIC: Returns a weak reference to an object by name
	std::weak_ptr<Material> MaterialRegistry::GetByName(const std::string& name)
	{
		// Make sure this registry exists
		std::weak_ptr<Material> empty = std::weak_ptr<Material>();
		if(!MaterialRegistry::verifyInstantiation()) return empty;
		if(MaterialRegistry::_instance->_resourceList.empty()) return empty;

		// Search through the list for an object with the same name as queried
		std::weak_ptr<Material> foundObject = std::weak_ptr<Material>();
		for(auto& resource : MaterialRegistry::_instance->_resourceList)
		{
			// Are the two name string the same?
			if(resource->GetName().compare(name) == 0)
			{
				foundObject = resource;
				return foundObject;
			}
		}

		// Couldn't find the queried name
		return empty;
	}

	// Helpers =========================================

	// STATIC: Was this object instantiated?
	bool MaterialRegistry::verifyInstantiation()
	{
		if(MaterialRegistry::_instance == NULL)
		{
			std::cout << "ERROR: MaterialRegistry not instantiated!" << std::endl;
			return false;
		}

		return true;
	}

} // namespace sfew