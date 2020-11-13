#include <Renderer/Renderer2D.h>
#include <Graphics/GraphicsFactory.h>
#include <Graphics/Commands.h>

One::RenderResource2D One::Renderer2D::CreateTexture2D()
{
	auto texture = GRAPHICS_FACTORY.CreateTexture2D(One::TextureTypes::Texture2D, "../test.png");
	u32 id = m_RenderingResourcesTexture.size();
	m_RenderingResourcesTexture.push_back(texture);

	return {id, RenderResource2D::Texture};
}

One::RenderResource2D One::Renderer2D::CreateTexture2D(const std::string &name)
{
	auto texture = GRAPHICS_FACTORY.CreateTexture2D(One::TextureTypes::Texture2D, "../test.png");
	u32 id = m_RenderingResourcesTexture.size();
	texture->LoadFromFile(name);
	m_RenderingResourcesTexture.push_back(texture);

	return {id, RenderResource2D::Texture};
}

One::RenderResource2D One::Renderer2D::CreateTexture2D(const One::Image &image)
{
	auto texture = GRAPHICS_FACTORY.CreateTexture2D(One::TextureTypes::Texture2D, "../test.png");
	u32 id = m_RenderingResourcesTexture.size();
	texture->LoadFromImage(image);
	m_RenderingResourcesTexture.push_back(texture);

	return {id, RenderResource2D::Texture};
}

One::RenderResource2D One::Renderer2D::CreateTexture2D(u32 width, u32 height, const unsigned char *data)
{
	throw NotImplementedException();
}

void One::Renderer2D::LoadTexture2D(One::RenderResource2D &resource, const std::string &name)
{
	m_RenderingResourcesTexture.at(resource.id)->LoadFromFile(name);
}

One::RenderResource2D One::Renderer2D::CreateShape(One::Shapes shape)
{
	throw NotImplementedException();
}

void One::Renderer2D::ShapeMove(One::RenderResource2D resource, float x, float y)
{
	throw NotImplementedException();
}

void One::Renderer2D::ShapeRotate(One::RenderResource2D resource, float by)
{
	throw NotImplementedException();
}

void One::Renderer2D::ShapeScale(One::RenderResource2D resource, float by)
{
	throw NotImplementedException();
}

void One::Renderer2D::SetCanvasColour(float r, float g, float b, float a)
{
	m_Canvas.SetColour(r, g, b);
}

void One::Renderer2D::SetCanvasTexture2D(One::RenderResource2D &resource)
{
	throw NotImplementedException();
}

void One::Renderer2D::BeginBatch()
{
	throw NotImplementedException();
}

void One::Renderer2D::DrawShape(One::RenderResource2D &resource, One::RenderResource2D &texture)
{
	if (resource.type != RenderResource2D::Shape || texture.type != RenderResource2D::Texture)
		throw GraphicsFunctionError();


}

void One::Renderer2D::EndBatch()
{
	throw NotImplementedException();
}

void One::Renderer2D::FlushBatch()
{
	throw NotImplementedException();
}
