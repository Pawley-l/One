#ifndef ONE_APPLICATION_H
#define ONE_APPLICATION_H

#include <Renderer/BaseRenderer.h>
#include <Window/Window.h>

namespace One
{
	/**
	 * Main Application class to be inherited from
	 */
	class Application
	{
	public:
		Application();

		void StartApplication();

		virtual void Startup() = 0;

		virtual void ProcessFrame() = 0;

	protected:
		std::shared_ptr<BaseRenderer> renderer;
		std::shared_ptr<Window> window;
	};
}

#endif //ONE_APPLICATION_H
