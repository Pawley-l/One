#include <Graphics/GraphicsFactory.h>
#include <Graphics/Commands.h>
#include <Application/InputManager.h>
#include <Renderer/Orth/OrthographicCamera.h>
#include "ProjectOne.h"

oneIMPLEMENT_APP(ProjectOne)

float vertices[] = {
	// positions          // colors           // texture coords
	0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
	0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
	-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left
};
u32 indices[] = {  // note that we start from 0!
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
};

void ProjectOne::Startup()
{
	m_ShaderProgram = One::Graphics::shader_program_ptr (GRAPHICS_COMMANDS->GetFactory().CreateShaderProgram());
	m_Camera = std::make_shared<One::Renderer::Camera>();
	m_VertexBuffer = One::Graphics::vertex_buffer_ptr (GRAPHICS_FACTORY.CreateVertexBuffer(vertices, sizeof(vertices)));
	m_IndexBuffer = One::Graphics::index_buffer_ptr (GRAPHICS_FACTORY.CreateIndexBuffer(indices, sizeof(indices)));
	m_VertexArray = One::Graphics::vertex_array_ptr (GRAPHICS_FACTORY.CreateBufferArray());

	auto vertex =
		One::Graphics::shader_ptr(GRAPHICS_COMMANDS->GetFactory().CreateShader(One::Graphics::Shaders::Vertex));

	auto fragment =
		One::Graphics::shader_ptr(GRAPHICS_COMMANDS->GetFactory().CreateShader(One::Graphics::Shaders::Fragment));

	vertex->LoadFromString(R"(
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
	fragment->LoadFromString(R"(
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

	m_ShaderProgram->AttachShader(*vertex);
	m_ShaderProgram->AttachShader(*fragment);
	m_ShaderProgram->LinkProgram();

	m_VertexArray->AddAttribute(3,One::Graphics::ShaderTypes::Float, 8 * sizeof(float),
	                           0, false);
	m_VertexArray->AddAttribute(3,One::Graphics::ShaderTypes::Float, 8 * sizeof(float),
	                           3 * sizeof(float), false);
	m_VertexArray->AddAttribute(2,One::Graphics::ShaderTypes::Float, 8 * sizeof(float),
	                           6 * sizeof(float), false);

	m_Texture = One::Graphics::texture_ptr(GRAPHICS_FACTORY.CreateTexture2D(
		One::Graphics::TextureTypes::Texture2D, "../test.png"));

	m_VertexArray->Add(m_VertexBuffer);
	m_VertexArray->Add(m_IndexBuffer);
	m_VertexArray->Add(m_Texture);
	m_VertexArray->SetPrimitive(One::Graphics::Primitives::Triangles);
	m_Camera->SetFov(90);
}

void ProjectOne::ProcessFrame()
{
	float cameraSpeed = 2.5 * 0.01;
	if (One::InputManager::IsKeyHeld(GLFW_KEY_W))
		cameraPos += cameraSpeed * cameraFront;
	if (One::InputManager::IsKeyHeld(GLFW_KEY_S))
		cameraPos -= cameraSpeed * cameraFront;
	if (One::InputManager::IsKeyHeld(GLFW_KEY_A))
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (One::InputManager::IsKeyHeld(GLFW_KEY_D))
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

	renderer->SceneBegin(m_Camera, m_ShaderProgram);
	renderer->Draw(m_VertexArray);
	renderer->SceneEnd();

	m_Camera->LookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	renderer->Flush();
}
