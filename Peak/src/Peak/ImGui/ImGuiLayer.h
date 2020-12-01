#pragma once
#include "Peak/Layer.h"

namespace Peak
{
	class PEAK_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();
		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(SDL_Event& event);
	private:
		float m_Time = 0.0f;
	};

}