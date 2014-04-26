// [EXAMPLE] Scene
// [DESCRIBE THE SCENE/LEVEL HERE]
//
// Written by [NAME] ([MONTH]-[DAY]-[YEAR])

// Required Headers
#ifndef SFEW_CUSTOM_SCENE__START
#define SFEW_CUSTOM_SCENE__START
#include "Scene.hpp"

// System Headers


// SFEW Headers


namespace sfew
{
	namespace scene
	{
		class StartScene : public Scene
		{
		public:

			// Ctor/Dtor ======================

			StartScene();
			virtual ~StartScene();

			// Routines =======================

			virtual bool Load();			// Clears current scene and loads
			virtual bool LoadAdditive();	// Loads without clearing current scene

			// Properties =====================

		private:

			// Helpers ========================

			
			
			// Data ===========================

			
			
		};

	} // namespace sfew::scene
} // namespace sfew

#endif