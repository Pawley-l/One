#include <Graphics/OpenGL3/GL3Shader.h>
#include <sstream>

void One::GL3::GL3Shader::CompileShader(const std::string &code, GLuint id)
{
	const char *c_str = code.c_str();

	int success;
	char infoLog[512];

	glShaderSource(id, 1, &c_str, nullptr);
	glCompileShader(id);

	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(id, 512, nullptr, infoLog);
		ERROR(infoLog)
	};
}

One::GL3::GL3Shader::~GL3Shader()
{
	glDeleteShader(m_ShaderID);
}