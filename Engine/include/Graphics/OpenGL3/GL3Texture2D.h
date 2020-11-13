#ifndef ONE_GL3TEXTURE2D_H
#define ONE_GL3TEXTURE2D_H

#include <Graphics/OpenGL3/GL3Texture.h>
#include <One.h>

namespace One::GL3
{
	class GL3Texture2D : public GL3Texture
	{
	public:
		void Initialize() override;

		void Bind(u32 id) override;

		void Unbind() override;

	protected:
		void InitializeTexture() override;

		void LoadTexture(unsigned char *data) override;

	private:
		unsigned int m_TextureID = -1;
	};
}

#endif //ONE_GL3TEXTURE2D_H
