#include "peakpch.h"
#include "Window.h"
#include "Peak/Log.h"
#include "Peak/ImGui/ImGuiLayer.h"
#include "Peak/Application.h"
#include <imgui.h>

namespace Peak
{

	Window::Window(std::string title, int width, int height)
	{
		Window::Init();
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
		gl_context = SDL_GL_CreateContext(window);
		SDL_GL_MakeCurrent(window, gl_context);
		gladLoadGLLoader(SDL_GL_GetProcAddress);
		PEAK_CORE_INFO("Vendor:  {0}", glGetString(GL_VENDOR));
		PEAK_CORE_INFO("Renderer:{0}", glGetString(GL_RENDERER));
		PEAK_CORE_INFO("Version: {0}", glGetString(GL_VERSION));
		SDL_GL_SetSwapInterval(1); // Enable vsync
		
	}

	Window::~Window()
	{
		Window::Destroy();
	}

	void Window::Init()
	{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
			printf("Error: %s\n", SDL_GetError());
		}
		SDL_GL_LoadLibrary(NULL);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
	}

	void Peak::Render()
	{
		
	}

	void Window::Destroy()
	{
		SDL_GL_DeleteContext(gl_context);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void Peak::Update(SDL_Window* window)
	{
		SDL_GL_SwapWindow(window);
	}

	void Window::OnWindowResize()
	{
		glViewport(0, 0, GetWidth(), GetHeight());
	}

	int Window::GetWidth()
	{
		int width, height;
		SDL_GetWindowSize(window, &width, &height);
		return width;
	}

	int Window::GetHeight()
	{
		int width,height;
		SDL_GetWindowSize(window, &width, &height);
		return height;
	}
}