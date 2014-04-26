// [EXAMPLE] Prefabrication
// [DESCRIBE THE GAMEOBJECT THIS PREFAB MAKES]
//
// Written by [NAME] ([MONTH]-[DAY]-[YEAR])

// Required Headers
#ifndef SFEW_CUSTOM_PREFAB__ENEMY
#define SFEW_CUSTOM_PREFAB__ENEMY
#include "Prefabrication.hpp"

// System Headers


// SFEW Headers 


namespace sfew
{
	namespace prefab
	{
		class EnemyPrefab : public Prefabrication
		{
		public:

			// Ctor/Dtor ======================

			EnemyPrefab();
			virtual ~EnemyPrefab();

			// Routines =======================

			virtual std::weak_ptr<GameObject> MakeObject();

			// Properties =====================


		private:

			// Helpers ========================

			

			// Data ===========================
			
			
			
		}; // End of custom prefab class header

	} // namespace sfew::prefab
} // namespace sfew

#endif