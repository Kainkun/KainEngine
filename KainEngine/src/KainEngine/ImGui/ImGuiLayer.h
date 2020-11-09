#pragma once

#include "KainEngine/Layer.h"

#include "KainEngine/Events/ApplicationEvent.h"
#include "KainEngine/Events/KeyEvent.h"
#include "KainEngine/Events/MouseEvent.h"

namespace KainEngine
{
	class KAINENGINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}