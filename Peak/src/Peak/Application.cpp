#include "peakpch.h"
#include "Application.h"
#include "Window/Window.h"

namespace Peak {
	Application::Application()
	{
	}
	Application::~Application()
	{

	}
	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}
	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	void Application::Run()
	{	
		Window main("Peak Engine", 1280, 720);


		while (m_Running)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT)
					m_Running = false;

			for (Layer* layer : m_LayerStack)
				layer->OnEvent(event);
			}

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();


			//	Render();
			SwapWindow(main.window);
		}
	}

}