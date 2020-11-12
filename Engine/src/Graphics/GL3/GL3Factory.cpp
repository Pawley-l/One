#include <Graphics/GL3/GL3Factory.h>
#include <Graphics/GL3/GL3.h>
#include <Graphics/GL3/GL3Texture2D.h>
#include <memory>

One::GL3::GL3Factory::GL3Factory()
= default;

std::shared_ptr<One::IndexBuffer>
One::GL3::GL3Factory::CreateIndexBuffer(u32 *indices, u32 size, DrawStrategy strategy)
{
	auto buffer = std::shared_ptr<One::IndexBuffer>(new GL3IndexBuffer());
	buffer->Initialize(indices, size, strategy);
	return buffer;
}

std::shared_ptr<One::VertexBuffer> One::GL3::GL3Factory::CreateVertexBuffer(float *vertices,
                                                                            u32 size,
                                                                            DrawStrategy strategy)
{
	auto buffer = std::shared_ptr<One::VertexBuffer>(new GL3VertexBuffer());
	buffer->Initialize(vertices, size, strategy);
	return buffer;
}

std::shared_ptr<One::Shader> One::GL3::GL3Factory::CreateShader(One::Shaders shader)
{
	switch (shader) {
		case Shaders::Vertex:
			return std::shared_ptr<One::Shader>(new GL3VertexShader());
		case Shaders::Fragment:
			return std::shared_ptr<One::Shader>(new GL3FragmentShader());
		case Shaders::Geometry:
			return nullptr;
	}
	return nullptr;
}

std::shared_ptr<One::ShaderProgram> One::GL3::GL3Factory::CreateShaderProgram()
{
	return std::shared_ptr<One::ShaderProgram>(new GL3ShaderProgram());
}

std::shared_ptr<One::VertexArray> One::GL3::GL3Factory::CreateBufferArray()
{
	auto array = std::shared_ptr<One::VertexArray>(new GL3BufferArray());
	array->Initialize();
	return array;
}

std::shared_ptr<One::Texture>
One::GL3::GL3Factory::CreateTexture2D(One::TextureTypes type, const std::string &file)
{
	auto texture = std::shared_ptr<One::Texture>(new GL3Texture2D());
	texture->LoadFromFile(file);
	return texture;
}
