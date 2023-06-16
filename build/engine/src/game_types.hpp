#pragma once

#include"core/app.hpp"

namespace Lib::Game {
	class VirtualGame {
		public:
			Lib::App::config appConfig;
			
			virtual bool necessaryMethod() = 0;
	};
	class Game : public VirtualGame {
		public:
			bool necessaryMethod();
	};
}