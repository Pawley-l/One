#include <Graphics/GraphicsFactory.h>
#include <Graphics/Commands.h>
#include <Application/InputManager.h>
#include <Renderer/2D/OrthographicCamera.h>
#include <cstring>
#include <utility>
#include "TestGame.h"

oneIMPLEMENT_APP(TestGame)

void TestGame::Startup()
{
	m_ShaderProgram = GRAPHICS_COMMANDS->GetFactory().CreateShaderProgram();
	m_Camera = std::make_shared<One::OrthographicCamera>();
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

	m_TestRenderer = std::make_shared<One::Renderer2D>();
	shape = m_TestRenderer->CreateShape(One::Shapes::Quad);
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

	m_TestRenderer->ShapePosition(shape, x, y);
	m_TestRenderer->BeginBatch(m_Camera, m_ShaderProgram);
	m_TestRenderer->FlushBatch();
}