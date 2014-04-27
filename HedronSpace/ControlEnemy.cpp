#include "ControlEnemy.hpp"
#include <iostream>
#include "GameObject.hpp"

// System Headers not needed in header


// SFEW Headers not needed in header
#include "Random.hpp"

namespace sfew
{
	namespace component
	{
		// Ctor/Dtor ========================================

		// Constructor
		ControlEnemy::ControlEnemy(std::weak_ptr<GameObject> owningGameObject) :
			CustomComponent(owningGameObject)
		{
			Start();
		}

		// Destructor
		ControlEnemy::~ControlEnemy()
		{
			Cleanup();
		}

		// Required Routines =========================================

		// Runs at contruction of component
		void ControlEnemy::Start()
		{
			
		}

		// Runs every frame
		void ControlEnemy::Update()
		{
			
		}

		// Runs at destruction of component
		void ControlEnemy::Cleanup()
		{

		}

		// Run if there is a collision with an object of a different group
		void ControlEnemy::OnCollision(PhysicsCollisionGroups otherGroup, 
										 std::weak_ptr<PhysicsEntity> otherEntity)
		{
			
		}

		// Custom Routines =========================================

		// Properties =========================================

		// Private Routines =========================================

	} // namespace sfew::component
} // namespace sfew