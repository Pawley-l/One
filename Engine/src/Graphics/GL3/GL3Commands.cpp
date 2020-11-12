#include <Graphics/GL3/GL3Commands.h>
#include <Graphics/GL3/GL3Buffers.h>
#include <Graphics/GL3/GL3Functions.h>
#include <Graphics/GL3/GL3Factory.h>

One::GL3::GL3Commands::GL3Commands()
{
	m_Factory = std::shared_ptr<GL3Factory>(new GL3Factory());
}

void
One::GL3::GL3Commands::SetViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
	Functions::Viewport(x, y, width, height);
}

void One::GL3::GL3Commands::Clear(float r, float g, float b)
{
	Functions::ClearColour(r, g, b, 1.0f);
	Functions::Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void One::GL3::GL3Commands::DrawArray(One::vertex_array_ptr &array, One::Primitives primitive)
{
	auto *new_array = dynamic_cast<GL3BufferArray *>(array.get());
	new_array->Bind();

	Functions::DrawArrays(primitive, 0, 3);
}

void One::GL3::GL3Commands::DrawElements(One::vertex_array_ptr &array,
                                         One::Primitives primitive)
{
	auto *new_array = dynamic_cast<GL3BufferArray *>(array.get());
	new_array->Bind();

	Functions::DrawElements(primitive, new_array->GetIndexCount(), ShaderTypes::Int, 0);
}

u32 One::GL3::GL3Commands::GetVendorID()
{
	return 0;
}

u32 One::GL3::GL3Commands::GetDriverID()
{
	return 0;
}

std::string One::GL3::GL3Commands::GetVendor()
{
	return std::string();
}

std::string One::GL3::GL3Commands::GetRendererDeviceString()
{
	return std::string();
}

u32 One::GL3::GL3Commands::GetMaxTextures()
{
	return 0;
}

u32 One::GL3::GL3Commands::GetMaxTextureSize()
{
	return 0;
}