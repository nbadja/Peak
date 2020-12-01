#include "peakpch.h"
#include "Application.h"
#include "Window/Window.h"
#include "Platform/OpenGL/imgui_impl_sdl.h"
#include "Platform/OpenGL/imgui_impl_opengl3.h"
#include "Peak/ImGui/ImGuiLayer.h"

namespace Peak {

    Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		s_Instance = this;
	}

	Application::~Application()
	{

	}
	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::Create_Window(std::string title, int width, int height)
	{
		m_Window = new Window(title.c_str(), width, height);
	}

	void Application::Run()
	{	

		SDL_Event event;
		while (m_Running)
		{
			while (SDL_PollEvent(&event)) {
				ImGui_ImplSDL2_ProcessEvent(&event);
				if (event.type == SDL_QUIT)
					m_Running = false;

			for (Layer* layer : m_LayerStack)
				layer->OnEvent(event);
			}

		

			Render();

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			Update(m_Window->window);




			
		}
	}
}