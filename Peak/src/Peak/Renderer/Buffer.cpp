#include "peakpch.h"
#include "Buffer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"
#include "Renderer.h"
#include <Peak\Log.h>

namespace Peak
{
	void VertexBuffer::SetLayout(const BufferLayout& layout)
	{
	}
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch(Renderer::GetAPI())
		{
		case RendererAPI::None: PEAK_CORE_WARN("RendererAPI::None is currently not supported");  return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		}
		PEAK_CORE_WARN("Unknown RendererAPI value");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: PEAK_CORE_WARN("RendererAPI::None is currently not supported");  return nullptr;
		case RendererAPI::OpenGL: return new OpenGLIndexBuffer(indices, size);
		}
		PEAK_CORE_WARN("Unknown RendererAPI value");
		return nullptr;
	}
}