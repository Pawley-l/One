#include <One.h>
#include <Window/Window.h>
#include <Graphics/GraphicsFactory.h>
#include <Graphics/Commands.h>
#include <Renderer/BaseRenderer.h>
#include <Application/InputManager.h>
#include <glm/glm.hpp>

int main()
{
	// ugly
	auto window = std::make_shared<One::Window>("window", 1280, 720);
	One::Renderer::BaseRenderer renderer(One::Graphics::API::GL3);

	window->Start(renderer);
	renderer.InitializeDevice();
	renderer.AttachWindow(window);


	while (!window->ShouldClose())
	{
		window->PollEvents();
		window->Clear();

		window->SwapBuffers();
	}
	return 0;
}