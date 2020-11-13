#include <Renderer/2D/Canvas.h>

One::Canvas::Canvas()
= default;

void One::Canvas::SetTexture(const One::Texture &texture)
{

}

void One::Canvas::SetColour(float r, float g, float b)
{
	m_CanvasColour = {r, g, b};
}
