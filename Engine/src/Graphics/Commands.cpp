#include <Graphics/Commands.h>
#include <Graphics/GL3/GL3Commands.h>
#include <iostream>

std::unique_ptr<One::Graphics::Commands> One::Graphics::Commands::m_Instance;

std::unique_ptr<One::Graphics::Commands> &One::Graphics::Commands::GetInstance()
{
	return m_Instance;
}

std::unique_ptr<One::Graphics::Commands> &One::Graphics::Commands::GetInstanceInitialize(One::Graphics::API api)
{
	if (m_Instance == nullptr)
	{
		switch (api)
		{
			case API::GL3:
				m_Instance = std::unique_ptr<One::Graphics::Commands>(new GL3::GL3Commands());
				break;
			case API::Vulkan:
				break;
			case API::GL2:
				break;
		}
	}

	return m_Instance;
}


One::Graphics::Commands::Commands()
{
	LOG("Graphics Initialized");
}


