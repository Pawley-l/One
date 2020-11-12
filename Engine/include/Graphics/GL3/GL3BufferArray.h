#ifndef ONE_GL3BUFFERARRAY_H
#define ONE_GL3BUFFERARRAY_H

#include <Graphics/Buffers.h>
#include <Graphics/Array.h>
#include <Graphics/Types.h>
#include <Graphics/GL3/GL3Buffers.h>
#include <GL/glew.h>

namespace One::GL3
{
	class GL3BufferArray : public VertexArray
	{

	public:
		void Initialize() override;

		void Bind() const override;

		void Unbind() const override;

		~GL3BufferArray() override;

		void
		AddAttribute(int size, ShaderTypes type, i32 stride, u32 offset, bool normalized) override;

		void Add(index_buffer_ptr &index_buffer) override;

		void Add(vertex_buffer_ptr &vertex_buffer) override;

		[[nodiscard]] unsigned int GetVertexCount() const;

		[[nodiscard]] unsigned int GetIndexCount() const;

		void Add(texture_ptr &texture) override;

		void SetPrimitive(const Primitives &primitive) override;

		Primitives GetPrimitive() override;

		VertexBuffer &operator[](std::size_t index) override;

		const VertexBuffer &operator[](std::size_t index) const override;

	private:
		GLuint m_BufferID;
		GLuint m_AttribLocation;
		GLuint m_VertexCount;
		GLuint m_IndexCount;
		GLuint m_TextureIndex = 0;
		Primitives m_DrawPrimitive;
	};
}

#endif //ONE_GL3BUFFERARRAY_H
