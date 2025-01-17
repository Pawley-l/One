#ifndef ONE_WINDOW_H
#define ONE_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>
#include <memory>
#include <functional>
#include <Graphics/Context.h>
#include <Graphics/Types.h>
#include <One.h>

namespace One
{
	class BaseRenderer;

	/**
	 * Window class which is a wrapper around GLFWWindow to make it clean and convenient
	 */
	class Window
	{
	private:
		// Typedef to make it easier to change in future
		typedef GLFWwindow *window_impl;
		friend One::Context;

		window_impl m_WindowImpl{};
		Context *m_Context{};

		std::string m_Title;
		u32 m_Width;
		u32 m_Height;


		double m_PreviousFrame = 0;
		int m_FrameCount = 0;

	private:
		std::function<void()> m_InputCallback;

		void InitGraphics(GraphicsAPI api);

	public:

		/**
		 * Initializes a window and awaits to be started
		 * @param name - Name of the window
		 * @param width - Window Width
		 * @param height - Window height
		 */
		Window(std::string name, u32 width, u32 height);

		~Window();

		/**
		 * Starts the window with the renderer
		 * @param renderer
		 */
		void Start(BaseRenderer &renderer, bool fullscreen = false);

		/**
		 * Returns true if the window should close
		 * @return bool
		 */
		bool ShouldClose();

		/**
		 * Tells the window to close on the next call of ShouldCLose()
		 * @param value - used to override
		 */
		void MarkShouldClose(bool value = true);

		/**
		 * Swaps the buffer of the window
		 */
		void SwapBuffers();

		/**
		 * Clears the screen with the default screen clear colour
		 */
		static void Clear();

		/**
		 * Clears the screen with the input colour
		 * @param r - Red
		 * @param g - Green
		 * @param b - Blue
		 */
		static void Clear(float r, float g, float b);

		/**
		 * Polls the window events
		 */
		static void PollEvents();

		/**
		 * Gets the window implementation
		 * @return window_impl&
		 */
		window_impl &GetWindowImpl();

		/**
		 *
		 * @return
		 */
		u32 GetWindowWidth();

		/**
		 *
		 * @return
		 */
		u32 GetWindowHeight();
	};
}

#endif //ONE_WINDOW_H
