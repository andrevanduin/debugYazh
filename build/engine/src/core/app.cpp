#include "app.hpp"
#include "game_types.hpp"

namespace Lib::App {
	struct State 
	{
		Lib::Game::VirtualGame* game;
		bool run;
		bool suspend;
		int num;
	};

	static State state;
	static bool init = false;
	
	bool create(Lib::Game::VirtualGame* game) {
		if(init) {
			std::cerr << "Lib::App::create() called more than once.";
			return false;
		}
		
		state.game = game;
		
		state.run = true;
		state.suspend = false;
		
		std::cout << game->appConfig.num;
		std::cout << game->appConfig.name;
		
		if (!state.game->necessaryMethod()) {
			std::cerr << "Game::necessaryMethod() failed.";
			return false;
		}
		
		init = true;
		
		return true;
	}
	
	bool run() {
		while(state.run) {
			if(state.run) {
				state.run = false;
			}
			
			if (!state.suspend) {
				if (!state.game->necessaryMethod()) {
					std::cerr << "Game::necessaryMethod() failed, shutting down.";
					state.run = false;
					break;
				}
			}
		}
		
		state.run = false;
		
		return true;
	}
} // namespace Lib::App
