#ifndef ONE_GL3SHADER_H
#define ONE_GL3SHADER_H

#include <iostream>
#include <Graphics/Types.h>
#include <Graphics/Shader.h>
#include <GL/glew.h>

namespace One::GL3
{
	class GL3ShaderProgram;

	/**
	 * GL3Shader class that all shaders should inherit from
	 */
	class GL3Shader : public One::Shader
	{
	private:
		friend GL3ShaderProgram;

	protected:
		GLuint m_ShaderID;

		/**
		 * Compiles the shader using the inputted code and id
		 * @param code
		 * @param id
		 * @warning The id needs to be created with glCreateShader before calling this
		 */
		static void CompileShader(const std::string &code, GLuint id);
	public:
		/**
		 * Deletes the shader
		 */
		~GL3Shader() override;
	};
}

#endif //ONE_GL3SHADER_H
