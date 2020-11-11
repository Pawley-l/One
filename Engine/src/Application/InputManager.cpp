#include <Application/InputManager.h>
#include <memory>
#include <GLFW/glfw3.h>
#include <iostream>

//	if (!m_KeysHeld[id])
//		m_KeysPressed[id] = true;
//	m_KeysHeld[id] = true;

std::array<bool, 255> One::InputManager::m_KeysHeld;
std::array<bool, 255> One::InputManager::m_KeysPressed;
std::array<bool, 7> One::InputManager::m_MouseButtonsPressed;
std::array<bool, 7> One::InputManager::m_MouseButtonsHeld;
double One::InputManager::m_MousePositionX;
double One::InputManager::m_MousePositionY;

void One::InputManager::mouse_button_callback(void *window, int button, int action, int mods)
{
	if (action == GLFW_PRESS) {
		if (!m_MouseButtonsHeld[button])
			m_MouseButtonsPressed[button] = true;
		m_MouseButtonsHeld[button] = true;
	}
	if (action == GLFW_RELEASE) {
		m_MouseButtonsPressed[button] = false;
		m_MouseButtonsHeld[button] = false;
	}
}

void One::InputManager::cursor_position_callback(void *window, double xpos, double ypos)
{
	m_MousePositionX = xpos;
	m_MousePositionY = ypos;
}

void One::InputManager::key_callback(void *window, int key, int scancode, int action, int mods)
{
	//if (key == GLFW_KEY_E && action == GLFW_PRESS)
	if (action == GLFW_PRESS) {
		if (!m_KeysHeld[key])
			m_KeysPressed[key] = true;
		m_KeysHeld[key] = true;
	}
	if (action == GLFW_RELEASE) {
		m_KeysPressed[key] = false;
		m_KeysHeld[key] = false;
	}
}

bool One::InputManager::IsKeyPressed(u32 id)
{
	if (m_KeysPressed[id]) {
		m_KeysPressed[id] = false;
		return true;
	}

	return false;
}

bool One::InputManager::IsKeyHeld(u32 id)
{
	return m_KeysHeld[id];
}

bool One::InputManager::IsMousePressed(u16 id)
{
	return m_MouseButtonsPressed[id];
}

bool One::InputManager::IsMouseHeld(u16 id)
{
	return m_MouseButtonsHeld[id];
}

std::pair<double, double> One::InputManager::GetMousePosition()
{
	return std::pair<double, double>(m_MousePositionX, m_MousePositionY);
}
