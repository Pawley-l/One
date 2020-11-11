#include <Application/Application.h>

void One::Application::StartApplication()
{
	window = std::make_shared<One::Window>("Window", 1280, 720);
	renderer = std::make_shared<One::Renderer::BaseRenderer>(One::Graphics::API::GL3);

	window->Start(*renderer);
	renderer->InitializeDevice();
	renderer->AttachWindow(window);

	this->Startup();

	while (!window->ShouldClose())
	{
		window->PollEvents();
		window->Clear();

		this->ProcessFrame();

		window->SwapBuffers();
	}
}

One::Application::Application()
= default;
