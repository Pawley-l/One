#include <Renderer/BaseRenderer.h>
#include <Graphics/Commands.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

One::Device One::BaseRenderer::GetCurrentDevice()
{
	return m_Device;
}

void One::BaseRenderer::Draw(One::vertex_array_ptr &array)
{
	m_Queue.push(array);
}

void One::BaseRenderer::SceneBegin(const std::shared_ptr<One::Camera> &camera,
                                   const std::shared_ptr<ShaderProgram> &shader)
{
	m_ProjectionMatrix = camera->GetProjection(m_AttachedWindow->GetWindowWidth(),
	                                           m_AttachedWindow->GetWindowHeight());
	m_ViewMatrix = camera->GetView();
	m_CurrentShader = shader;
	m_InScene = true;
}

void One::BaseRenderer::SceneEnd()
{
	m_InScene = false;
}

void One::BaseRenderer::Flush()
{
	if (!m_InScene) {
		// Sets the analytics
		m_Device.GPU.Analytics.DrawCalls = m_Queue.size();

		if (!m_Queue.empty()) {
			glm::mat4 model = glm::mat4(1.0f);
//			model = glm::scale(model, glm::vec3(100.0f, 100.0f, 0.0f));

			m_CurrentShader->Use();
			m_CurrentShader->AddUniformMat4x4("view", m_ViewMatrix);
			m_CurrentShader->AddUniformMat4x4("projection", m_ProjectionMatrix);
			m_CurrentShader->AddUniformMat4x4("model", model);

			while (!m_Queue.empty()) {
				GRAPHICS_COMMANDS->DrawElements(m_Queue.front(), m_Queue.front()->GetPrimitive());
				m_Queue.pop();
			}
		}
	}
}

One::BaseRenderer::BaseRenderer(One::GraphicsAPI api)
{
	m_Device.GPU.GraphicsAPI = api;
}

void One::BaseRenderer::InitializeDevice()
{
	m_Device = {
		GRAPHICS_COMMANDS->GetVendorID(),
		GRAPHICS_COMMANDS->GetDriverID(),
		GRAPHICS_COMMANDS->GetVendor(),
		GRAPHICS_COMMANDS->GetRendererDeviceString(),
		GraphicsAPI::GL3,
		GRAPHICS_COMMANDS->GetMaxTextures(),
		GRAPHICS_COMMANDS->GetMaxTextureSize(),
		1000,
		1280,
		720
	};
}

void One::BaseRenderer::AttachWindow(const std::shared_ptr<One::Window> &window)
{
	m_AttachedWindow = window;
}

