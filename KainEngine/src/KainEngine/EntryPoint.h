#pragma once

#ifdef KE_PLATFORM_WINDOWS

extern KainEngine::Application* KainEngine::CreateApplication();

int main(int argc, char** argv)
{
	KainEngine::Log::Init();
	KE_CORE_WARN("Initialized Log!");
	int a = 5;
	KE_INFO("Hello~! Var={0}", a);

	auto app = KainEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif