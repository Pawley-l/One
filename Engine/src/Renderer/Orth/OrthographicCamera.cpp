#include <Renderer/Orth/OrthographicCamera.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void One::OrthographicCamera::LookAt(glm::vec3 x, glm::vec3 y, glm::vec3 z)
{
	Camera::LookAt(x, y, z);
}

glm::mat4x4 One::OrthographicCamera::GetProjection(float width, float height)
{
	m_ProjectionMatrix = glm::ortho(-(width / 2), width / 2, height / 2, -(height / 2), 0.0f, 10.f);

	return m_ProjectionMatrix;
}

glm::mat4x4 One::OrthographicCamera::GetView()
{
	return m_ViewMatrix;
}

void One::OrthographicCamera::Move(float x, float y)
{
	m_ViewMatrix = glm::translate(m_ViewMatrix, {y, x, 0});

//	m_ViewMatrix = glm::lookAt(
//		glm::vec3(0,0,5), // Camera is at (0,0,5), in World Space
//		glm::vec3(x,y,5), // and looks at the origin
//		glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
//	);
}
