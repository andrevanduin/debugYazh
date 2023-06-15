#pragma once

#include"defines.hpp"

namespace Lib::App {
	using config = struct config {
		int num;
		char* name;
	};
	
	LAPI bool create(config* appConfig);
	
	LAPI bool run();
} // namespace Lib::App
