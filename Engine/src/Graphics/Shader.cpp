#include <Graphics/Shader.h>
#include <fstream>

std::string One::Graphics::Shader::GetFileContents(const std::string &file)
{
	std::ifstream ifs(file);
	std::string content( (std::istreambuf_iterator<char>(ifs) ),
	                     (std::istreambuf_iterator<char>()) );
	return content;
}