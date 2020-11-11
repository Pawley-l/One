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

		static bool IsMousePressed(u16 id);

		static bool IsMouseHeld(u16 id);

		static std::pair<double, double> GetMousePosition();

	private:
		friend Window;

		static void key_callback(void *window, int key, int scancode, int action, int mods);

		static void mouse_button_callback(void *window, int button, int action, int mods);

		static void cursor_position_callback(void *window, double xpos, double ypos);


		static std::array<bool, 255> m_KeysHeld;
		static std::array<bool, 255> m_KeysPressed;
		static std::array<bool, 7> m_MouseButtonsPressed;
		static std::array<bool, 7> m_MouseButtonsHeld;
		static double m_MousePositionX, m_MousePositionY;

//		static struct MousePosition {
//			u32 x;
//			u32 y;
//		} m_MousePosition;
	};
}


#endif //ONE_INPUTMANAGER_H
