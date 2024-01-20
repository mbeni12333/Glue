#include "gepch.h"
#include "GLUE/Application.h"

#include "GLUE/Events/ApplicationEvent.h"
#include "GLUE/Events/MouseEvent.h"

#include <GLFW/glfw3.h>

namespace GLUE {

	Application::Application(){
		m_Window = std::unique_ptr<Window>(Window::Create());
	}


	Application::~Application()	{
	}

	void Application::Run()	{
		WindowResizeEvent e(1280, 720);
		MouseMovedEvent e2(20, 30);

		if (e.IsInCategory(EventCategoryApplication)) {
			GLUE_TRACE(e);
		}

		if (e2.IsInCategory(EventCategoryInput)) {
			GLUE_TRACE(e2);
		}

		while (m_Running){
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

}