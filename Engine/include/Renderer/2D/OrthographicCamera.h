#ifndef ONE_ORTHOGRAPHICCAMERA_H
#define ONE_ORTHOGRAPHICCAMERA_H

#include <Renderer/Camera.h>

namespace One
{
	class OrthographicCamera : public One::Camera
	{
	public:
		OrthographicCamera();

		void Move(float x, float y) override;

	public:
		void LookAt(glm::vec3 x, glm::vec3 y, glm::vec3 z) override;

		glm::mat4x4 GetProjection(float width, float height) override;

		glm::mat4x4 GetView() override;

	private:
		glm::vec3 m_Position;
		float m_Rotiation = 0.f;
	};
}

#endif //ONE_ORTHOGRAPHICCAMERA_H
