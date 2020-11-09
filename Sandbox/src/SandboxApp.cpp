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
		if (KainEngine::Input::IsKeyPressed(KE_KEY_SPACE))
			KE_TRACE("SPACE IS PRESSED!!!");
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
		PushOverlay(new KainEngine::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

KainEngine::Application* KainEngine::CreateApplication()
{
	return new Sandbox();
}