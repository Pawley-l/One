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
		virtual void Initialize(u32 *indices, u32 count) = 0;
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

	class FrameBuffer
	{
	public:
	};
}

#endif //ONE_BUFFERS_H
