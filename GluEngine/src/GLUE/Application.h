#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"
#include "Window.h"

namespace GLUE{

    // The Application class is the base class for all applications. It is responsible for the main loop and the creation of the window.
    // it's exported as a dll so that the user can create their own application class and use it in the engine.
    class GLUE_API Application{
    public:
        Application();
        virtual ~Application();
        void OnEvent(Event& e);
        

        void Run();
    private:
        bool OnWindowCloseEvent(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    // This function is defined in the user's application class. It is used to create the application.
    Application* CreateApplication();


}