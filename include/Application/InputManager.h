#ifndef ONE_INPUTMANAGER_H
#define ONE_INPUTMANAGER_H

#include <memory>
#include <One.h>

namespace One {
	class Window;
}

namespace One
{
	class InputManager
	{
	public:
		static bool IsKeyPressed(u32 id);
		static bool IsKeyHeld(u32 id);

	private:
		friend Window;
		static void key_callback(void* window, int key, int scancode, int action, int mods);

		static std::array<bool, 255> m_KeysHeld;
		static std::array<bool, 255> m_KeysPressed;
//		static struct MousePosition {
//			u32 x;
//			u32 y;
//		} m_MousePosition;
	};
}


#endif //ONE_INPUTMANAGER_H
