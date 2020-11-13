#include <Graphics/OpenGL3/GL3Texture.h>
#include <stb/stb_image.h>
#include <iostream>

void One::GL3::GL3Texture::LoadFromFile(const std::string &file)
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

void One::GL3::GL3Texture::LoadFromImage(const One::Image &image)
{
	if (image.IsImageLoaded()) {
		Initialize();
		InitializeTexture();
		LoadTexture(image.GetImageData());
	}
}

std::pair<int, int> One::GL3::GL3Texture::GetSize()
{
	return std::pair<int, int>(m_Width, m_Height);
}
