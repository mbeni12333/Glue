#pragma once


namespace GLUE{

    #ifdef GLUE_PLATFORM_WINDOWS
        // This approach allows to use a single keyword GLUE_BUILD_DLL in the engine
        // as well as in the user without worriying about which is which
        #ifdef GLUE_BUILD_DLL
            // If we are building the dll, we export the class
            #define GLUE_API __declspec(dllexport)
        #else
            // If we are using the dll, we import the class.
            #define GLUE_API __declspec(dllimport)
        #endif
    #else
        #error GluEngine only supports Windows!
    #endif


#ifdef GLUE_ENABLE_ASSERTS
    #define GLUE_ASSERT(x, ...) { if(!(x)) { GLUE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define GLUE_CORE_ASSERT(x, ...) { if(!(x)) { GLUE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define GLUE_ASSERT(x, ...)
    #define GLUE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

}
