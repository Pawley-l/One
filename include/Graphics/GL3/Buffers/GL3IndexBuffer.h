#ifndef ONE_GL3INDEXBUFFER_H
#define ONE_GL3INDEXBUFFER_H

#include <Graphics/Buffers.h>
#include <GL/glew.h>

namespace One::Graphics::GL3
{
	class GL3VertexBufferArray;

	class GL3IndexBuffer : public IndexBuffer
	{
	private:
		unsigned int m_Count = 0;
		GLuint m_BufferID = 0;

		friend GL3VertexBufferArray;
	public:
		void Initialize(u32 *indices, u32 size) override;

		void Bind() const override;

		void Unbind() const override;

		~GL3IndexBuffer() override;

		unsigned int GetCount() override;
	};
}

#endif //ONE_GL3INDEXBUFFER_H
