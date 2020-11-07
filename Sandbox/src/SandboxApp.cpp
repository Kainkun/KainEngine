#include <KainEngine.h>

class Sandbox : public KainEngine::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

KainEngine::Application* KainEngine::CreateApplication()
{
	return new Sandbox();
}