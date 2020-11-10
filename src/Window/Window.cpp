#include <Window/Window.h>
#include <iostream>
#include <Graphics/GL3/GL3Context.h>
#include <Graphics/Commands.h>

void window_size_callback(GLFWwindow* window, int width, int height)
{
	One::Graphics::Commands::GetInstance()->SetViewPort(0, 0, width, height);
}

One::Window::Window(const std::string &name, u32 width, u32 height, Graphics::API api) : m_GraphicsApi(api)
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
	glfwSetWindowSizeCallback(m_WindowImpl, window_size_callback);
}

One::Window::Window(const std::string &name, u32 width, u32 height) : Window(name, width, height, Graphics::API::GL3)
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
	Graphics::Commands::GetInstance()->Clear(0.2f, 0.3f, 0.3f);
}

void One::Window::Clear(float r, float g, float b)
{
	Graphics::Commands::GetInstance()->Clear(r, g, b);
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
			Graphics::Commands::GetInstanceInitialize(Graphics::API::GL3);
			m_Context->InitializeContext();
			break;
		case Graphics::API::Vulkan:
			break;
		case Graphics::API::GL2:
			break;
	}
}

u32 One::Window::GetWindowWidth()
{
	int width, height;
	glfwGetWindowSize(m_WindowImpl, &width, &height);

	return width;
}

u32 One::Window::GetWindowHeight()
{
	int width, height;
	glfwGetWindowSize(m_WindowImpl, &width, &height);

	return height;
}
