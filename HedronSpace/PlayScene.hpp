// [EXAMPLE] Scene
// [DESCRIBE THE SCENE/LEVEL HERE]
//
// Written by [NAME] ([MONTH]-[DAY]-[YEAR])

// Required Headers
#ifndef SFEW_CUSTOM_SCENE__PLAY
#define SFEW_CUSTOM_SCENE__PLAY
#include "Scene.hpp"

// System Headers


// SFEW Headers


namespace sfew
{
	namespace scene
	{
		class PlayScene : public Scene
		{
		public:

			// Ctor/Dtor ======================

			PlayScene();
			virtual ~PlayScene();

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