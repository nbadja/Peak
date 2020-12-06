
#define isMousePressed(x)  SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(x)
#define isKeyPressed(x) Input[x]
#define	MouseWheelVertical	m_Event.wheel.y
#define	MouseWheelHorizontal	m_Event.wheel.x
#define isEventType(x) m_Event.type == x

#define KeyPressed m_Event.key.keysym.sym

#define isKeyDown(x) isEventType(SDL_KEYDOWN) && KeyPressed == x
#define isKeyUp(x) isEventType(SDL_KEYUP) && KeyPressed == x

#define KEY(x) SDL_SCANCODE_##x