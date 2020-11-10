#ifndef ONE_PROJECTONE_H
#define ONE_PROJECTONE_H

#include <Application/Application.h>
#include <Graphics/Buffers.h>
#include <Renderer/Camera.h>

class ProjectOne : public One::Application
{
public:
	void Startup() override;

	void ProcessFrame() override;

private:
	std::shared_ptr<One::Graphics::VertexBuffer> m_VertexBuffer;
	std::shared_ptr<One::Graphics::IndexBuffer> m_IndexBuffer;
	std::shared_ptr<One::Graphics::VertexArray> m_VertexArray;
	std::shared_ptr<One::Graphics::ShaderProgram> m_ShaderProgram;
	std::shared_ptr<One::Graphics::Texture> m_Texture;
	glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
	std::shared_ptr<One::Renderer::Camera> m_Camera;
};


#endif //ONE_PROJECTONE_H
