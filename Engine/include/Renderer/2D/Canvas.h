#ifndef ONE_CANVAS_H
#define ONE_CANVAS_H

#include <One.h>
#include <Graphics/Texture.h>
#include <glm/glm.hpp>

namespace One
{
	class Canvas
	{
	public:
		Canvas();

		void SetTexture(const Texture &texture);

		void SetColour(float r, float g, float b);

	private:
		std::unique_ptr<Texture> m_CanvasTexture;
		glm::vec3 m_CanvasColour{};
	};
}

#endif //ONE_CANVAS_H
