#include <Graphics/GL3/Shader/GL3ShaderProgram.h>
#include <Graphics/GL3/Shader/GL3Shader.h>

One::Graphics::GL3::GL3ShaderProgram::GL3ShaderProgram()
{
	m_ProgramID = glCreateProgram();
}

void One::Graphics::GL3::GL3ShaderProgram::AttachShader(One::Graphics::Shader &shader) const
{
	auto *gl3shader = dynamic_cast<GL3Shader*>(&shader);
	glAttachShader(gl3shader->m_ShaderID, m_ProgramID);
}

void One::Graphics::GL3::GL3ShaderProgram::LinkProgram() const
{
	glLinkProgram(m_ProgramID);
}

void One::Graphics::GL3::GL3ShaderProgram::Use() const
{
	glUseProgram(m_ProgramID);
}

One::Graphics::GL3::GL3ShaderProgram::~GL3ShaderProgram()
{

}
