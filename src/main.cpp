#include <GL/glew.h>
#include <Window/Window.h>
#include <Graphics/GraphicsFactory.h>

int main()
{
	One::Window window("window", 1280, 720);

	auto program = One::Graphics::shader_program_ptr (GRAPHICS_FACTORY->CreateShaderProgram());

	auto vertex =
		One::Graphics::shader_ptr (GRAPHICS_FACTORY->CreateShader(One::Graphics::Shaders::Vertex));

	auto fragment =
		One::Graphics::shader_ptr (GRAPHICS_FACTORY->CreateShader(One::Graphics::Shaders::Fragment));


	vertex->LoadFromFile("../vertex.glsl");
	fragment->LoadFromFile("../fragment.glsl");

	program->AttachShader(*vertex);
	program->AttachShader(*fragment);
	program->LinkProgram();
	program->Use();


	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left
		0.5f, -0.5f, 0.0f, // right
		0.0f,  0.5f, 0.0f  // top
	};


	auto bufferarray = One::Graphics::vertex_array_ptr
		(GRAPHICS_FACTORY->CreateBufferArray());

	bufferarray->Bind();

	auto buffer = One::Graphics::vertex_buffer_ptr
	        (GRAPHICS_FACTORY->CreateVertexBuffer(vertices,  sizeof(vertices)));


	bufferarray->AddAttribute(3, One::Graphics::ShaderTypes::Float, 3 * sizeof(float), 0);
	buffer->Unbind();

	while (!window.ShouldClose())
	{
		window.PollEvents();
		window.Clear();

		program->Use();
		bufferarray->Bind();
		glDrawArrays(GL_TRIANGLES, 0, 3);

		window.SwapBuffers();
	}
	return 0;
}