#include "GLUE/Application.h"
#include "GLUE/Log.h"
#include "GLUE/Events/ApplicationEvent.h"
#include "GLUE/Events/MouseEvent.h"

namespace GLUE {

	Application::Application(){
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

		while (true);
	}

}