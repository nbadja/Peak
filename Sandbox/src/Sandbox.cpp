#include "Peak.h"
#include "SDL.h"

class ExampleLayer : public Peak::Layer
{
public:
	ExampleLayer() :Layer("Example")
	{

	}

	void OnEvent(SDL_Event& event) override
	{
		
	}

	void OnUpdate() override
	{
	
	}
};

class Sandbox : public Peak::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{

	}
};

Peak::Application* Peak::CreateApplication()
{
	return new Sandbox();
}