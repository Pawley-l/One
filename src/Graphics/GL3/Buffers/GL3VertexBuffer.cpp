#include <Graphics/GL3/Buffers/GL3VertexBuffer.h>

void One::Graphics::GL3::GL3VertexBuffer::Initialize(float *vertices, unsigned int size)
{
	glGenBuffers(1, &m_BufferID);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void One::Graphics::GL3::GL3VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
}

void One::Graphics::GL3::GL3VertexBuffer::Unbind() const
{
	glBindBuffer(1, m_BufferID);
}

One::Graphics::GL3::GL3VertexBuffer::~GL3VertexBuffer()
{
	glDeleteBuffers(1, &m_BufferID);
}
