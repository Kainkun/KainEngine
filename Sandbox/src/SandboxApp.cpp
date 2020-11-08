#include <KainEngine.h>

class ExampleLayer : public KainEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		KE_INFO("ExampleLayer::Update");
	}

	void OnEvent(KainEngine::Event& event) override
	{

	}
};

class Sandbox : public KainEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

KainEngine::Application* KainEngine::CreateApplication()
{
	return new Sandbox();
}