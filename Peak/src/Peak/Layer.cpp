#include "peakpch.h"
#include "Layer.h"

namespace Peak
{
	Layer::Layer(const std::string& debugName)
		:m_DebugName(debugName)
	{
	}

	Layer::~Layer()
	{

	}

	void Layer::RegisterEvent(SDL_Event& event)
	{
		m_Event = event;
		Input = SDL_GetKeyboardState(NULL);
	}
}