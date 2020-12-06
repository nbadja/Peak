#pragma once
#include "Peak/Core.h"
#include "glad/glad.h"


namespace Peak
{
	class  Window
	{
	public:
		Window(std::string title, int width, int height);
		~Window();
		void Init();
		friend void Render();
		void Destroy();
		friend void Update(SDL_Window* window);
		void OnWindowResize();
		int GetWidth();
		int GetHeight();
		SDL_Window* window;
		SDL_GLContext gl_context;
	};
	
}


