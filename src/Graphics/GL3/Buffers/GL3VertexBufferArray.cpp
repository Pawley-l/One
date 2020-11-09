#include <Graphics/GL3/Buffers/GL3VertexBufferArray.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wint-to-void-pointer-cast"

void One::Graphics::GL3::GL3VertexBufferArray::Initialize()
{
	glGenVertexArrays(1, &m_BufferID);
}

void One::Graphics::GL3::GL3VertexBufferArray::Bind() const
{
	glBindVertexArray(m_BufferID);
}

void One::Graphics::GL3::GL3VertexBufferArray::Unbind() const
{
	glBindVertexArray(0);
}

void One::Graphics::GL3::GL3VertexBufferArray::AddAttribute(int size, One::Graphics::ShaderTypes type, int stride,
                                                            unsigned int offset, bool normalized)
{
	Bind();
	switch (type)
	{

		case ShaderTypes::Vec:
			break;
		case ShaderTypes::Vec2:
			break;
		case ShaderTypes::Vec3:
			break;
		case ShaderTypes::Vec4:
			break;
		case ShaderTypes::Mat2:
			break;
		case ShaderTypes::Mat3:
			break;
		case ShaderTypes::Mat4:
			break;
		case ShaderTypes::Float:
			glVertexAttribPointer(m_AttribLocation, size, GL_FLOAT, normalized ? GL_TRUE : GL_FALSE,
			                      stride, (void*)offset);
			glEnableVertexAttribArray(m_AttribLocation);;
		case ShaderTypes::Int:
			glVertexAttribPointer(m_AttribLocation, size, GL_INT, normalized ? GL_TRUE : GL_FALSE,
			                      stride, (void*)offset);
			glEnableVertexAttribArray(m_AttribLocation);;;
	}



	Unbind();
	m_AttribLocation++;
}

void One::Graphics::GL3::GL3VertexBufferArray::Add(One::Graphics::index_buffer_ptr &index_buffer)
{

}

void One::Graphics::GL3::GL3VertexBufferArray::Add(One::Graphics::vertex_buffer_ptr &vertex_buffer)
{

}

One::Graphics::GL3::GL3VertexBufferArray::~GL3VertexBufferArray()
= default;

#pragma clang diagnostic pop