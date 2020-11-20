#include <Renderer/Renderer2D.h>
#include <Graphics/GraphicsFactory.h>
#include <Graphics/Commands.h>
#include <Graphics/Types.h>
#include <cstring>
#include <utility>

namespace One
{
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec4 Colour;
		glm::vec2 TextureCoordinates;
		float Texture;
	};

	template<typename T, int size>
	static std::array<T, size> generate_indices()
	{
		std::array<T, size> array{};

		int offset = 0;
		for (int i = 0; i < size; i += 6) {
			array[i] = offset + 0;
			array[i + 1] = offset + 1;
			array[i + 2] = offset + 3;

			array[i + 3] = offset + 1;
			array[i + 4] = offset + 2;
			array[i + 5] = offset + 3;

			offset += 4;
		}

		return array;
	}

	static std::array<Vertex, 4> CreateQuad(float x, float y, float size, u32 id)
	{
		Vertex v1{};
		v1.Position = {x, y, 0.f};
		v1.Colour = {0.1f, 0.3f, 0.7f, 1.f};
		v1.TextureCoordinates = {0.f, 0.f};
		v1.Texture = id;

		Vertex v2{};
		v2.Position = {x + size, y, 0.f};
		v2.Colour = {0.1f, 0.3f, 0.7f, 1.f};
		v2.TextureCoordinates = {1.f, 0.f};
		v2.Texture = id;

		Vertex v3{};
		v3.Position = {x + size, y + size, 0.f};
		v3.Colour = {0.1f, 0.3f, 0.7f, 1.f};
		v3.TextureCoordinates = {1.f, 1.f};
		v3.Texture = id;

		Vertex v4{};
		v4.Position = {x, y + size, 0.f};
		v4.Colour = {0.1f, 0.3f, 0.7f, 1.f};
		v4.TextureCoordinates = {0.f, 1.f};
		v4.Texture = id;

		return {v1, v2, v3, v4};
	}

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
}


One::Renderer2D::Renderer2D()
{
//	auto quad = CreateQuad(10, 10, 100, 0);
	auto ind = generate_indices<u32, 1000>();

//	Vertex vertices[4];

	u32 indices[1000];

	memcpy(indices, ind.data(), ind.size() * sizeof(u32));
//	memcpy(vertices, quad.data(), quad.size() * sizeof(Vertex));

	m_VertexArray = GRAPHICS_FACTORY.CreateBufferArray();
	m_VertexBuffer = GRAPHICS_FACTORY.CreateVertexBuffer(nullptr, sizeof(Vertex) * 1000, DrawStrategy::Dynamic);
	m_IndexBuffer = GRAPHICS_FACTORY.CreateIndexBuffer(indices, sizeof(indices), DrawStrategy::Dynamic);
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
	RenderResource2D resource{};
	resource.type = RenderResource2D::ResourceType::Shape;
	resource.id = m_ShapeIndex;

	auto quad = One::CreateQuad(0, 0, 10, 0);

	Vertex shape_vertex[4];
	memcpy(shape_vertex, quad.data(), quad.size() * sizeof(Vertex));

	m_VertexBuffer->SubData(m_ShapeIndex * sizeof(shape_vertex), sizeof(shape_vertex), shape_vertex);

	m_ShapeIndex++;

	return resource;
}

void One::Renderer2D::ShapePosition(One::RenderResource2D resource, float x, float y)
{
	auto quad = One::CreateQuad(x, y, 10, 0);

	Vertex shape_vertex[4];
	memcpy(shape_vertex, quad.data(), quad.size() * sizeof(Vertex));

	m_VertexBuffer->SubData(resource.id * sizeof(shape_vertex), sizeof(shape_vertex), shape_vertex);
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

void One::Renderer2D::BeginBatch(std::shared_ptr<Camera> camera, std::shared_ptr<ShaderProgram> shader)
{
	m_Camera = std::move(camera);
	m_Shader = std::move(shader);
	m_ProjectionMatrix = m_Camera->GetProjection(1280, 720);
	m_ViewMatrix = m_Camera->GetView();
}

//void One::Renderer2D::DrawShape(One::RenderResource2D &resource, One::RenderResource2D &texture)
//{
//	if (resource.type != RenderResource2D::Shape || texture.type != RenderResource2D::Texture)
//		throw GraphicsFunctionError();
//
//}

void One::Renderer2D::EndBatch()
{
	throw NotImplementedException();
}

void One::Renderer2D::FlushBatch()
{
	glm::mat4 model = glm::mat4(1.0f);

	m_Shader->Use();
	m_Shader->AddUniformMat4x4("view", m_ViewMatrix);
	m_Shader->AddUniformMat4x4("projection", m_ProjectionMatrix);
	m_Shader->AddUniformMat4x4("model", model);
	GRAPHICS_COMMANDS->DrawElements(m_VertexArray, m_VertexArray->GetPrimitive());
}

void One::Renderer2D::SwapBuffer()
{
	throw NotImplementedException();
}

void One::Renderer2D::ClearBuffer()
{
	GRAPHICS_COMMANDS->Clear(0, 0, 0);
}
