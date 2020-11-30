#pragma once


#ifdef PEAK_PLATFORM_WINDOWS

extern Peak::Application* Peak::CreateApplication();

int main(int args, char** argv)
{
	Peak::Log::Init();
	PEAK_CORE_TRACE("Peak Engine 1.0v started..");
	auto app = Peak::CreateApplication();
	app->Run();
	delete app;
}

#endif