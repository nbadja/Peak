#pragma once
#include "Core.h"

namespace Peak {
	class PEAK_API Application
	{
		public:
			Application();
			virtual ~Application();
			void Run();
	};

	Application* CreateApplication();
}


