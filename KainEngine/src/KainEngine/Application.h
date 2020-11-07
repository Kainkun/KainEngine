#pragma once
#include "Core.h"

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