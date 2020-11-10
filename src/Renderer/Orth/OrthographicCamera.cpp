#include <Renderer/Orth/OrthographicCamera.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void One::Renderer::Orth::OrthographicCamera::LookAt(glm::vec3 x, glm::vec3 y, glm::vec3 z)
{
	Camera::LookAt(x, y, z);
}

glm::mat4x4 One::Renderer::Orth::OrthographicCamera::GetProjection(float width, float height)
{
	m_ProjectionMatrix = glm::ortho<float>(0, 0, width, height, 0.1f, 100.0f);

	return m_ProjectionMatrix;
}

glm::mat4x4 One::Renderer::Orth::OrthographicCamera::GetView()
{
	return Camera::GetView();
}
