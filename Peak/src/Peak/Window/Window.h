#pragma once
#include "Peak/Core.h"
#include "GL/gl3w.h"
#include "SDL.h"

namespace Peak
{
	class PEAK_API Window
	{
	public:
		Window(std::string title, int width, int height);
		~Window();
		void Init();
		friend void Render();
		void Destroy();
		friend void SwapWindow(SDL_Window* window);
		SDL_Window* window;
		SDL_GLContext gl_context;
	};
	
}


