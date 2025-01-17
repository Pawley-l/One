#include <Application/Application.h>
#include <iostream>

void One::Application::StartApplication()
{
	window = std::make_shared<One::Window>("Window", 1280, 720);
	renderer = std::make_shared<One::BaseRenderer>(One::GraphicsAPI::GL3);

	window->Start(*renderer);
	renderer->InitializeDevice();
	renderer->AttachWindow(window);

	this->Startup();

	while (!window->ShouldClose()) {
		window->PollEvents();
		window->Clear();

		this->ProcessFrame();

		window->SwapBuffers();
	}
}

One::Application::Application()
= default;
