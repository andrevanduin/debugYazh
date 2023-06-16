#pragma once
#include<game_types.hpp>

namespace Lib::Game {
	class Game : public Lib::Game::VirtualGame {
		public:
			bool necessaryMethod() override {
				return True;
			}
	};
} // namespace Lib::Game