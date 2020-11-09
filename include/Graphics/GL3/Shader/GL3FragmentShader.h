#ifndef ONE_GL3FRAGMENTSHADER_H
#define ONE_GL3FRAGMENTSHADER_H

#include "GL3Shader.h"

namespace One::Graphics::GL3
{
	class GL3FragmentShader : public GL3Shader
	{
	public:
		GL3FragmentShader();

		void LoadFromFile(const std::string &file) override;

		void LoadFromString(const std::string &text) override;
	};
}

#endif //ONE_GL3FRAGMENTSHADER_H
