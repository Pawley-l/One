#include <Window/Window.h>
#include <iostream>
#include <utility>
#include <Graphics/OpenGL3/GL3Context.h>
#include <Graphics/Commands.h>
#include <Renderer/BaseRenderer.h>
#include <Application/InputManager.h>

void window_size_callback(GLFWwindow* window, int width, int height)
{
	One::Commands::GetInstance()->SetViewPort(0, 0, width, height);
}

One::Window::Window(std::string name, u32 width, u32 height) : m_Title(std::move(name)), m_Width(width), m_Height(height)
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
	Commands::GetInstance()->Clear(0.2f, 0.3f, 0.3f);
}

void One::Window::Clear(float r, float g, float b)
{
	Commands::GetInstance()->Clear(r, g, b);
}

One::Window::window_impl &One::Window::GetWindowImpl()
{
	return m_WindowImpl;
}

void One::Window::PollEvents()
{
	glfwPollEvents();
}

void One::Window::InitGraphics(One::GraphicsAPI api)
{
	switch (api) {
		case GraphicsAPI::GL3:
			m_Context = new One::GL3::GL3Context(this);
			Commands::GetInstanceInitialize(GraphicsAPI::GL3);
			m_Context->InitializeContext();
			break;
		case GraphicsAPI::Vulkan:
			break;
		case GraphicsAPI::GL2:
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

void One::Window::Start(One::BaseRenderer &renderer)
{
	glfwInit();
	m_WindowImpl = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);

	if (m_WindowImpl == nullptr) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	InitGraphics(renderer.GetCurrentDevice().GPU.GraphicsAPI);
	glfwSwapInterval(1);

	Commands::GetInstance()->SetViewPort(0, 0, m_Width, m_Height);
	glfwSetWindowSizeCallback(m_WindowImpl, window_size_callback);

	glfwSetKeyCallback(m_WindowImpl, reinterpret_cast<GLFWkeyfun>(InputManager::key_callback));
	glfwSetMouseButtonCallback(m_WindowImpl,
	                           reinterpret_cast<GLFWmousebuttonfun>(InputManager::mouse_button_callback));
}
