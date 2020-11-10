#ifndef ONE_SHADER_H
#define ONE_SHADER_H

#include <string>
#include <Graphics/Types.h>
#include <memory>
#include <glm/glm.hpp>
#include <Common.h>

namespace One::Graphics
{
	class Shader
	{
	protected:
		/**
		 * Just gets the contents of a file and returns it
		 * @param file
		 * @return contents
		 */
		static std::string GetFileContents(const std::string &file);
	public:
		/**
		 * Loads the shader from file and compiles it
		 * @param file
		 */
		virtual void LoadFromFile(const std::string &file) = 0;

		/**
		 * Loads the shader directly from a string
		 * @param text
		 * @warning not implemented
		 */
		virtual void LoadFromString(const std::string &text) = 0;

		virtual ~Shader() = default;
	};

	typedef std::shared_ptr<Shader> shader_ptr;

	class ShaderProgram
	{
	public:
		/**
		 * Adds a uniform Vec3
		 * @param name
		 * @param vec
		 */
		virtual void AddUniformVec3(const std::string &name, glm::vec3 &vec) = 0;

		/**
		 * Adds a uniform Vec2
		 * @param name
		 * @param vec
		 */
		virtual void AddUniformVec2(const std::string &name, glm::vec2 &vec) = 0;

		/**
		 * Adds a uniform Mat4x4
		 * @param name
		 * @param mat
		 */
		virtual void AddUniformMat4x4(const std::string &name, glm::mat4x4 &mat) = 0;

		/**
		 * Adds a uniform Mat3x3
		 * @param name
		 * @param mat
		 */
		virtual void AddUniformMat3x3(const std::string &name, glm::mat3x3 &mat) = 0;

		/**
		 * Adds a uniform int
		 * @param name
		 * @param val
		 */
		virtual void AddUniformInt(const std::string &name, i32 val) = 0;

		/**
		 * Attaches a shader to the program
		 * @param shader
		 */
		virtual void AttachShader(Shader &shader) const = 0;

		/**
		 * Links the program
		 */
		virtual void LinkProgram() const = 0;

		/**
		 * Enables the shader
		 */
		virtual void Use() const = 0;

		virtual ~ShaderProgram() = default;
	};

	typedef std::shared_ptr<ShaderProgram> shader_program_ptr;
}

#endif //ONE_GL3SHADER_H
