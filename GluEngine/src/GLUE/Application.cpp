#include "gepch.h"
#include "GLUE/Application.h"
#include <GLFW/glfw3.h>

namespace GLUE {


#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)


	Application::Application(){
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}


	Application::~Application()	{
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowCloseEvent));
		GLUE_CORE_INFO("{0}", e);
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
	bool Application::OnWindowCloseEvent(WindowCloseEvent& event) {
		m_Running = false;

		return true;
	}
}