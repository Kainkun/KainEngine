#include "kepch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "KainEngine/Platform/OpenGL/OpenGLVertexArray.h"

namespace KainEngine
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: KE_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexArray();
		}

		KE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}