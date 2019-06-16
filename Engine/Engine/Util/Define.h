#pragma once

#ifdef ONE_ENGINE
#ifdef ONE_WINDOW

//#if ONE_DINAMIC_LINK
//#ifdef ONE_BUILD_DLL
//
//#define  __declspec(dllexport)
//#else
//#define  __declspec(dllimport)
//
//#endif // ONE_BUILD_DLL
//
//#else
//#define 
//#endif    // ONE_DINAMIC_LINK  

#else
#error BooEngine only support Windows!

#endif // ONE_WINDOW
#endif // ONE_ENGINE


#ifdef ONE_DEBUG
#define ONE_ENABLE_ASSERTS
#endif

#ifdef ONE_ENABLE_ASSERTS
#define CLIENT_ASSERT(x, ...) { if(!(x)) { CLIENT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define ENGINE_ASSERT(x, ...) { if(!(x)) { ENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define ONE_ASSERT(x, ...)
#define ONE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define ONE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

//constexpr auto DISPLAY_ID_NO_DISPLAY = -1;
#define DISPLAY_ID_NO_DISPLAY -1


