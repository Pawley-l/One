#ifndef ONE_GL3SHADERPROGRAM_H
#define ONE_GL3SHADERPROGRAM_H

#include <GL/glew.h>
#include <Graphics/Shader.h>

namespace One::GL3
{
	class GL3ShaderProgram : public ShaderProgram
	{
	private:
		GLuint m_ProgramID;

	public:
		GL3ShaderProgram();

		void AttachShader(Shader &shader) const override;

		void LinkProgram() const override;

		void Use() const override;

		~GL3ShaderProgram() override;

		void AddUniformVec3(const std::string &name, glm::vec3 &vec) override;

		void AddUniformVec2(const std::string &name, glm::vec2 &vec) override;

		void AddUniformMat4x4(const std::string &name, glm::mat4x4 &mat) override;

		void AddUniformMat3x3(const std::string &name, glm::mat3x3 &mat) override;

		void AddUniformInt(const std::string &name, i32 val) override;
	};
}

#endif //ONE_GL3SHADERPROGRAM_H
