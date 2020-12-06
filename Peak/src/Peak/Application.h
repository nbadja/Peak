#pragma once
#include "Core.h"
#include "Peak/Log.h"
#include "Peak/LayerStack.h"
#include "Window/Window.h"
#include "Peak/ImGui/ImGuiLayer.h"
#include "Platform/OpenGL/imgui_impl_SDL.h"
#include "Platform/OpenGL/imgui_impl_opengl3.h"
#include "Peak/Renderer/Shader.h"
#include <Peak\Renderer\Buffer.h>
#include "Peak/Renderer/VertexArray.h"
#include "Renderer/Camera.h"
#include "Peak/Core/Timestep.h"

namespace Peak {
	class  Application
	{
	public:
			Application(std::string title, int width, int height);
			virtual ~Application();
			void Run();

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* overlay);
			inline static Application& Get() {
				return *s_Instance;
			}
			inline Window* GetWindow() { 
				return m_Window;
			}
			inline ImGuiLayer* GetImGuiLayer() {
				return m_ImGuiLayer;
			}
			void Create_Window(std::string title, int width, int height);
			void HandleEvents();
	private:
			float m_LastFrameTime = 0.0f;
	private:
			bool m_Running = true;
			LayerStack m_LayerStack;
			static Application* s_Instance;
			Window* m_Window;
			ImGuiLayer* m_ImGuiLayer;
			SDL_Event event;
	};

	Application* CreateApplication();
}


