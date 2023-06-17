#pragma once
#include"defines.hpp"
#include"game_types.hpp"

namespace Lib::App {
	LAPI bool create(Lib::Game::VirtualGame* game);
	
	LAPI bool run();
} // namespace Lib::App
