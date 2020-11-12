#ifndef ONE_COMMANDS_H
#define ONE_COMMANDS_H

#include <Graphics/Types.h>
#include <Graphics/Buffers.h>
#include <Graphics/GraphicsFactory.h>
#include <memory>

#define GRAPHICS_COMMANDS One::Commands::GetInstance()

namespace One
{
	class Window;
}

namespace One
{
	/**
	 * Graphics GraphicsAPI Command class - Contains all abstracted commands and a graphics factory set to the correct api.
	 * Whatever initializes the instance first ends up being the graphics api for it's whole life.
	 *
	 * Only friend classes can Initialize the graphics GraphicsAPI.
	 * @friend Window
	 */
	class Commands
	{
	protected:
		Commands();

		friend Window;

		std::shared_ptr<GraphicsFactory> m_Factory;
	public:
		/**
		 * Sets the viewport
		 * @param x
		 * @param y
		 * @param width
		 * @param height
		 */
		virtual void SetViewPort(unsigned int x, unsigned int y, unsigned int width, unsigned int height) = 0;

		/**
		 * Clears the screen with the colour
		 * @param r
		 * @param g
		 * @param b
		 */
		virtual void Clear(float r, float g, float b) = 0;

		/**
		 * Draws an array
		 * @param array
		 * @param primitive
		 */
		virtual void DrawArray(vertex_array_ptr &array, One::Primitives primitive) = 0;

		/**
		 * Draws a indexed array
		 * @param array
		 * @param primitive
		 */
		virtual void DrawElements(vertex_array_ptr &array, One::Primitives primitive) = 0;

		/**
		 * Returns the vendor id
		 * @return u32
		 */
		virtual u32 GetVendorID() = 0;

		/**
		 * Returns the driver id
		 * @return u32
		 */
		virtual u32 GetDriverID() = 0;

		/**
		 * Gets the vendor as a string
		 * @return string
		 */
		virtual std::string GetVendor() = 0;

		/**
		 * Gets the render device as a string
		 * @return string
		 */
		virtual std::string GetRendererDeviceString() = 0;

		/**
		 * Gets the maximum number of textures the driver supports
		 * @return u32
		 */
		virtual u32 GetMaxTextures() = 0;

		/**
		 * Gets the maximum texture size the driver supports
		 * @return
		 */
		virtual u32 GetMaxTextureSize() = 0;

		/**
		 * Gets the graphics factory for creating graphics objects for the correct api
		 * @return
		 */
		GraphicsFactory &GetFactory()
		{
			return *m_Factory;
		}

	private:
		static std::unique_ptr<Commands> m_Instance;

		static std::unique_ptr<Commands> &GetInstanceInitialize(GraphicsAPI api = GraphicsAPI::GL3);

	public:
		/**
		 * Gets the current instance
		 * @return instance
		 * @warning GetInstanceInitialize() needs to be called first by a friend class
		 */
		static std::unique_ptr<Commands> &GetInstance();
	};
}

#endif //ONE_COMMANDS_H
