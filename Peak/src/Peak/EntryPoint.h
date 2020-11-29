#pragma once


#ifdef PEAK_PLATFORM_WINDOWS

extern Peak::Application* Peak::CreateApplication();

int main(int args, char** argv)
{
	Peak::Log::Init();
	PEAK_CORE_ERROR("JUST A ERROR");
	PEAK_CORE_INFO("Peak Engine 1.0v started..");
	PEAK_CORE_WARN("Initialized core log");
	PEAK_INFO("Initialized client log");

	auto app = Peak::CreateApplication();
	app->Run();
	delete app;
}

#endif