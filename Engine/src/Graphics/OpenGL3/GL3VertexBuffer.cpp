#include <GL/glew.h>
#include <Graphics/OpenGL3/GL3VertexBuffer.h>
#include <Graphics/OpenGL3/GL3Functions.h>

void One::GL3::GL3VertexBuffer::Initialize(float *vertices, u32 size, DrawStrategy strategy)
{
	Functions::GenBuffers(1, &m_BufferID);
	Functions::BindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	Functions::BufferData(GL_ARRAY_BUFFER, size, vertices, strategy);

	m_BufferSize = size / sizeof(float);
	Functions::BindBuffer(0, m_BufferID);
}

void One::GL3::GL3VertexBuffer::Bind() const
{
	Functions::BindBuffer(GL_ARRAY_BUFFER, m_BufferID);
}

void One::GL3::GL3VertexBuffer::Unbind() const
{
	Functions::BindBuffer(0, m_BufferID);
}

One::GL3::GL3VertexBuffer::~GL3VertexBuffer()
{
	Functions::DeleteBuffers(0, &m_BufferID);
}

void One::GL3::GL3VertexBuffer::SubData(u32 offset, u32 size, void *data)
{
	Functions::BindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
	Functions::BindBuffer(0, m_BufferID);
}
