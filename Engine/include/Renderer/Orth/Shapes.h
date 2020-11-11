#ifndef ONE_SHAPES_H
#define ONE_SHAPES_H

#include <One.h>
#include <glm/glm.hpp>

namespace One::Renderer::Orth
{
	class Transform2D
	{
	public:
		void Rotate(float by, glm::vec3 direction = {0, 0, 1});

		void Scale(float x, float y = 0);

		void SetPosition(float x, float y);

		void Move(float x, float y);


		glm::mat4 GetModel();

	protected:
		glm::mat4 m_ModelMatrix{1.f};
	};


	struct Shape
	{
		u32 ID = -1;
		u32 TextureID = -1;

		enum class ShapeType
		{
			None, Quad
		} Shape = ShapeType::Quad;

		Transform2D Transform;
	};

}

#endif //ONE_SHAPES_H
