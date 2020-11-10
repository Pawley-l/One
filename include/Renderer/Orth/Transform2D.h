#ifndef ONE_TRANSFORM2D_H
#define ONE_TRANSFORM2D_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace One::Renderer::Orth
{
	class Transform2D
	{
	public:
		void Rotate(float by);
		void Scale(float by);
		void SetPosition(float x, float y);
		void Move(float x, float y);

	protected:
		glm::mat4 m_ModelMatrix;
	};
}

#endif //ONE_TRANSFORM2D_H
