#include <Graphics/OpenGL3/GL3Functions.h>
#include <any>

void One::GL3::Functions::DrawArrays(One::Primitives primitive, unsigned int first, unsigned int count)
{
	switch (primitive) {
		case Primitives::Triangles:
			glDrawArrays(GL_TRIANGLES, first, count);
		case Primitives::Quads:
			glDrawArrays(GL_QUADS, first, count);
		case Primitives::Points:
			glDrawArrays(GL_POINTS, first, count);
		case Primitives::Lines:
			glDrawArrays(GL_LINES, first, count);
	}
}

void One::GL3::Functions::ClearColour(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
}

void One::GL3::Functions::Clear(unsigned int mask)
{
	glClear(mask);
}

void One::GL3::Functions::Viewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
	glViewport(x, y, width, height);
}

void One::GL3::Functions::GenBuffers(unsigned int n, unsigned int *buffers)
{
	glGenBuffers(n, buffers);
}

void One::GL3::Functions::BindBuffer(unsigned int type, unsigned int id)
{
	glBindBuffer(type, id);
}

void One::GL3::Functions::BufferData(unsigned int type, unsigned int size, void *data,
                                     One::DrawStrategy usage)
{
	switch (usage) {
		case DrawStrategy::Static:
			glBufferData(type, size, data, GL_STATIC_DRAW);
			break;
		case DrawStrategy::Dynamic:
			glBufferData(type, size, data, GL_DYNAMIC_DRAW);
			break;
	}
}

void One::GL3::Functions::DeleteBuffers(unsigned int n, unsigned int *buffers)
{
	glDeleteBuffers(n, buffers);
}

void One::GL3::Functions::VertexAttribPointer(unsigned int location, unsigned int size,
                                              One::ShaderTypes type, bool normalized,
                                              unsigned int stride, void *offset)
{
	switch (type) {
		case ShaderTypes::Vec:
			break;
		case ShaderTypes::Vec2:
			break;
		case ShaderTypes::Vec3:
			break;
		case ShaderTypes::Vec4:
			break;
		case ShaderTypes::Mat2:
			break;
		case ShaderTypes::Mat3:
			break;
		case ShaderTypes::Mat4:
			break;
		case ShaderTypes::Float:
			glVertexAttribPointer(location, size, GL_FLOAT, !normalized ? GL_TRUE : GL_FALSE,
			                      stride, offset);
			break;
		case ShaderTypes::Int:
			glVertexAttribPointer(location, size, GL_INT, !normalized ? GL_TRUE : GL_FALSE,
			                      stride, offset);
			break;
	}

}

void One::GL3::Functions::DrawElements(One::Primitives primitive, unsigned int count,
                                       One::ShaderTypes type, unsigned int indices)
{
	// TODO: Convert shader type
	switch (primitive) {

		case Primitives::Triangles:
			glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, (void *) indices);
			break;
		case Primitives::Points:
			glDrawElements(GL_POINTS, count, GL_UNSIGNED_INT, (void *) indices);
			break;
		case Primitives::Lines:
			glDrawElements(GL_LINES, count, GL_UNSIGNED_INT, (void*) indices);
			break;
		case Primitives::Quads:
			glDrawElements(GL_QUADS, count, GL_UNSIGNED_INT, (void*) indices);
			break;
	}
}
