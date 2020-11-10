#ifndef ONE_GL3FACTORY_H
#define ONE_GL3FACTORY_H

#include <Graphics/GraphicsFactory.h>

namespace One::Graphics::GL3
{
	class GL3Commands;

	/**
	 * OpenGL 3.3 Core Graphics Factory inherited from GraphicsFactory
	 */
	class GL3Factory : public GraphicsFactory
	{
	private:
		friend GL3Commands;

		explicit GL3Factory();
	public:
		IndexBuffer *CreateIndexBuffer(u32 *indices, u32 size) override;

		VertexBuffer *CreateVertexBuffer(float *vertices, u32 size) override;

		Shader *CreateShader(Shaders shader) override;

		ShaderProgram *CreateShaderProgram() override;

		VertexArray *CreateBufferArray() override;

		Texture *CreateTexture2D(TextureTypes type, const std::string &file) override;
	};
}

#endif //ONE_GL3FACTORY_H
