#ifndef ONE_BASERENDERER_H
#define ONE_BASERENDERER_H

#include <One.h>
#include <Graphics/Types.h>
#include <Renderer/Camera.h>
#include <Graphics/Buffers.h>
#include <Graphics/Shader.h>
#include <Window/Window.h>

#include <string>
#include <queue>
#include <atomic>

namespace One
{
	/**
	 * Contains all information about the device this is being rendered on.
	 *
	 * @property GPU - contains VendorID, DeviceID, VendorString, RendererDeviceString, GraphicsAPI, Limitations, Analytics
	 * @property Monitor - contains width, height
	 */
	struct Device
	{
		struct GpuData
		{
			u32 VendorID;
			u32 DeviceID;
			std::string VendorString;
			std::string RendererDeviceString;
			One::GraphicsAPI GraphicsAPI;
			struct LimitsData
			{
				u32 MaxTextures;
				u32 MaxTextureSize;
			} Limitations;
			struct AnalyticsData
			{
				u32 DrawCalls;
			} Analytics;
		}
			GPU;
		struct MonitorData
		{
			u32 Width;
			u32 Height;
		} Monitor;
	};

	/**
	 * The base renderer that all renderers inherit from. All renders all queued and flushed by the flush method.
	 * Specific use cases should be handled by specific inherited children, this can only handle drawing vertex arrays
	 * which handles majority of rendering but not a nice interface.
	 */
	class BaseRenderer
	{
	public:
		/**
		 * Initializes the renderer with the api.
		 * @param api
		 */
		explicit BaseRenderer(GraphicsAPI api);

		/**
		 * Initializes the device it will be rendered on
		 */
		void InitializeDevice();

		/**
		 * Gets information and statistics of the render device
		 * @return
		 */
		Device GetCurrentDevice();

		/**
		 * Attaches this renderer to a window to use it as its context
		 * @param window
		 */
		void AttachWindow(const std::shared_ptr<One::Window> &window);

		/**
		 * Adds a vertex array to its render queue
		 * @param array
		 */
		virtual void Draw(vertex_array_ptr &array);

		/**
		 * Starts a scene with a camera and shader
		 * @param camera
		 * @param shader
		 *
		 * @warning only one scene per draw call currently
		 * @warning Needs to be attached to a window
		 */
		virtual void SceneBegin(const std::shared_ptr<One::Camera> &camera,
		                        const std::shared_ptr<ShaderProgram> &shader);

		/**
		 * Ends the current scene
		 */
		virtual void SceneEnd();

		/**
		 * Flushes all of the draw calls from all scenes
		 */
		virtual void Flush();

	protected:

		Device m_Device{};
		glm::mat4 m_ProjectionMatrix{};
		glm::mat4 m_ViewMatrix{};
		std::shared_ptr<ShaderProgram> m_CurrentShader;
		std::shared_ptr<One::Window> m_AttachedWindow;
		std::queue<vertex_array_ptr> m_Queue;
		std::atomic_bool m_InScene;
		float m_Fov = 75.f;
	};
}

#endif //ONE_BASERENDERER_H
