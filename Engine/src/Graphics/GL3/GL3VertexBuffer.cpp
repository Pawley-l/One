#include <Graphics/GL3/GL3VertexBuffer.h>
#include <Graphics/GL3/GL3Functions.h>
#include <iostream>

void One::Graphics::GL3::GL3VertexBuffer::Initialize(float *vertices, u32 size)
{
	Functions::GenBuffers(1, &m_BufferID);
	Functions::BindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	Functions::BufferData(GL_ARRAY_BUFFER, size, vertices, DrawStrategy::Static);

	m_BufferSize = size / sizeof(float);
	Functions::BindBuffer(1, m_BufferID);
}

void One::Graphics::GL3::GL3VertexBuffer::Bind() const
{
	Functions::BindBuffer(GL_ARRAY_BUFFER, m_BufferID);
}

void One::Graphics::GL3::GL3VertexBuffer::Unbind() const
{
	Functions::BindBuffer(1, m_BufferID);
}

One::Graphics::GL3::GL3VertexBuffer::~GL3VertexBuffer()
{
	Functions::DeleteBuffers(1, &m_BufferID);
}