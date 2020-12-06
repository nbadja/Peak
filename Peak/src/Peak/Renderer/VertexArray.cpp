#include "peakpch.h"
#include "VertexArray.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Peak
{
	
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: PEAK_CORE_WARN("RendererAPI::None is currently not supported");  return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexArray();
		}
		PEAK_CORE_WARN("Unknown RendererAPI value");
		return nullptr;
	}
}