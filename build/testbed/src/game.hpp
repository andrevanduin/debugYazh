#pragma once
#include<game_types.hpp>

namespace Lib::Game {
	class Game : public VirtualGame {
		public:
			bool necessaryMethod() override {
				return true;
			}
	};
} // namespace Lib::Game