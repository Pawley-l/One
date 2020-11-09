#ifndef ONE_GL3VERTEXBUFFER_H
#define ONE_GL3VERTEXBUFFER_H

#include <Graphics/Buffers.h>
#include <GL/glew.h>

namespace One::Graphics::GL3
{
	class GL3VertexBuffer : public One::Graphics::VertexBuffer
	{
	private:
		GLuint m_BufferID{};
	public:
		void Initialize(float *vertices, unsigned int size) override;

		void  Bind() const override;

		void Unbind() const override;

		~GL3VertexBuffer() override;
	};
}

#endif //ONE_GL3VERTEXBUFFER_H
