#pragma once

namespace Lib::Game {
	struct Config {
		int num;
		const char* name;
	};

	class VirtualGame {
	public:
		virtual bool necessaryMethod() = 0;

		Config appConfig;
	};

	VirtualGame* create_game();
}