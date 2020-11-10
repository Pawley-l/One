#include <Graphics/GL3/Shader/GL3ShaderProgram.h>
#include <Graphics/GL3/Shader/GL3Shader.h>
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

One::Graphics::GL3::GL3ShaderProgram::GL3ShaderProgram()
{
	m_ProgramID = glCreateProgram();
}

void One::Graphics::GL3::GL3ShaderProgram::AttachShader(One::Graphics::Shader &shader) const
{
	auto *gl3shader = dynamic_cast<GL3Shader*>(&shader);
	glAttachShader(m_ProgramID, gl3shader->m_ShaderID);
}

void One::Graphics::GL3::GL3ShaderProgram::LinkProgram() const
{
	int success;
	char infoLog[1024];
	glLinkProgram(m_ProgramID);
	glGetShaderiv(m_ProgramID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(m_ProgramID, 1024, NULL, infoLog);
		std::cout << infoLog  << std::endl;
	}
}

void One::Graphics::GL3::GL3ShaderProgram::Use() const
{
	glUseProgram(m_ProgramID);
}

One::Graphics::GL3::GL3ShaderProgram::~GL3ShaderProgram()
{

}

void One::Graphics::GL3::GL3ShaderProgram::AddUniformVec3(const std::string &name, glm::vec3 &vec)
{

}

void One::Graphics::GL3::GL3ShaderProgram::AddUniformVec2(const std::string &name, glm::vec2 &vec)
{
//	int location = glGetUniformLocation(m_ProgramID, name.c_str());
//	glUniform2fv(location, 1, GL_FALSE, &vec);
}

void One::Graphics::GL3::GL3ShaderProgram::AddUniformMat4x4(const std::string &name, glm::mat4x4 &mat)
{
	int location = glGetUniformLocation(m_ProgramID, name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, &mat[0][0]);
}

void One::Graphics::GL3::GL3ShaderProgram::AddUniformMat3x3(const std::string &name, glm::mat3x3 &mat)
{
	int location = glGetUniformLocation(m_ProgramID, name.c_str());
	glUniformMatrix3fv(location, 1, GL_FALSE, &mat[0][0]);
}

void One::Graphics::GL3::GL3ShaderProgram::AddUniformInt(const std::string &name, i32 val)
{
	int location = glGetUniformLocation(m_ProgramID, name.c_str());
	glUniform1i(location, val);
}
