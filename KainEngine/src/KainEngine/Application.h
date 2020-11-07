#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace KainEngine
{

	class KAINENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}