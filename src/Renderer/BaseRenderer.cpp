#include <Renderer/BaseRenderer.h>
#include <Graphics/Commands.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

One::Renderer::Device One::Renderer::BaseRenderer::GetCurrentDevice()
{
	return m_Device;
}

void One::Renderer::BaseRenderer::Submit(One::Graphics::vertex_array_ptr &array)
{
	m_Queue.push(array);
}

void One::Renderer::BaseRenderer::SceneBegin(const std::shared_ptr<One::Renderer::Camera>& camera,
                                             const std::shared_ptr<Graphics::ShaderProgram>& shader)
{
	m_ProjectionMatrix = camera->GetProjection(m_AttachedWindow->GetWindowWidth(), m_AttachedWindow->GetWindowHeight());
	m_ViewMatrix = camera->GetView();
	m_CurrentShader = shader;
	m_InScene = true;
}

void One::Renderer::BaseRenderer::SceneEnd()
{
	m_InScene = false;
}

void One::Renderer::BaseRenderer::Flush()
{
	if (!m_InScene)
		if (!m_Queue.empty())
		{
			m_CurrentShader->Use();
			m_CurrentShader->AddUniformMat4x4("view", m_ViewMatrix);
			m_CurrentShader->AddUniformMat4x4("projection", m_ProjectionMatrix);

			glm::mat4 model = glm::mat4(1.0f);
			m_CurrentShader->AddUniformMat4x4("model", model);

			while (!m_Queue.empty())
			{
				GRAPHICS_COMMANDS->DrawElements(m_Queue.front(), m_Queue.front()->GetPrimitive());
				m_Queue.pop();
			}
		}
}

One::Renderer::BaseRenderer::BaseRenderer(One::Graphics::API api)
{
	m_Device.GPU.GraphicsAPI = api;
}

void One::Renderer::BaseRenderer::InitializeDevice()
{
	m_Device = {
		GRAPHICS_COMMANDS->GetVendorID(),
		GRAPHICS_COMMANDS->GetDriverID(),
		GRAPHICS_COMMANDS->GetVendor(),
		GRAPHICS_COMMANDS->GetRendererDeviceString(),
		Graphics::API::GL3,
		GRAPHICS_COMMANDS->GetMaxTextures(),
		GRAPHICS_COMMANDS->GetMaxTextureSize(),
		1280,
		720
	};
}

void One::Renderer::BaseRenderer::AttachWindow(const std::shared_ptr<One::Window> &window)
{
	m_AttachedWindow = window;
}

