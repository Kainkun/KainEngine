#include "kepch.h"
#include "Buffer.h"

#include "Renderer.h"

#include "KainEngine/Platform/OpenGL/OpenGLBuffer.h"

namespace KainEngine
{
	VertexBuffer* VertexBuffer::Create(float* verticies, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: KE_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexBuffer(verticies, size);
		}

		KE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: KE_CORE_ASSERT(false, "RendererAPI::None is currently not supported"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLIndexBuffer(indices, size);
		}

		KE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}