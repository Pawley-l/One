#ifndef ONE_BASERENDERER_H
#define ONE_BASERENDERER_H

#include <One.h>
#include <Graphics/Types.h>
#include <Renderer/Camera.h>
#include <Graphics/Buffers.h>
#include <Graphics/Shader.h>

#include <string>
#include <queue>
#include <atomic>
#include <Window/Window.h>


namespace One::Renderer
{
	struct Device
	{
		struct GpuData {
			u32 VendorID;
			u32 DeviceID;
			std::string VendorString;
			std::string RendererDeviceString;
			One::Graphics::API GraphicsAPI;
			struct LimitsData {
				u32 MaxTextures;
				u32 MaxTextureSize;
			} Limitations;
			struct AnalyticsData {
				u32 DrawCalls;
			} Analytics;
		} GPU;
		struct MonitorData {
			u32 Width;
			u32 Height;
		} Monitor;
	};

	class BaseRenderer
	{
	public:
		explicit BaseRenderer(Graphics::API api);

		void InitializeDevice();

		Device GetCurrentDevice();

		void AttachWindow(const std::shared_ptr<One::Window> &window);

		virtual void Draw(Graphics::vertex_array_ptr &array);

		virtual void SceneBegin(const std::shared_ptr<One::Renderer::Camera>& camera,
		                        const std::shared_ptr<Graphics::ShaderProgram>& shader);

		virtual void SceneEnd();

		virtual void Flush();

	protected:
		Device m_Device{};
		glm::mat4 m_ProjectionMatrix{};
		glm::mat4 m_ViewMatrix{};
		std::shared_ptr<Graphics::ShaderProgram> m_CurrentShader;
		std::shared_ptr<One::Window> m_AttachedWindow;
		std::queue<Graphics::vertex_array_ptr> m_Queue;
		std::atomic_bool m_InScene;
		float m_Fov = 75.f;
	};
}

#endif //ONE_BASERENDERER_H
