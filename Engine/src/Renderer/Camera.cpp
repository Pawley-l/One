#include <Renderer/Camera.h>
#include <glm/glm.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void One::Renderer::Camera::LookAt(glm::vec3 x, glm::vec3 y, glm::vec3 z)
{
	m_ViewMatrix = glm::lookAt(x, y, z);
}

void One::Renderer::Camera::SetFov(float fov)
{
	m_Fov = fov;
}

glm::mat4x4 One::Renderer::Camera::GetProjection(float width, float height)
{
	m_ProjectionMatrix = glm::perspective(glm::radians(m_Fov), width / height, 0.1f, 100.0f);

	return m_ProjectionMatrix;
}

glm::mat4x4 One::Renderer::Camera::GetView()
{
	return m_ViewMatrix;
}

void One::Renderer::Camera::Move(float x, float y)
{

}

One::Renderer::Camera::Camera()
= default;
