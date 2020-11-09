#include <Graphics/GL3/GL3Commands.h>
#include <GL/glew.h>

One::Graphics::GL3::GL3Commands::GL3Commands()
{

}

void
One::Graphics::GL3::GL3Commands::SetViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
	glViewport(x, y, width, height);
}

void One::Graphics::GL3::GL3Commands::Clear(float r, float g, float b)
{
	glClearColor(r, g, b, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
