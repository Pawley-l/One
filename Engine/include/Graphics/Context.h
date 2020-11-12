#ifndef ONE_CONTEXT_H
#define ONE_CONTEXT_H

namespace One
{
	class Context
	{
	public:
		virtual void InitializeContext() = 0;

		virtual void SwapBuffers() = 0;
	};
}

#endif //ONE_CONTEXT_H
