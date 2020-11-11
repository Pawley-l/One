#ifndef ONE_TYPES_H
#define ONE_TYPES_H

namespace One::Graphics
{
	enum class API
	{
		GL2, GL3, Vulkan
	};

	enum class Shaders
	{
		Vertex, Fragment, Geometry
	};

	enum class Buffers
	{
		Vertex, Index, Frame
	};

	enum class ShaderTypes
	{
		Vec, Vec2, Vec3, Vec4, Mat2, Mat3, Mat4, Float, Int
	};
	
	enum class Primitives
	{
		Triangles, Quads, Points, Lines
	};

	enum class DrawStrategy
	{
		Static, Dynamic
	};

	enum class TextureTypes
	{
		Texture2D
	};
}

#endif //ONE_TYPES_H
