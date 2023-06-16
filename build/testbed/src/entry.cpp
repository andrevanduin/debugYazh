#include<entry.hpp>

// Define the function to create a game.
namespace Lib::Game {
	Game game;
	Game* create() {
		// Application configuration.
		game.appConfig.num = 3;
		game.appConfig.name = (char*)"Yazh Engine Testbed";
		
		return &game;
	}
} // namespace Lib::Game