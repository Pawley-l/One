#include <Renderer/Orth/Base2DRenderer.h>
#include <Graphics/Commands.h>
#include <glm/gtc/matrix_transform.hpp>

float square[] = {
	// positions          // colors           // texture coords
	0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
	0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
	-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
	-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // top left
};

u32 indices[] = {  // note that we start from 0!
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
};

One::Renderer::Orth::Shape One::Renderer::Orth::Base2DRenderer::CreateShape
	(One::Renderer::Orth::Shape::ShapeType shapetype)
{
	Shape shape;
	u32 id = -1;

	One::Graphics::vertex_buffer_ptr m_VertexBuffer;
	auto m_IndexBuffer = One::Graphics::index_buffer_ptr(
		GRAPHICS_FACTORY.CreateIndexBuffer(indices, sizeof(indices), Graphics::DrawStrategy::Dynamic));
	auto m_VertexArray = One::Graphics::vertex_array_ptr(GRAPHICS_FACTORY.CreateBufferArray());

	switch (shape.Shape) {
		case Shape::ShapeType::None:
			break;
		case Shape::ShapeType::Quad:
			m_VertexBuffer = One::Graphics::vertex_buffer_ptr
				(GRAPHICS_FACTORY.CreateVertexBuffer(square, sizeof(square),
				                                     Graphics::DrawStrategy::Dynamic));
			break;
	}

	m_VertexArray->AddAttribute(3, One::Graphics::ShaderTypes::Float, 8 * sizeof(float),
	                            0, false);
	m_VertexArray->AddAttribute(3, One::Graphics::ShaderTypes::Float, 8 * sizeof(float),
	                            3 * sizeof(float), false);
	m_VertexArray->AddAttribute(2, One::Graphics::ShaderTypes::Float, 8 * sizeof(float),
	                            6 * sizeof(float), false);

	m_VertexArray->Add(m_VertexBuffer);
	m_VertexArray->Add(m_IndexBuffer);
	m_VertexArray->SetPrimitive(One::Graphics::Primitives::Triangles);

	shape.ID = m_VertexArrays.size();

	m_VertexArrays.push_back(m_VertexArray);

	shape.Shape = shapetype;
	return shape;
}

u32 One::Renderer::Orth::Base2DRenderer::CreateTexture(const std::string &file)
{
	u32 size = m_Textures.size();
	auto texture = One::Graphics::texture_ptr(GRAPHICS_FACTORY.CreateTexture2D(
		One::Graphics::TextureTypes::Texture2D, file));
	m_Textures.push_back(texture);
	return size;
}

void One::Renderer::Orth::Base2DRenderer::SceneBegin(const std::shared_ptr<OrthographicCamera> &camera)
{
	m_ProjectionMatrix = camera->GetProjection(m_AttachedWindow->GetWindowWidth(),
	                                           m_AttachedWindow->GetWindowHeight());
	m_ViewMatrix = camera->GetView();
	m_InScene = true;
}

void One::Renderer::Orth::Base2DRenderer::Draw(One::Renderer::Orth::Shape shape)
{
	m_RendererQueue.push(shape);
}

void One::Renderer::Orth::Base2DRenderer::Flush()
{
	//BaseRenderer::Flush();

	while (!m_RendererQueue.empty()) {
		auto shape = m_RendererQueue.front();

		glm::mat4 model = shape.Transform.GetModel();
		model = glm::scale(model, glm::vec3(100.0f, 100.0f, 0.0f));

		m_CurrentShader->Use();
		m_CurrentShader->AddUniformMat4x4("view", m_ViewMatrix);
		m_CurrentShader->AddUniformMat4x4("projection", m_ProjectionMatrix);
		m_CurrentShader->AddUniformMat4x4("model", model);

		m_Textures[shape.TextureID]->Bind(0);

		GRAPHICS_COMMANDS->DrawElements(m_VertexArrays[shape.ID], m_VertexArrays[shape.ID]->GetPrimitive());
		m_RendererQueue.pop();
	}
}

One::Renderer::Orth::Base2DRenderer::Base2DRenderer(Graphics::API api) : BaseRenderer(api)
{
}

void One::Renderer::Orth::Base2DRenderer::Initialize()
{
	m_CurrentShader = One::Graphics::shader_program_ptr(GRAPHICS_COMMANDS->GetFactory().CreateShaderProgram());

	auto vertex =
		One::Graphics::shader_ptr(GRAPHICS_COMMANDS->GetFactory().CreateShader(One::Graphics::Shaders::Vertex));

	auto fragment =
		One::Graphics::shader_ptr(
			GRAPHICS_COMMANDS->GetFactory().CreateShader(One::Graphics::Shaders::Fragment));

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

	m_CurrentShader->AttachShader(*vertex);
	m_CurrentShader->AttachShader(*fragment);
	m_CurrentShader->LinkProgram();
}
