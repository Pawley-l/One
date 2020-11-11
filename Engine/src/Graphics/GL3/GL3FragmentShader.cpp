#include <Graphics/GL3/GL3FragmentShader.h>

void One::Graphics::GL3::GL3FragmentShader::LoadFromFile(const std::string &file)
{
	auto code = GetFileContents(file);
	CompileShader(code, m_ShaderID);
}

void One::Graphics::GL3::GL3FragmentShader::LoadFromString(const std::string &text)
{
	CompileShader(text, m_ShaderID);
}

One::Graphics::GL3::GL3FragmentShader::GL3FragmentShader()
{
	m_ShaderID = glCreateShader(GL_FRAGMENT_SHADER);
}
