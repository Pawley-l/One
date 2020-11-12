#include <Renderer/Camera.h>
#include <glm/glm.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void One::Camera::LookAt(glm::vec3 x, glm::vec3 y, glm::vec3 z)
{
	m_ViewMatrix = glm::lookAt(x, y, z);
}

void One::Camera::SetFov(float fov)
{
	m_Fov = fov;
}

glm::mat4x4 One::Camera::GetProjection(float width, float height)
{
	m_ProjectionMatrix = glm::perspective(glm::radians(m_Fov), width / height, 0.1f, 100.0f);

	return m_ProjectionMatrix;
}

glm::mat4x4 One::Camera::GetView()
{
	return m_ViewMatrix;
}

void One::Camera::Move(float x, float y)
{

}

One::Camera::Camera()
= default;
