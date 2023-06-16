#pragma once

#include"defines.hpp"

namespace Lib::Game {
	class Game;
}

namespace Lib::App {
	using config = struct config {
		int num;
		char* name;
	};
	
	LAPI bool create(class Lib::Game::Game* game);
	
	LAPI bool run();
} // namespace Lib::App
