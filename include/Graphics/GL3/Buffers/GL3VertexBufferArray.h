#ifndef ONE_GL3VERTEXBUFFERARRAY_H
#define ONE_GL3VERTEXBUFFERARRAY_H

#include <Graphics/Buffers.h>
#include <Graphics/Types.h>
#include <Graphics/GL3/GL3Buffers.h>
#include <GL/glew.h>

namespace One::Graphics::GL3
{
	class GL3VertexBufferArray : public VertexArray
	{
	private:
		GLuint m_BufferID;
		GLuint m_AttribLocation;
		GLuint m_VertexCount;
		GLuint m_IndexCount;
		GLuint m_TextureIndex = 0;
		Primitives m_DrawPrimitive;
		
	public:
		void Initialize() override;

		void Bind() const override;

		void Unbind() const override;

		~GL3VertexBufferArray() override;

		void
		AddAttribute(int size, ShaderTypes type, i32 stride, u32 offset, bool normalized) override;

		void Add(index_buffer_ptr &index_buffer) override;

		void Add(vertex_buffer_ptr &vertex_buffer) override;

		unsigned int GetVertexCount() const;

		unsigned int GetIndexCount() const;

		void Add(texture_ptr &texture) override;

		void SetPrimitive(const Primitives &primitive) override;

		Primitives GetPrimitive() override;

		VertexBuffer &operator[](std::size_t index) override;

		const VertexBuffer &operator[](std::size_t index) const override;
	};
}

#endif //ONE_GL3VERTEXBUFFERARRAY_H
