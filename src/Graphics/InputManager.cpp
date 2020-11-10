#include <Application/InputManager.h>
#include <memory>
#include <GLFW/glfw3.h>
#include <iostream>

std::array<bool, 255> One::InputManager::m_KeysHeld;
std::array<bool, 255> One::InputManager::m_KeysPressed;

//void One::Window::InputManager::SetPressed(u32 id)
//{
//	if (!m_KeysHeld[id])
//		m_KeysPressed[id] = true;
//	m_KeysHeld[id] = true;
//}

bool One::InputManager::IsKeyPressed(u32 id)
{
	if (m_KeysPressed[id])
	{
		m_KeysPressed[id] = false;
		return true;
	}

	return false;
}

bool One::InputManager::IsKeyHeld(u32 id)
{
	return m_KeysHeld[id];
}

void One::InputManager::key_callback(void *window, int key, int scancode, int action, int mods)
{
	//if (key == GLFW_KEY_E && action == GLFW_PRESS)
	if (action == GLFW_PRESS)
	{
		if (!m_KeysHeld[key])
			m_KeysPressed[key] = true;
		m_KeysHeld[key] = true;
	}
	if (action == GLFW_RELEASE)
	{
		m_KeysPressed[key] = false;
		m_KeysHeld[key] = false;
	}
}
