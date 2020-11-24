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
#include "Camera.h"

#define MAX_VERTEX

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
		Renderer2D();

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
		virtual void ShapePosition(RenderResource2D resource, float x, float y);

		virtual void ShapeRotate(RenderResource2D resource, float by);

		virtual void ShapeScale(RenderResource2D resource, float by);

		// Canvas API
		virtual void SetCanvasColour(float r, float g, float b, float a);

		virtual void SetCanvasTexture2D(RenderResource2D &resource);

		// Batch Draw API
		virtual void BeginBatch(std::shared_ptr<Camera> camera, std::shared_ptr<ShaderProgram> shader);

//		virtual void DrawShape(RenderResource2D &resource, One::RenderResource2D &texture);

		virtual void EndBatch();

		// Draw Commands
		virtual void FlushBatch();

		// Viewport Commands
		virtual void SwapBuffer();

		virtual void ClearBuffer();

	protected:
		std::vector<std::shared_ptr<Texture>> m_RenderingResourcesTexture;
		Canvas m_Canvas;
		std::shared_ptr<VertexArray> m_VertexArray;
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
		std::shared_ptr<Camera> m_Camera;
		std::shared_ptr<ShaderProgram> m_Shader;
		std::shared_ptr<One::Texture> m_Texture;
		glm::mat4 m_ProjectionMatrix{};
		glm::mat4 m_ViewMatrix{};
		u32 m_ShapeIndex = 0;
	};

}

#endif //ONE_RENDERER2D_H
