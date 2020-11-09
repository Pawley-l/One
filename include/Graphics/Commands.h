#ifndef ONE_COMMANDS_H
#define ONE_COMMANDS_H

#include <Graphics/Types.h>
#include <memory>

#define GRAPHICS_COMMANDS One::Graphics::Commands::GetInstance()

namespace One::Graphics
{
	class Commands
	{
	public:
		virtual void SetViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height) = 0;
		virtual void Clear(float r, float g, float b) = 0;
	private:
		static std::unique_ptr <Commands> m_Instance;
	public:
		static std::unique_ptr <Commands> &GetInstance(API api = API::GL3);
	};
}

#endif //ONE_COMMANDS_H
