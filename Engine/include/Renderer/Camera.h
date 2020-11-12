#ifndef ONE_CAMERA_H
#define ONE_CAMERA_H

#include <glm/glm.hpp>

namespace One
{
	class BaseRenderer;

	class Camera
	{
	public:
		Camera();

		virtual void LookAt(glm::vec3 x, glm::vec3 y, glm::vec3 z);

		virtual void Move(float x, float y);

		virtual glm::mat4x4 GetProjection(float width, float height);

		virtual glm::mat4x4 GetView();

		void SetFov(float fov);

	protected:
		float m_Fov = 75.f;

		glm::mat4x4 m_ViewMatrix{1.f};
		glm::mat4x4 m_ProjectionMatrix{1.f};
	};
}

#endif //ONE_CAMERA_H
