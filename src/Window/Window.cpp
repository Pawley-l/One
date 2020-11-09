#include <Window/Window.h>
#include <iostream>
#include <Graphics/GL3/GL3Context.h>
#include <Graphics/GraphicsFactory.h>
#include <Graphics/Commands.h>

One::Window::Window(const std::string &name, int width, int height, Graphics::API api) : m_GraphicsApi(api)
{
	glfwInit();
	m_WindowImpl = glfwCreateWindow(width, height, name.c_str(),nullptr,nullptr);

	if (m_WindowImpl == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	InitGraphics(api);
	glfwSwapInterval(1);
	Graphics::Commands::GetInstance()->SetViewPort(0, 0, width, height);
}

One::Window::Window(const std::string &name, int width, int height) : Window(name, width, height, Graphics::API::GL3)
{}

One::Window::~Window()
{
	glfwDestroyWindow(m_WindowImpl);
	glfwTerminate();
	delete m_Context;
}

bool One::Window::ShouldClose()
{
	return glfwWindowShouldClose(m_WindowImpl);
}

void One::Window::SwapBuffers()
{
	m_Context->SwapBuffers();
}

void One::Window::MarkShouldClose(bool value)
{
	glfwSetWindowShouldClose(m_WindowImpl, true);
}

void One::Window::Clear()
{
	Graphics::Commands::GetInstance(Graphics::API::GL3)->Clear(0.2f, 0.3f, 0.3f);
}

void One::Window::Clear(float r, float g, float b)
{
	Graphics::Commands::GetInstance(Graphics::API::GL3)->Clear(r, g, b);
}

One::Window::window_impl &One::Window::GetWindowImpl()
{
	return m_WindowImpl;
}

void One::Window::PollEvents()
{
	glfwPollEvents();
}

void One::Window::InitGraphics(One::Graphics::API api)
{
	switch (api)
	{
		case Graphics::API::GL3:
			m_Context = new One::Graphics::GL3::GL3Context(this);
			Graphics::GraphicsFactory::GetInstance(Graphics::API::GL3);
			Graphics::Commands::GetInstance(Graphics::API::GL3);
			m_Context->InitializeContext();
			break;
		case Graphics::API::Vulkan:
			break;
	}
}
