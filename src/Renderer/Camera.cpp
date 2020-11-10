#include <Renderer/Camera.h>
#include <glm/glm.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void One::Renderer::Camera::LookAt(glm::vec3 x, glm::vec3 y, glm::vec3 z)
{
	m_ViewMatrix = glm::lookAt(x, y, z);
}
