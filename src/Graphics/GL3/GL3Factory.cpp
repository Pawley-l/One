#include <Graphics/GL3/GL3Factory.h>
#include <Graphics/GL3/GL3.h>
#include <Graphics/GL3/Texture/GL3Texture2D.h>

One::Graphics::GL3::GL3Factory::GL3Factory()
= default;

One::Graphics::IndexBuffer*
One::Graphics::GL3::GL3Factory::CreateIndexBuffer(u32 *indices, u32 size)
{
	auto* buffer = new One::Graphics::GL3::GL3IndexBuffer();
	buffer->Initialize(indices, size);
	return buffer;
}

One::Graphics::VertexBuffer *One::Graphics::GL3::GL3Factory::CreateVertexBuffer(float *vertices, u32 size)
{
	auto* buffer = new One::Graphics::GL3::GL3VertexBuffer();
	buffer->Initialize(vertices, size);
	return buffer;
}

One::Graphics::Shader *One::Graphics::GL3::GL3Factory::CreateShader(One::Graphics::Shaders shader)
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

One::Graphics::ShaderProgram *One::Graphics::GL3::GL3Factory::CreateShaderProgram()
{
	return new One::Graphics::GL3::GL3ShaderProgram();
}

One::Graphics::VertexArray *One::Graphics::GL3::GL3Factory::CreateBufferArray()
{
	auto* array = new One::Graphics::GL3::GL3VertexBufferArray();
	array->Initialize();
	return array;
}

One::Graphics::Texture *
One::Graphics::GL3::GL3Factory::CreateTexture2D(One::Graphics::TextureTypes type, const std::string &file)
{
	Texture* texture;
	switch (type)
	{
		case TextureTypes::Texture2D:
			texture = new GL3Texture2D();
	}
	texture->LoadFromFile(file);
	return texture;
}
