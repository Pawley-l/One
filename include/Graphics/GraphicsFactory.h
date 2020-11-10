#ifndef ONE_GRAPHICSFACTORY_H
#define ONE_GRAPHICSFACTORY_H

#include <memory>
#include <Graphics/Types.h>
#include <Graphics/Buffers.h>
#include <Graphics/Shader.h>
#include <Graphics/Texture.h>
#include <Common.h>

#define GRAPHICS_FACTORY One::Graphics::Commands::GetInstance()->GetFactory()

namespace One::Graphics
{
	/**
	 * Graphics factory that creates graphics objects for every api. Apis need ot inherit this class and
	 * implement all methods to their respective functions and integrate into Commands singleton
	 */
	class GraphicsFactory
	{
	public:
		/**
		 * Creates a index buffer and returns it
		 * @param indices
		 * @param size
		 * @return index buffer
		 */
		virtual IndexBuffer *CreateIndexBuffer(u32 *indices, u32 size) = 0;

		/**
		 * Create a vertex buffer and returns it
		 * @param vertices
		 * @param size
		 * @return vertex buffer
		 */
		virtual VertexBuffer *CreateVertexBuffer(float *vertices, u32 size) = 0;

		/**
		 * Creates and returns a buffer array
		 * @return buffer array
		 */
		virtual VertexArray *CreateBufferArray() = 0;

		/**
		 * Creates and returns a shader of the type
		 * @param shader
		 * @return shader
		 */
		virtual Shader *CreateShader(Shaders shader) = 0;

		/**
		 * Creates a shader program
		 * @return shader program
		 */
		virtual ShaderProgram *CreateShaderProgram() = 0;

		/**
		 * Creates and loads a shader of the inputted type
		 * @param file
		 * @return
		 */
		virtual Texture *CreateTexture2D(TextureTypes type, const std::string &file) = 0;

		/**
		 * Gets this parent instance as the child instance or nullptr
		 * @tparam child
		 * @return child
		 */
		template<typename child>
		bool *AsChild(child *input)
		{
			input = dynamic_cast<child>(this);
			return input != nullptr;
		}
	};


}

#endif //ONE_GRAPHICSFACTORY_H
