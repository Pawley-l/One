#include <Graphics/GL3/GL3IndexBuffer.h>
#include <Graphics/GL3/GL3Functions.h>
#include <iostream>

void One::GL3::GL3IndexBuffer::Initialize(u32 *indices, u32 size, DrawStrategy strategy)
{
	Functions::GenBuffers(1, &m_BufferID);
	Functions::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
	Functions::BufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, strategy);

	m_Count = size / sizeof(u32);
	Functions::BindBuffer(1, m_BufferID);
}

void One::GL3::GL3IndexBuffer::Bind() const
{
	Functions::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
}

void One::GL3::GL3IndexBuffer::Unbind() const
{
	Functions::BindBuffer(1, m_BufferID);
}

One::GL3::GL3IndexBuffer::~GL3IndexBuffer()
{
	Functions::DeleteBuffers(1, &m_BufferID);
}

unsigned int One::GL3::GL3IndexBuffer::GetCount()
{
	return m_Count;
}
