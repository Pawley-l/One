#ifndef ONE_GL3VERTEXBUFFERARRAY_H
#define ONE_GL3VERTEXBUFFERARRAY_H

#include <Graphics/Buffers.h>
#include <GL/glew.h>

namespace One::Graphics::GL3
{
	class GL3VertexBufferArray : public VertexBufferArray
	{
	private:
		GLuint m_BufferID;
		GLuint m_AttribLocation;
	public:
		void Initialize() override;

		void Bind() const override;

		void Unbind() const override;

		~GL3VertexBufferArray() override;

		void
		AddAttribute(int size, ShaderTypes type, int stride, unsigned int offset, bool normalized) override;

		void Add(index_buffer_ptr &index_buffer) override;

		void Add(vertex_buffer_ptr &vertex_buffer) override;

	};
}

#endif //ONE_GL3VERTEXBUFFERARRAY_H
