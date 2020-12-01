#include "peakpch.h"
#include "Window.h"


namespace Peak
{

	Window::Window(std::string title, int width, int height)
	{
		Window::Init();
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
		gl_context = SDL_GL_CreateContext(window);
		SDL_GL_SetSwapInterval(1); // Enable vsync
	//	gl3wInit();
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
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
		SDL_DisplayMode current;
		SDL_GetCurrentDisplayMode(0, &current);
	}

	void Peak::Render()
	{
		//Render background
		/*glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);*/
	}

	void Window::Destroy()
	{
		SDL_GL_DeleteContext(gl_context);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void Peak::SwapWindow(SDL_Window* window)
	{
		SDL_GL_SwapWindow(window);
	}
}