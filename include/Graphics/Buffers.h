#ifndef ONE_BUFFERS_H
#define ONE_BUFFERS_H

#include <Graphics/Types.h>
#include <Graphics/Texture.h>
#include <memory>
#include <vector>
#include <One.h>

namespace One::Graphics
{
	class VertexArray;
	class VertexBuffer;
	class IndexBuffer;

	typedef std::shared_ptr<VertexArray> vertex_array_ptr;
	typedef std::shared_ptr<VertexBuffer> vertex_buffer_ptr;
	typedef std::shared_ptr<IndexBuffer> index_buffer_ptr;

	/**
	 * A index buffer specifies the draw order that a vertex buffer will be drawn. This is used to save space
	 * because a vertex can be drawn more than once.
	 */
	class IndexBuffer
	{
	public:
		virtual void Initialize(u32 *indices, u32 size) = 0;
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual unsigned int GetCount() = 0;
		virtual ~IndexBuffer() = default;
	};

	/**
	 * A vertex buffer holds all of the vertices that will be draw to the screen.
	 */
	class VertexBuffer
	{
	public:
		virtual void Initialize(float *vertices, u32 size) = 0;
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual ~VertexBuffer() = default;
	};

	/**
	 * A vertex array is a object that stores the state needed to supply the an shader program.
	 * It holds a vertex buffer, draw primitive and a index buffer.
	 */
	class VertexArray
	{
	protected:
		std::vector<index_buffer_ptr> m_IndexBuffers;
		std::vector<vertex_buffer_ptr> m_VertexBuffers;

	public:
		virtual void Initialize() = 0;
		virtual void AddAttribute(int size, ShaderTypes type, i32 stride, u32 offset,
			bool normalized) = 0;
		virtual void Add(index_buffer_ptr &index_buffer) = 0;
		virtual void Add(vertex_buffer_ptr &vertex_buffer) = 0;
		virtual void Add(texture_ptr &texture) =0;
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual void SetPrimitive(const Graphics::Primitives &primitive) = 0;
		virtual Graphics::Primitives GetPrimitive() = 0;
		virtual VertexBuffer& operator [](std::size_t index) = 0;
		virtual const VertexBuffer& operator [](std::size_t index) const = 0;
		//virtual VertexArray& operator+=(const VertexBuffer& buffer) const = 0;
		virtual ~VertexArray() = default;

		//virtual std::ostream& operator<<(std::ostream& os, const T& obj) = 0;
	};
}

#endif //ONE_BUFFERS_H
