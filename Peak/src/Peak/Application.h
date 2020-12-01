#pragma once
#include "Core.h"
#include "Peak/Log.h"
#include "Peak/LayerStack.h"


namespace Peak {
	class PEAK_API Application
	{
	public:
			Application();
			virtual ~Application();
			void Run();

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* overlay);
	private:
			bool m_Running = true;
			LayerStack m_LayerStack;
	};

	Application* CreateApplication();
}


