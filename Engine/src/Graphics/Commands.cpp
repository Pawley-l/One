#include <Graphics/Commands.h>
#include <Graphics/OpenGL3/GL3Commands.h>
#include <iostream>

std::unique_ptr<One::Commands> One::Commands::m_Instance;

std::unique_ptr<One::Commands> &One::Commands::GetInstance()
{
	return m_Instance;
}

std::unique_ptr<One::Commands> &One::Commands::GetInstanceInitialize(One::GraphicsAPI api)
{
	if (m_Instance == nullptr) {
		switch (api) {
			case GraphicsAPI::GL3:
				m_Instance = std::unique_ptr<One::Commands>(new GL3::GL3Commands());
				break;
			case GraphicsAPI::Vulkan:
				break;
			case GraphicsAPI::GL2:
				break;
		}
	}

	return m_Instance;
}

One::Commands::Commands()
{
	LOG("Graphics Initialized");
}



