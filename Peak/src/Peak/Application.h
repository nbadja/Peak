#pragma once
#include "Core.h"
#include "Peak/Log.h"
#include "Peak/LayerStack.h"
#include "Window/Window.h"

namespace Peak {
	class PEAK_API Application
	{
	public:
			Application();
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
			void Create_Window(std::string title, int width, int height);
	private:
			bool m_Running = true;
			LayerStack m_LayerStack;
			static Application* s_Instance;
			Window* m_Window;
	};

	Application* CreateApplication();
}


