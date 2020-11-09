#include <Graphics/GraphicsFactory.h>
#include <Graphics/GL3/GL3.h>

std::unique_ptr<One::Graphics::GraphicsFactory> One::Graphics::GraphicsFactory::m_Instance;

std::unique_ptr<One::Graphics::GraphicsFactory> &One::Graphics::GraphicsFactory::GetInstance(One::Graphics::API api)
{
	if (m_Instance == nullptr)
	{
		switch (api)
		{
			case API::GL3:
				m_Instance = std::unique_ptr<GraphicsFactory>(new GL3GraphicsFactory());
				break;
			case API::Vulkan:
				break;
		}

	}

	return m_Instance;
}

One::Graphics::GL3GraphicsFactory::GL3GraphicsFactory()
= default;

One::Graphics::IndexBuffer*
One::Graphics::GL3GraphicsFactory::CreateIndexBuffer(unsigned int *indices, unsigned int size)
{
	auto* buffer = new One::Graphics::GL3::GL3IndexBuffer();
	buffer->Initialize(indices, size);
	return buffer;
}

One::Graphics::VertexBuffer *One::Graphics::GL3GraphicsFactory::CreateVertexBuffer(float *vertices, unsigned int size)
{
	auto* buffer = new One::Graphics::GL3::GL3VertexBuffer();
	buffer->Initialize(vertices, size);
	return buffer;
}

One::Graphics::Shader *One::Graphics::GL3GraphicsFactory::CreateShader(One::Graphics::Shaders shader)
{
	switch (shader)
	{
		case Shaders::Vertex:
			return new Graphics::GL3::GL3VertexShader();
		case Shaders::Fragment:
			return new Graphics::GL3::GL3FragmentShader();;
		case Shaders::Geometry:
			return nullptr;
	}
	return nullptr;
}

One::Graphics::ShaderProgram *One::Graphics::GL3GraphicsFactory::CreateShaderProgram()
{
	return new One::Graphics::GL3::GL3ShaderProgram();
}

One::Graphics::VertexBufferArray *One::Graphics::GL3GraphicsFactory::CreateBufferArray()
{
	auto* array = new One::Graphics::GL3::GL3VertexBufferArray();
	array->Initialize();
	return array;
}

One::Graphics::Features One::Graphics::GL3GraphicsFactory::GetFeatures()
{
	return {
		true
	};
}
