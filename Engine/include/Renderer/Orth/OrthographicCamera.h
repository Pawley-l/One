#ifndef ONE_ORTHOGRAPHICCAMERA_H
#define ONE_ORTHOGRAPHICCAMERA_H

#include <Renderer/Camera.h>

namespace One::Renderer::Orth
{
	class OrthographicCamera : public One::Renderer::Camera
	{
	public:
		void Move(float x, float y) override;

	public:
		void LookAt(glm::vec3 x, glm::vec3 y, glm::vec3 z) override;

		glm::mat4x4 GetProjection(float width, float height) override;

		glm::mat4x4 GetView() override;

	};
}

#endif //ONE_ORTHOGRAPHICCAMERA_H