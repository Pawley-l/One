#ifndef ONE_TEXTURE_H
#define ONE_TEXTURE_H

#include <string>
#include <memory>
#include <One.h>
#include <Renderer/Image.h>

namespace One
{
	/**
	 * Basic Texture class
	 */
	class Texture
	{
	public:
		virtual void Initialize() = 0;

		virtual void LoadFromFile(const std::string &file) = 0;

		virtual void LoadFromImage(const Image &image) = 0;

		virtual void Bind(u32 id) = 0;

		virtual void Unbind() = 0;

		virtual std::pair<int, int> GetSize() = 0;
	};

	typedef std::shared_ptr<Texture> texture_ptr;
}


#endif //ONE_GL3TEXTURE_H
