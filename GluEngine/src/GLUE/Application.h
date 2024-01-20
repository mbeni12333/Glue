#pragma once

#include "GLUE/Core.h"
#include "GLUE/Events/Event.h"

namespace GLUE{

    // The Application class is the base class for all applications. It is responsible for the main loop and the creation of the window.
    // it's exported as a dll so that the user can create their own application class and use it in the engine.
    class GLUE_API Application{
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // This function is defined in the user's application class. It is used to create the application.
    Application* CreateApplication();


}