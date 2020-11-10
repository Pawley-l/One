#include <Window/Window.h>
#include <Graphics/GraphicsFactory.h>
#include <Graphics/Commands.h>
#include <Renderer/BaseRenderer.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

static glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
static glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
static glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
static std::shared_ptr<One::Renderer::Camera> camera;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main()
{
	auto window = std::make_shared<One::Window>("window", 1280, 720);
	One::Renderer::BaseRenderer renderer;

	renderer.AttachWindow(window);

	glfwSetKeyCallback(window->GetWindowImpl(), key_callback);
	camera = std::make_shared<One::Renderer::Camera>();

	auto program = One::Graphics::shader_program_ptr (GRAPHICS_COMMANDS->GetFactory().CreateShaderProgram());


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

	program->AttachShader(*vertex);
	program->AttachShader(*fragment);
	program->LinkProgram();

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

	auto buffer = One::Graphics::vertex_buffer_ptr (GRAPHICS_FACTORY.CreateVertexBuffer(vertices,
										     sizeof(vertices)));
	auto indexbuffer = One::Graphics::index_buffer_ptr (GRAPHICS_FACTORY.CreateIndexBuffer(indices,
											sizeof(indices)));

	auto buffer_array = One::Graphics::vertex_array_ptr (GRAPHICS_FACTORY.CreateBufferArray());

	buffer_array->AddAttribute(3,One::Graphics::ShaderTypes::Float, 8 * sizeof(float),
			   0, false);
	buffer_array->AddAttribute(3,One::Graphics::ShaderTypes::Float, 8 * sizeof(float),
			   3 * sizeof(float), false);
	buffer_array->AddAttribute(2,One::Graphics::ShaderTypes::Float, 8 * sizeof(float),
			   6 * sizeof(float), false);

	auto texture = One::Graphics::texture_ptr(GRAPHICS_FACTORY.CreateTexture2D(
		One::Graphics::TextureTypes::Texture2D, "../test.png"));

	buffer_array->Add(buffer);
	buffer_array->Add(indexbuffer);
	buffer_array->Add(texture);

	buffer_array->SetPrimitive(One::Graphics::Primitives::Triangles);

	while (!window->ShouldClose())
	{
		window->PollEvents();
		window->Clear();

		renderer.SceneBegin(camera, program);
		renderer.Submit(buffer_array);
		renderer.SceneEnd();

		camera->LookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		renderer.Flush();

		window->SwapBuffers();
	}
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//if (key == GLFW_KEY_E && action == GLFW_PRESS)


	float cameraSpeed = 2.5 * 0.01;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos += cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
}
