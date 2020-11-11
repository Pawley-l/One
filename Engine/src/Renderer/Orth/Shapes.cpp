#include <Renderer/Orth/Shapes.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

void One::Renderer::Orth::Transform2D::Rotate(float by, glm::vec3 direction)
{

	m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(by), direction);
}

void One::Renderer::Orth::Transform2D::Scale(float x, float y)
{
	m_ModelMatrix = glm::scale(m_ModelMatrix, {x, y, 0});
}

void One::Renderer::Orth::Transform2D::SetPosition(float x, float y)
{

}

void One::Renderer::Orth::Transform2D::Move(float x, float y)
{
	m_ModelMatrix = glm::translate(m_ModelMatrix, {x, y, 0});
}

glm::mat4 One::Renderer::Orth::Transform2D::GetModel()
{
	return m_ModelMatrix;
}
