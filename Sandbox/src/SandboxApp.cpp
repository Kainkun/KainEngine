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
			KE_TRACE("SPACE IS PRESSED (poll)!!!");
	}

	void OnEvent(KainEngine::Event& event) override
	{
		if (event.GetEventType() == KainEngine::EventType::KeyPressed)
		{
			KainEngine::KeyPressedEvent& e = (KainEngine::KeyPressedEvent&)event;
			if(e.GetKeyCode() == KE_KEY_SPACE)
				KE_TRACE("SPACE IS PRESSED (event)!!!");
		}
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