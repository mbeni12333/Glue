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



#define BIT(x) (1 << x)

}
