#ifndef ONE_GL3VERTEXBUFFER_H
#define ONE_GL3VERTEXBUFFER_H

#include <Graphics/Buffers.h>
#include <GL/glew.h>

namespace One::Graphics::GL3
{
	class GL3BufferArray;

	class GL3VertexBuffer : public One::Graphics::VertexBuffer
	{
	private:
		GLuint m_BufferID{};
		GLuint m_BufferSize;

		friend GL3BufferArray;
	public:
		void Initialize(float *vertices, u32 size) override;

		void  Bind() const override;

		void Unbind() const override;

		~GL3VertexBuffer() override;
	};
}

#endif //ONE_GL3VERTEXBUFFER_H
