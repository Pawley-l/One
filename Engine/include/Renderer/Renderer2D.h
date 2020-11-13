#ifndef ONE_RENDERER2D_H
#define ONE_RENDERER2D_H

#include <One.h>
#include <Renderer/Image.h>
#include <Renderer/2D/Canvas.h>

#include <any>
#include <vector>
#include <queue>
#include <Graphics/Types.h>
#include <Graphics/Shader.h>
#include <Graphics/Array.h>

namespace One
{
	class GraphicsFunctionError : public std::logic_error
	{
	public:
		GraphicsFunctionError() : logic_error("GraphicsFunctionError")
		{}

		virtual char const *what()
		{ return "Error when calling a graphics function \n"; }
	};

	/**
	 * "Render Resources" such as texture and shapes
	 */
	struct RenderResource2D
	{
		u32 id;
		enum ResourceType
		{
			Texture, Material, Shader, Shape
		} type;
	};

	enum class Shapes
	{
		Quad
	};

	/**
	 * Handles the rendering of all 2D objects, particles, lights, and resources
	 */
	class Renderer2D
	{
	public:
		// Texture API
		virtual RenderResource2D CreateTexture2D();

		virtual RenderResource2D CreateTexture2D(const std::string &name);

		virtual RenderResource2D CreateTexture2D(const Image &image);

		virtual RenderResource2D CreateTexture2D(u32 width, u32 height, const unsigned char *data);

		virtual void LoadTexture2D(RenderResource2D &resource, const std::string &name);

		// Shader API
//		virtual RenderResource2D CreateShader() = 0;
//		virtual RenderResource2D CreateShader(const std::string &name, bool file = true) = 0;
//
//		virtual void SetShaderSource(RenderResource2D& resource, const std::string &name, bool file = true) = 0;
//		virtual std::string GetShaderSource(RenderResource2D& resource) = 0;

		// Shape API
		virtual RenderResource2D CreateShape(Shapes shape);

		// Transformation API
		virtual void ShapeMove(RenderResource2D resource, float x, float y);

		virtual void ShapeRotate(RenderResource2D resource, float by);

		virtual void ShapeScale(RenderResource2D resource, float by);

		// Canvas API
		virtual void SetCanvasColour(float r, float g, float b, float a);

		virtual void SetCanvasTexture2D(RenderResource2D &resource);

		// Direct Draw API
//		virtual void DirectDrawQuad(glm::vec2 position, glm::vec2 size,
//						RenderResource2D &texture, float rotate = 0) = 0;

		// Batch Draw API
		virtual void BeginBatch();

		virtual void DrawShape(RenderResource2D &resource, One::RenderResource2D &texture);

		virtual void EndBatch();

		// Draw Commands
		virtual void FlushBatch();
//		virtual void FlushDirect() = 0;

	protected:

		struct DrawCall
		{
			u32 ShapeID;
			u32 TextureID;
		};


		std::vector<std::shared_ptr<Texture>> m_RenderingResourcesTexture;
		Canvas m_Canvas;
		std::unique_ptr<VertexArray> m_VertexArray;
		std::vector<std::shared_ptr<VertexArray>> m_VertexBuffers;

	private:

	};

}

#endif //ONE_RENDERER2D_H
