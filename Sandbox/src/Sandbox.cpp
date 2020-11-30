#include "Peak.h"

class Sandbox : public Peak::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Peak::Application* Peak::CreateApplication()
{
	return new Sandbox();
}