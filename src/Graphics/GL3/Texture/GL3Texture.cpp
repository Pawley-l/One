#include <Graphics/GL3/Texture/GL3Texture.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <iostream>

void One::Graphics::GL3::GL3Texture::LoadFromFile(const std::string &file)
{
	Initialize();
	m_Path = file;
	int nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load(file.c_str(), &m_Width, &m_Height, &nrChannels, STBI_rgb_alpha);

	if (data) {
		InitializeTexture();
		LoadTexture(data);
	} else {
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

unsigned int One::Graphics::GL3::GL3Texture::GetWidth()
{
	return m_Width;
}

unsigned int One::Graphics::GL3::GL3Texture::GetHeight()
{
	return m_Width;
}
