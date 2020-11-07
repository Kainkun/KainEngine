#pragma once

#ifdef KE_PLATFORM_WINDOWS

extern KainEngine::Application* KainEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = KainEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif