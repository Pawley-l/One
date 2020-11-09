#ifndef ONE_BUFFERS_H
#define ONE_BUFFERS_H

#include <Graphics/Types.h>
#include <memory>
#include <vector>

namespace One::Graphics
{
	/**
	 *
	 */
	class IndexBuffer
	{
	public:
		virtual void Initialize(unsigned int *indices, unsigned int size) = 0;
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual unsigned int GetCount() = 0;
		virtual ~IndexBuffer() = default;
	};

	typedef std::shared_ptr<IndexBuffer> index_buffer_ptr;

	/**
	 *
	 */
	class VertexBuffer
	{
	public:
		virtual void Initialize(float *vertices, unsigned int size) = 0;
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual ~VertexBuffer() = default;
	};

	typedef std::shared_ptr<VertexBuffer> vertex_buffer_ptr;

	/**
	 *
	 */
	class VertexBufferArray
	{
	protected:
		std::vector<index_buffer_ptr> m_IndexBuffers;
		std::vector<vertex_buffer_ptr> m_VertexBuffers;

	public:
		virtual void Initialize() = 0;
		virtual void AddAttribute(int size, ShaderTypes type, int stride, unsigned int offset,
			bool normalized) = 0;
		virtual void Add(index_buffer_ptr &index_buffer) = 0;
		virtual void Add(vertex_buffer_ptr &vertex_buffer) = 0;
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual ~VertexBufferArray() = default;
	};

	typedef std::shared_ptr<VertexBufferArray> vertex_array_ptr;
}

#endif //ONE_BUFFERS_H
