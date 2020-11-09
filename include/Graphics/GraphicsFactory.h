#ifndef ONE_GRAPHICSFACTORY_H
#define ONE_GRAPHICSFACTORY_H

#include <memory>
#include <Graphics/Types.h>
#include <Graphics/Buffers.h>
#include <Graphics/Shader.h>
#include <Graphics/Features.h>

#define GRAPHICS_FACTORY One::Graphics::GraphicsFactory::GetInstance()

namespace One::Graphics
{
	class GraphicsFactory
	{
	public:
		/**
		 * Returns the current factory in plain text
		 * @return string
		 */
		virtual Features GetFeatures() = 0;

		/**
		 * Creates a index buffer and returns it
		 * @param indices
		 * @param size
		 * @return index buffer
		 */
		virtual IndexBuffer *CreateIndexBuffer(unsigned int *indices, unsigned int size) = 0;

		/**
		 * Create a vertex buffer and returns it
		 * @param vertices
		 * @param size
		 * @return vertex buffer
		 */
		virtual VertexBuffer *CreateVertexBuffer(float *vertices, unsigned int size) = 0;

		virtual VertexBufferArray *CreateBufferArray() = 0;

		/**
		 * Creates and returns a shader of the type
		 * @param shader
		 * @return shader
		 */
		virtual Shader *CreateShader(Shaders shader) = 0;

		virtual ShaderProgram *CreateShaderProgram() = 0;

	private:
		static std::unique_ptr<GraphicsFactory> m_Instance;
	public:
		static std::unique_ptr<GraphicsFactory> &GetInstance(API api = API::GL3);
	};

	/**
	 * OpenGL 3.3 Core Graphics Factory inherited from GraphicsFactory
	 */
	class GL3GraphicsFactory : public GraphicsFactory
	{
	private:
		friend GraphicsFactory;
		explicit GL3GraphicsFactory();
	public:
		Features GetFeatures() override;

		IndexBuffer *CreateIndexBuffer(unsigned int *indices, unsigned int size) override;

		VertexBuffer *CreateVertexBuffer(float *vertices, unsigned int size) override;

		Shader *CreateShader(Shaders shader) override;

		ShaderProgram *CreateShaderProgram() override;

		VertexBufferArray *CreateBufferArray() override;
	};
}

#endif //ONE_GRAPHICSFACTORY_H
