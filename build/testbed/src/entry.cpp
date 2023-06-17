#include<entry.hpp>
#include"game.hpp"

// Define the function to create a game.
namespace Lib::Game {
	Game game;

	VirtualGame* create_game() {
		// Application configuration.
		game.appConfig.num = 3;
		game.appConfig.name = "Game";
		
		return &game;
	}
} // namespace Lib::Game