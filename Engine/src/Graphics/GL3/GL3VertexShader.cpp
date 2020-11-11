#include <Graphics/GL3/GL3VertexShader.h>

void One::Graphics::GL3::GL3VertexShader::LoadFromFile(const std::string &file)
{
	auto code = GetFileContents(file);
	CompileShader(code, m_ShaderID);
}

void One::Graphics::GL3::GL3VertexShader::LoadFromString(const std::string &text)
{
	CompileShader(text, m_ShaderID);
}

One::Graphics::GL3::GL3VertexShader::GL3VertexShader()
{
	m_ShaderID = glCreateShader(GL_VERTEX_SHADER);
}
