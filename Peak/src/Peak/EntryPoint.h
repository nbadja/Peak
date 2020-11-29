#pragma once


#ifdef PEAK_PLATFORM_WINDOWS

extern Peak::Application* Peak::CreateApplication();

int main(int args, char** argv)
{
	printf("Peak Engine 1.0v started\n");
	auto app = Peak::CreateApplication();
	app->Run();
	delete app;
}

#endif