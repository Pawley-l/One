#ifndef ONE_GL3COMMANDS_H
#define ONE_GL3COMMANDS_H

#include <Graphics/Commands.h>

namespace One::Graphics::GL3
{
	class GL3Commands : public Commands
	{
	public:
		GL3Commands();

		void SetViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height) override;

		void Clear(float r, float g, float b) override;
	};
}

#endif //ONE_GL3COMMANDS_H
