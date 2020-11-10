#include <Graphics/GL3/Shader/GL3Shader.h>
#include <sstream>

void One::Graphics::GL3::GL3Shader::CompileShader(const std::string &code, GLuint id)
{
	const char *c_str = code.c_str();

	int success;
	char infoLog[512];

	glShaderSource(id, 1, &c_str, NULL);
	glCompileShader(id);

	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(id, 512, NULL, infoLog);
		ERROR(infoLog)
	};
}

One::Graphics::GL3::GL3Shader::~GL3Shader()
{
	glDeleteShader(m_ShaderID);
}