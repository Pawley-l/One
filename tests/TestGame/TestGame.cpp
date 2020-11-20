#include <Graphics/GraphicsFactory.h>
#include <Graphics/Commands.h>
#include <Application/InputManager.h>
#include <Renderer/2D/OrthographicCamera.h>
#include <cstring>

#include "TestGame.h"

oneIMPLEMENT_APP(TestGame)

struct Vertex
{
	glm::vec3 Position;
	glm::vec4 Colour;
	glm::vec2 TextureCoordinates;
	float Texture;
};

template<int size>
static std::array<u32, size> generate_indices()
{
	std::array<u32, size> array{};

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
	v1.Colour = {1.1f, 0.3f, 0.7f, 1.f};
	v1.TextureCoordinates = {0.f, 0.f};
	v1.Texture = id;

	Vertex v2{};
	v2.Position = {x + size, y, 0.f};
	v2.Colour = {1.1f, 0.3f, 0.7f, 1.f};
	v2.TextureCoordinates = {1.f, 0.f};
	v2.Texture = id;

	Vertex v3{};
	v3.Position = {x + size, y + size, 0.f};
	v3.Colour = {1.1f, 0.3f, 0.7f, 1.f};
	v3.TextureCoordinates = {1.f, 1.f};
	v3.Texture = id;

	Vertex v4{};
	v4.Position = {x, y + size, 0.f};
	v4.Colour = {1.1f, 0.3f, 0.7f, 1.f};
	v4.TextureCoordinates = {0.f, 1.f};
	v4.Texture = id;

	return {v1, v2, v3, v4};
}


void TestGame::Startup()
{
	u32 _indices[1000];
	auto in = generate_indices<1000>();
	memcpy(_indices, in.data(), in.size() * sizeof(u32));

	m_Camera = std::make_shared<One::OrthographicCamera>();

	m_ShaderProgram = GRAPHICS_COMMANDS->GetFactory().CreateShaderProgram();
	m_VertexBuffer = GRAPHICS_FACTORY.CreateVertexBuffer(nullptr, sizeof(Vertex) * 1000,
	                                                     One::DrawStrategy::Dynamic);
	m_IndexBuffer = GRAPHICS_FACTORY.CreateIndexBuffer(_indices, sizeof(_indices), One::DrawStrategy::Dynamic);
	m_VertexArray = GRAPHICS_FACTORY.CreateBufferArray();

	auto vertex = One::shader_ptr(GRAPHICS_COMMANDS->GetFactory().CreateShader(One::Shaders::Vertex));
	auto fragment = One::shader_ptr(GRAPHICS_COMMANDS->GetFactory().CreateShader(One::Shaders::Fragment));

	vertex->LoadFromString(R"(
	#version 330 core
	layout (location = 0) in vec3 a_Position;
	layout (location = 1) in vec4 a_Colour;
	layout (location = 2) in vec2 a_TexCoord;
	layout (location = 3) in float a_Tex;

	uniform mat4 model;
	uniform mat4 view;
	uniform mat4 projection;

	out vec4 o_Colour;
	out vec2 o_TexCoord;

	void main()
	{
	    gl_Position = projection * view * model * vec4(a_Position, 1.0f);
	    o_Colour = a_Colour;
	    o_TexCoord = a_TexCoord;
	}
	)");
	fragment->LoadFromString(R"(
	#version 330 core
	out vec4 FragColor;

	in vec4 o_Colour;
	in vec2 o_TexCoord;

	uniform sampler2D u_Texture;

	void main()
	{
	    FragColor = texture(u_Texture, o_TexCoord) * o_Colour;
	}
	)");

	m_ShaderProgram->AttachShader(*vertex);
	m_ShaderProgram->AttachShader(*fragment);
	m_ShaderProgram->LinkProgram();

	m_VertexArray->AddAttribute(3, One::ShaderTypes::Float, sizeof(Vertex),
	                            0, false);

	m_VertexArray->AddAttribute(4, One::ShaderTypes::Float, sizeof(Vertex),
	                            offsetof(Vertex, Colour), false);

	m_VertexArray->AddAttribute(2, One::ShaderTypes::Float, sizeof(Vertex),
	                            offsetof(Vertex, TextureCoordinates), false);

	m_VertexArray->AddAttribute(1, One::ShaderTypes::Float, sizeof(Vertex),
	                            offsetof(Vertex, Texture), false);

	m_Texture = One::texture_ptr(GRAPHICS_FACTORY.CreateTexture2D(
		One::TextureTypes::Texture2D, "../test2.png"));

	m_VertexArray->Add(m_VertexBuffer);
	m_VertexArray->Add(m_IndexBuffer);
	m_VertexArray->Add(m_Texture);
	m_VertexArray->SetPrimitive(One::Primitives::Triangles);
}

void TestGame::ProcessFrame()
{
	float cameraSpeed = 2.5 * 0.01;
//	if (One::InputManager::IsKeyHeld(GLFW_KEY_W))
//		cameraPos += cameraSpeed * cameraFront;
//	if (One::InputManager::IsKeyHeld(GLFW_KEY_S))
//		cameraPos -= cameraSpeed * cameraFront;
//	if (One::InputManager::IsKeyHeld(GLFW_KEY_A))
//		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//	if (One::InputManager::IsKeyHeld(GLFW_KEY_D))
//		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

	if (One::InputManager::IsKeyHeld(GLFW_KEY_W))
		y += 10;
	if (One::InputManager::IsKeyHeld(GLFW_KEY_S))
		y -= 10;
	if (One::InputManager::IsKeyHeld(GLFW_KEY_A))
		x -= 10;
	if (One::InputManager::IsKeyHeld(GLFW_KEY_D))
		x += 10;

	auto quad = CreateQuad(x, y, 100, 0);

	Vertex vertex[4];
	memcpy(vertex, quad.data(), quad.size() * sizeof(Vertex));

	m_VertexBuffer->SubData(0, sizeof(vertex), vertex);

	renderer->SceneBegin(m_Camera, m_ShaderProgram);
	renderer->Draw(m_VertexArray);
	renderer->SceneEnd();

	renderer->Flush();
}





