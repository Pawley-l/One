#include <Graphics/GL3/Buffers/GL3IndexBuffer.h>

void One::Graphics::GL3::GL3IndexBuffer::Initialize(unsigned int *indices, unsigned int size)
{
	m_Count = size / sizeof(unsigned int);
	glGenBuffers(1, &m_BufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void One::Graphics::GL3::GL3IndexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
}

void One::Graphics::GL3::GL3IndexBuffer::Unbind() const
{
	glBindBuffer(1, m_BufferID);
}

One::Graphics::GL3::GL3IndexBuffer::~GL3IndexBuffer()
{
	glDeleteBuffers(1, &m_BufferID);
}

unsigned int One::Graphics::GL3::GL3IndexBuffer::GetCount()
{
	return m_Count;
}
