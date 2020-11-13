#ifndef ONE_IMAGE_H
#define ONE_IMAGE_H

#include <One.h>
#include <memory>

namespace One
{
	class Image
	{
	public:
		Image();

		~Image();

		void LoadFromFile(const std::string &file, bool flipped = true);

		[[nodiscard]] unsigned char *GetImageData() const;

		[[nodiscard]] std::pair<int, int> GetSize() const;

		[[nodiscard]] int GetChannels() const;

		[[nodiscard]] bool IsImageLoaded() const;

		static std::shared_ptr<Image> LoadImedi(const std::string &file);

	private:
		bool m_IsLoaded = false;

		unsigned char *m_FileData = nullptr;

		int m_Width = -1, m_Height = -1, m_Channels = -1;

		std::string m_Path;
	};
}

#endif //ONE_IMAGE_H
