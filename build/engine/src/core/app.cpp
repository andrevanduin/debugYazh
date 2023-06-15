#include"app.hpp"

namespace Lib::App {
	static struct state {
		bool run;
		bool suspend;
		int num;
	} state;
	
	static bool init = false;
	
	bool create(config* appConfig) {
		if(init) {
			std::cerr << "Lib::App::create called more than once.";
			return false;
		}
		
		state.run = true;
		state.suspend = false;
		
		std::cout << "Lib::App created!" << std::endl;

		init = true;
		
		std::cout << "struct Lib::App::state state {\n"
		          << "\tbool run = " << state.run << ";\n"
		          << "\tbool suspend = " << state.run << ";\n"
		          << "\tint num = " << state.num << ";\n"
		          << '}' << std::endl;
		std::cout << "Lib::App::config appConfig {\n"
		          << "\tchar* name = " << appConfig->name << ";\n"
		          << "\tint num = " << appConfig->num << ";\n"
		          << '}' << std::endl;
		std::cout << "bool init = " << init << ';' << std::endl;
		
		return true;
	}
	
	bool run() {
		while(state.run) {
			std::clog << "Main loop running!" << std::endl;
			if(state.run) {
				break;
			}
		}
		
		std::clog << "Main loop broken!" << std::endl;
		state.run = false;
		
		return true;
	}
} // namespace Yazh::Application
