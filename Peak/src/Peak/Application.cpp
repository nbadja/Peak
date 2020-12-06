#include "peakpch.h"
#include "Application.h"
#include "Renderer/Renderer.h"


namespace Peak {

    Application* Application::s_Instance = nullptr;

	Application::Application(std::string title, int width, int height)
	{
		s_Instance = this;
		Create_Window(title, width, height);
		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
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

	void Application::HandleEvents()
	{

		for (Layer* layer : m_LayerStack)
			layer->OnEvent(event);

		while (SDL_PollEvent(&event)) {
			ImGui_ImplSDL2_ProcessEvent(&event);
			if (event.type == SDL_QUIT)
				m_Running = false;
			else if (event.type == SDL_WINDOWEVENT)
			{
				switch (event.window.event)
				{
				case SDL_WINDOWEVENT_RESIZED:
					m_Window->OnWindowResize();
					break;
				}
			}
		}
	}

	void Application::Run()
	{	

		while (m_Running)
		{
			float time = (float) SDL_GetTicks() / 1000.0f;
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			HandleEvents();

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(timestep);

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImGuiLayer->End();

			Update(m_Window->window);
		}
	}
}