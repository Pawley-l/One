#include <Renderer/Image.h>

#define STB_IMAGE_IMPLEMENTATION

#include <stb/stb_image.h>

#include <memory>

One::Image::Image()
= default;

One::Image::~Image()
{
	if (m_FileData)
		stbi_image_free(m_FileData);
}

void One::Image::LoadFromFile(const std::string &file, bool flipped)
{
	m_Path = file;
	stbi_set_flip_vertically_on_load(flipped);
	m_FileData = stbi_load(file.c_str(), &m_Width, &m_Height, &m_Channels, STBI_rgb_alpha);

	if (m_FileData) {
		m_IsLoaded = true;
	} else {
		ERROR("Failed to load image - " + file);
	}
}

std::pair<int, int> One::Image::GetSize() const
{
	return std::pair<int, int>(m_Width, m_Height);
}

int One::Image::GetChannels() const
{
	return m_Channels;
}

bool One::Image::IsImageLoaded() const
{
	return m_IsLoaded;
}

unsigned char *One::Image::GetImageData() const
{
	return m_FileData;
}

std::shared_ptr<One::Image> One::Image::LoadImedi(const std::string &file)
{
	auto image = std::make_shared<Image>();
	image->LoadFromFile(file);
	return std::shared_ptr<Image>();
}
