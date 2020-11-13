#include <Graphics/OpenGL3/GL3Texture2D.h>
#include <GL/glew.h>

void One::GL3::GL3Texture2D::Initialize()
{
	glCreateTextures(GL_TEXTURE_2D, 1, &m_TextureID);
}

void One::GL3::GL3Texture2D::Bind(u32 id)
{
	glBindTextureUnit(id, m_TextureID);
}

void One::GL3::GL3Texture2D::Unbind()
{
	glBindTextureUnit(0, m_TextureID);
}

void One::GL3::GL3Texture2D::InitializeTexture()
{
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void One::GL3::GL3Texture2D::LoadTexture(unsigned char *data)
{
	Initialize();
	glTextureStorage2D(m_TextureID, 1, GL_RGBA8, m_Width, m_Height);
	InitializeTexture();
	glTextureSubImage2D(m_TextureID, 0, 0, 0, m_Width, m_Height, GL_RGBA, GL_UNSIGNED_BYTE, data);
}
