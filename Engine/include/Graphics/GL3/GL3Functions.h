#ifndef ONE_GL3FUNCTIONS_H
#define ONE_GL3FUNCTIONS_H

#include <GL/glew.h>
#include <Graphics/Types.h>
#include <any>

/**
 * Wrapper around common opengl 3 functions
 *
 * 			glVertexAttribPointer(m_AttribLocation, size, GL_FLOAT, normalized ? GL_TRUE : GL_FALSE,
			                      stride, (void*)offset);
			glEnableVertexAttribArray(m_AttribLocation);;
			glBindVertexArray(0);
			glGenVertexArrays(1, &m_BufferID);
 */

namespace One::Graphics::GL3::Functions
{
	void DrawArrays(One::Graphics::Primitives primitive, unsigned int first, unsigned int count);
	void ClearColour(float r, float g, float b, float a);
	void Clear(unsigned int mask);
	void Viewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
	void GenBuffers(unsigned int n, unsigned int* buffers);
	void BindBuffer(unsigned int type, unsigned int id);
	void BufferData(unsigned int type, unsigned int size, void * data, DrawStrategy usage);
	void DeleteBuffers(unsigned int n, unsigned int* buffers);
	void VertexAttribPointer(unsigned int location, unsigned int size, One::Graphics::ShaderTypes type,
			  bool normalized, unsigned int stride, void* offset);
//	void EnableVertexAttribArray();
//	void BindVertexArray();
//	void GenVertexArrays();
	void DrawElements(One::Graphics::Primitives primitive,
		   unsigned int count, One::Graphics::ShaderTypes type, unsigned int indices);
}

#endif //ONE_GL3FUNCTIONS_H
