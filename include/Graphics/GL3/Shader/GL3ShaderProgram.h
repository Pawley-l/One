#ifndef ONE_GL3SHADERPROGRAM_H
#define ONE_GL3SHADERPROGRAM_H

#include <GL/glew.h>
#include <Graphics/Shader.h>

namespace One::Graphics::GL3
{
	class GL3ShaderProgram : public ShaderProgram
	{
	private:
		GLuint m_ProgramID;

	public:
		GL3ShaderProgram();

		void AttachShader(Shader &shader) const override;

		void LinkProgram() const override;

		void Use() const override;

		~GL3ShaderProgram() override;
	};
}

#endif //ONE_GL3SHADERPROGRAM_H
