// [EXAMPLE] Scene
// [DESCRIBE THE SCENE/LEVEL HERE]
//
// Written by [NAME] ([MONTH]-[DAY]-[YEAR])

// Required Headers
#ifndef SFEW_CUSTOM_SCENE__GAMEOVER
#define SFEW_CUSTOM_SCENE__GAMEOVER
#include "Scene.hpp"

// System Headers


// SFEW Headers


namespace sfew
{
	namespace scene
	{
		class GameOverScene : public Scene
		{
		public:

			// Ctor/Dtor ======================

			GameOverScene();
			virtual ~GameOverScene();

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