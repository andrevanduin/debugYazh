#include"defines.hpp"
#include"core/app.hpp"
#include"game_types.hpp"

/**
 * The main entry point of the app.
 */
int main(void) {
	
	// Request the game instance from the app.
	Lib::Game::VirtualGame* game = Lib::Game::create_game();
	if (!game) {
		std::cerr << "Could not create game!";
		return -1;
	}
	
	// Initialization
	if (!Lib::App::create(game)) {
		std::clog << "App failed to create!";
		return 1;
	}
	
	// Begin the game loop.
	if (!Lib::App::run()) {
		std::clog << "App did not shutdown gracefully";
		return 2;
	}
	
	return 0;
}
