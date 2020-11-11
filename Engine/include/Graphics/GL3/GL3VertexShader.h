#ifndef ONE_GL3VERTEXSHADER_H
#define ONE_GL3VERTEXSHADER_H

#include "GL3Shader.h"

namespace One::Graphics::GL3
{
	/**
	 * Creates a vertex shader
	 */
	class GL3VertexShader : public GL3Shader
	{
	public:
		GL3VertexShader();

		void LoadFromFile(const std::string &file) override;

		void LoadFromString(const std::string &text) override;

	};
}

#endif //ONE_GL3VERTEXSHADER_H
