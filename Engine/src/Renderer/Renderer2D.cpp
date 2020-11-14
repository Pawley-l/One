#include <Renderer/Renderer2D.h>
#include <Graphics/GraphicsFactory.h>
#include <Graphics/Commands.h>
#include <Graphics/Types.h>
#include <cstring>

static std::string vertex(R"(
	#version 330 core
	layout (location = 0) in vec3 aPos;
	layout (location = 1) in vec3 aColor;
	layout (location = 2) in vec2 aTexCoord;

	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

	out vec3 ourColor;
	out vec2 TexCoord;

	void main()
	{
	    gl_Position = projection * view * model * vec4(aPos, 1.0f);
	    ourColor = aColor;
	    TexCoord = aTexCoord;
	}
	)");

static std::string fragment(R"(
	#version 330 core
	out vec4 FragColor;

	in vec3 ourColor;
	in vec2 TexCoord;

	uniform sampler2D ourTexture;

	void main()
	{
	    FragColor = texture(ourTexture, TexCoord);
	}
	)");

//struct Vertex
//{
//	glm::vec3 Position;
//	glm::vec4 Colour;
//	glm::vec2 TextureCoordinates;
//	float Texture;
//};

//template<int size>
//static std::array<Vertex, size> generate_indices()
//{
//	std::array<Vertex, size> array{};
//
//	// Process indices
//
//	return array;
//}
//
//static u32 indices_[] = {  // note that we start from 0!
//	0, 1, 3,   // first triangle
//	1, 2, 3    // second triangle
//};
//
//static std::array<Vertex, 4> CreateQuad(float x, float y, float size, u32 id)
//{
//	Vertex v1{};
//	v1.Position = {x, y, 0.f};
//	v1.Colour = {0.1f, 0.3f, 0.7f, 1.f};
//	v1.TextureCoordinates = {0.f, 0.f };
//	v1.Texture = id;
//
//	Vertex v2{};
//	v2.Position = {x+size, y, 0.f};
//	v2.Colour = {0.1f, 0.3f, 0.7f, 1.f};
//	v2.TextureCoordinates = {1.f, 0.f };
//	v2.Texture = id;
//
//	Vertex v3{};
//	v3.Position = {x+size, y+size, 0.f};
//	v3.Colour = {0.1f, 0.3f, 0.7f, 1.f};
//	v3.TextureCoordinates = {1.f, 1.f };
//	v3.Texture = id;
//
//	Vertex v4{};
//	v4.Position = {x, y+size, 0.f};
//	v4.Colour = {0.1f, 0.3f, 0.7f, 1.f};
//	v4.TextureCoordinates = {0.f, 1.f };
//	v4.Texture = id;
//
//	return {v1, v2, v3, v4};
//}

One::Renderer2D::Renderer2D()
{
//	auto quad = CreateQuad(10, 10, 100, 0);
//	u32 vertices[4];
//
//	memcpy(vertices, quad.data(), quad.size() * sizeof(Vertex));
//
//	m_VertexArray = GRAPHICS_FACTORY.CreateBufferArray();
//	m_VertexBuffer = GRAPHICS_FACTORY.CreateVertexBuffer(nullptr, sizeof(Vertex) * 1000, DrawStrategy::Dynamic);
//	m_IndexBuffer = GRAPHICS_FACTORY.CreateIndexBuffer(indices_, sizeof(indices_), DrawStrategy::Dynamic);
}

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

void One::Renderer2D::SwapBuffer()
{
	throw NotImplementedException();
}

void One::Renderer2D::ClearBuffer()
{
	GRAPHICS_COMMANDS->Clear(0, 0, 0);
}
