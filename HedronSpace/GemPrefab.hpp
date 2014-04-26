// [EXAMPLE] Prefabrication
// [DESCRIBE THE GAMEOBJECT THIS PREFAB MAKES]
//
// Written by [NAME] ([MONTH]-[DAY]-[YEAR])

// Required Headers
#ifndef SFEW_CUSTOM_PREFAB__GEM
#define SFEW_CUSTOM_PREFAB__GEM
#include "Prefabrication.hpp"

// System Headers


// SFEW Headers 


namespace sfew
{
	namespace prefab
	{
		class GemPrefab : public Prefabrication
		{
		public:

			// Ctor/Dtor ======================

			GemPrefab();
			virtual ~GemPrefab();

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