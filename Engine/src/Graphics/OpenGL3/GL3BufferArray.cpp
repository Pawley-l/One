#include <Graphics/OpenGL3/GL3BufferArray.h>
#include <Graphics/OpenGL3/GL3Functions.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wint-to-void-pointer-cast"

void One::GL3::GL3BufferArray::Initialize()
{
	glGenVertexArrays(1, &m_BufferID);
	glBindVertexArray(0);
}

void One::GL3::GL3BufferArray::Bind() const
{
	glBindVertexArray(m_BufferID);
}

void One::GL3::GL3BufferArray::Unbind() const
{
	glBindVertexArray(0);
}

void One::GL3::GL3BufferArray::AddAttribute(int size, One::ShaderTypes type, i32 stride,
                                            u32 offset, bool normalized)
{
	glBindVertexArray(m_BufferID);

	Functions::VertexAttribPointer(m_AttribLocation, size, type, normalized, stride, (void *) offset);

	glEnableVertexAttribArray(m_AttribLocation);

	glBindVertexArray(0);
	m_AttribLocation++;
}

void One::GL3::GL3BufferArray::Add(One::index_buffer_ptr &index_buffer)
{
	auto *new_array = dynamic_cast<GL3IndexBuffer *>(index_buffer.get());
	m_IndexCount += new_array->m_Count;
	Bind();
	new_array->Bind();
	Unbind();
	m_IndexBuffers.push_back(index_buffer);
}

void One::GL3::GL3BufferArray::Add(One::vertex_buffer_ptr &vertex_buffer)
{
	auto *new_array = dynamic_cast<GL3VertexBuffer *>(vertex_buffer.get());
	m_VertexCount += new_array->m_BufferSize;
	Bind();
	new_array->Bind();
	Unbind();
	m_VertexBuffers.push_back(vertex_buffer);
}

unsigned int One::GL3::GL3BufferArray::GetVertexCount() const
{
	return m_VertexCount;
}

unsigned int One::GL3::GL3BufferArray::GetIndexCount() const
{
	return m_IndexCount;
}

void One::GL3::GL3BufferArray::Add(One::texture_ptr &texture)
{
	Bind();
	texture->Bind(m_TextureIndex);
	m_TextureIndex++;
	Unbind();
	texture->Unbind();
}

void One::GL3::GL3BufferArray::SetPrimitive(const One::Primitives &primitive)
{
	m_DrawPrimitive = primitive;
}

One::Primitives One::GL3::GL3BufferArray::GetPrimitive()
{
	return m_DrawPrimitive;
}

One::VertexBuffer &One::GL3::GL3BufferArray::operator[](std::size_t index)
{
	return m_VertexBuffers[index].operator*();
}

const One::VertexBuffer &One::GL3::GL3BufferArray::operator[](std::size_t index) const
{
	return m_VertexBuffers[index].operator*();
}

One::GL3::GL3BufferArray::~GL3BufferArray()
= default;

#pragma clang diagnostic pop