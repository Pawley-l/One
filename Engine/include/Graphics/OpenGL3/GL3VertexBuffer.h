#ifndef ONE_GL3VERTEXBUFFER_H
#define ONE_GL3VERTEXBUFFER_H

#include <Graphics/Buffers.h>
#include <GL/glew.h>

namespace One::GL3
{
	class GL3BufferArray;

	class GL3VertexBuffer : public One::VertexBuffer
	{
	private:
		GLuint m_BufferID{};
		GLuint m_BufferSize;

		friend GL3BufferArray;
	public:
		void Initialize(float *vertices, u32 size, DrawStrategy strategy) override;

		void Bind() const override;

		void Unbind() const override;

		~GL3VertexBuffer() override;

		void SubData(u32 offset, u32 size, void *data) override;
	};
}

#endif //ONE_GL3VERTEXBUFFER_H
