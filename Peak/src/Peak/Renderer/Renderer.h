#pragma once
#include "Peak/Renderer/VertexArray.h"
#include "glad/glad.h"
#include <Peak\Renderer\Camera.h>
#include "Peak/Renderer/Shader.h"

namespace Peak
{
	enum class RendererAPI
	{
		None = 0,
		OpenGL = 1
	};

	class Renderer
	{
	public:
		inline static RendererAPI GetAPI() {
			return s_RendererAPI;
		}
		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();
		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);
		
		inline static void SetClearColor(float r, float g, float b, float a)
		{
			glClearColor(r, g, b, a);
		}

		inline static void Clear()
		{
			glClear(GL_COLOR_BUFFER_BIT);
		}
	private:
		static RendererAPI s_RendererAPI;
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;
	};

}