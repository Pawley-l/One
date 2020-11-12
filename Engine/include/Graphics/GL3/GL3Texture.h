#ifndef ONE_GL3TEXTURE_H
#define ONE_GL3TEXTURE_H

#include <Graphics/Texture.h>

namespace One::GL3
{
	class GL3Texture : public Texture
	{
	public:
		void LoadFromFile(const std::string &file) override;

		unsigned int GetWidth() override;

		unsigned int GetHeight() override;

	protected:
		virtual void InitializeTexture() =0;
		virtual void LoadTexture(unsigned char *data) =0;

		int m_Width;
		int m_Height;
		std::string m_Path;
	};
}

#endif //ONE_GL3TEXTURE_H
