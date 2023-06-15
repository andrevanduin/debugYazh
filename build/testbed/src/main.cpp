#include<core/app.hpp>

int main(void) {
	// Application configuration.
	Lib::App::config appConfig;
	appConfig.num = 3;
	appConfig.name = (char*)"Yazh Engine Testbed";
	
	Lib::App::create(&appConfig);
	
	Lib::App::run();
}
