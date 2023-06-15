#include<iostream>
#include<string>

// Platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) 
#	define LPLATFORM_WINDOWS true
#	ifndef _WIN64
#		error "64-bit is required on Windows!"
#	endif
#elif defined(__linux__) || defined(__gnu_linux__)
// Linux OS
#	define LPLATFORM_LINUX true
#	if defined(__ANDROID__)
#		define YPLATFORM_ANDROID true
#	endif

// Catch anything not caught by the above.

#elif defined(_POSIX_VERSION)
// Posix
#	define LPLATFORM_POSIX true
#elif __APPLE__
// Apple platforms
#	define LPLATFORM_APPLE true
#	include <TargetConditionals.h>
#	if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#		define LPLATFORM_IOS true
#		define LPLATFORM_IOS_SIMULATOR true
#	elif TARGET_OS_IPHONE
#		define LPLATFORM_IOS true
// iOS device
#	elif TARGET_OS_MAC
// Other kinds of Mac OS
#	else
#		error "Unknown Apple platform"
#	endif
#elif defined(__unix__)
#	define LPLATFORM_UNIX true
#else
#	error "Unknown platform!"
#endif

#ifdef LEXPORT
// Exports
#	ifdef LPLATFORM_WINDOWS
#		define LAPI __declspec(dllexport)
#	else
#		define LAPI __attribute__((visibility("default")))
#	endif
#else
// Imports
#	ifdef LPLATFORM_WINDOWS
#		define LAPI __declspec(dllimport)
#	else
#		define LAPI
#	endif
#endif

