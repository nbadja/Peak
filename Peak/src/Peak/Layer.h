#pragma once

#include "Peak/Core.h"
#include <string>
#include "Peak/Core/Timestep.h"

namespace Peak
{
	class  Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep timestep) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(SDL_Event& event) {}
		virtual void RegisterEvent(SDL_Event& event);

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
		SDL_Event m_Event;
		const Uint8* Input;
	};

}
