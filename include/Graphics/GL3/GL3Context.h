#ifndef ONE_GL3CONTEXT_H
#define ONE_GL3CONTEXT_H

#include <Graphics/Context.h>
#include <Window/Window.h>

namespace One::Graphics::GL3
{
	class GL3Context : public  One::Graphics::Context
	{
	private:
		Window* m_Window;

	public:
		explicit GL3Context(Window* window);

		void InitializeContext() override;

		void SwapBuffers() override;

	};
}

#endif //ONE_GL3CONTEXT_H
