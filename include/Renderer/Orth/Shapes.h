#ifndef ONE_SHAPES_H
#define ONE_SHAPES_H

#include <One.h>

namespace One::Renderer::Orth::Shapes
{
	namespace {
		class Shape {};
	}

	class Rect : public Shape
	{
	public:


	private:
		explicit Rect(u32 id) : m_RectID(id)
		{}

		u32 m_RectID;
	};
}

#endif //ONE_SHAPES_H
