#pragma once
#include "Core.h"
#include "Peak/Log.h"


namespace Peak {
	class PEAK_API Application
	{
		public:
			Application();
			virtual ~Application();
			void Run();
	private:
		bool m_Running = true;
	};

	Application* CreateApplication();
}


