#ifndef ONE_BASE2DRENDERER_H
#define ONE_BASE2DRENDERER_H

#include <Renderer/Orth/Shapes.h>
#include <Renderer/Orth/OrthographicCamera.h>
#include <Renderer/BaseRenderer.h>
#include <Graphics/Array.h>

namespace One::Renderer::Orth
{
	class Base2DRenderer : public BaseRenderer
	{
	public:
		explicit Base2DRenderer(Graphics::API api);

		void Initialize();

		Shape CreateShape(Shape::ShapeType shapetype);

		u32 CreateTexture(const std::string &file);

		void SceneBegin(const std::shared_ptr<OrthographicCamera> &camera);

		void Draw(Shape shape);

		void Flush() override;

	private:
		std::vector<std::shared_ptr<Graphics::Texture>> m_Textures;

		std::vector<std::shared_ptr<Graphics::VertexArray>> m_VertexArrays;

		std::queue<Shape> m_RendererQueue;
	};
}


#endif //ONE_BASE2DRENDERER_H
