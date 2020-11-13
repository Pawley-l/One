#include <Graphics/OpenGL3/GL3Context.h>
#include <GLFW/glfw3.h>
#include <GL/glew.h>
#include <cstdio>

void One::GL3::GL3Context::InitializeContext()
{
	glfwMakeContextCurrent(m_Window->GetWindowImpl());

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
}

void One::GL3::GL3Context::SwapBuffers()
{
	glfwSwapBuffers(m_Window->GetWindowImpl());
}

One::GL3::GL3Context::GL3Context(One::Window *window)
{
	this->m_Window = window;
}