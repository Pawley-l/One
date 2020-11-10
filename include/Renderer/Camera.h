#ifndef ONE_CAMERA_H
#define ONE_CAMERA_H

#include <glm/glm.hpp>

namespace One::Renderer
{
	class BaseRenderer;

	class Camera
	{
	public:
		void LookAt(glm::vec3 x, glm::vec3 y, glm::vec3 z);

	private:
		friend BaseRenderer;

		glm::mat4x4 m_ViewMatrix;
	};
}

#endif //ONE_CAMERA_H
