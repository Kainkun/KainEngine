#include "kepch.h"
#include "Application.h"
#include "KainEngine/Events/ApplicationEvent.h"
#include "KainEngine/Log.h"

namespace KainEngine
{

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			KE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			KE_ERROR("WRONG");
		}

		while (true);
	}
}