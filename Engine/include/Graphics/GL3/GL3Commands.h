#ifndef ONE_GL3COMMANDS_H
#define ONE_GL3COMMANDS_H

#include <Graphics/Commands.h>

namespace One::GL3
{
	class GL3Commands : public Commands
	{
	public:
		GL3Commands();

		void SetViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height) override;

		void Clear(float r, float g, float b) override;

		void DrawArray(vertex_array_ptr &array, One::Primitives primitive) override;

		void DrawElements(vertex_array_ptr &array, One::Primitives primitive) override;

		u32 GetVendorID() override;

		u32 GetDriverID() override;

		std::string GetVendor() override;

		std::string GetRendererDeviceString() override;

		u32 GetMaxTextures() override;

		u32 GetMaxTextureSize() override;
	};
}

#endif //ONE_GL3COMMANDS_H
