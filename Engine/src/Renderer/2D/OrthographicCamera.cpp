#include <Renderer/2D/OrthographicCamera.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

One::OrthographicCamera::OrthographicCamera()
{
	m_Position.x = 0;
	m_Position.y = 0;
}

void One::OrthographicCamera::LookAt(glm::vec3 x, glm::vec3 y, glm::vec3 z)
{
	Camera::LookAt(x, y, z);
}

glm::mat4x4 One::OrthographicCamera::GetProjection(float width, float height)
{
	m_ProjectionMatrix = glm::ortho(0.f, width, 0.f, height,
	                                -1.0f, 1.f);

	return m_ProjectionMatrix;
}

glm::mat4x4 One::OrthographicCamera::GetView()
{
	glm::mat4 transform = glm::translate(glm::mat4(1.f), m_Position);
	m_ViewMatrix = glm::inverse(transform);

	return m_ViewMatrix;
}

void One::OrthographicCamera::Move(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

