#ifndef ONE_SHADER_H
#define ONE_SHADER_H

#include <string>
#include <Graphics/Types.h>
#include <memory>

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
		virtual void AttachShader(Shader &shader) const = 0;

		virtual void LinkProgram() const = 0;

		virtual void Use() const = 0;

		virtual ~ShaderProgram() = default;
	};

	typedef std::shared_ptr<ShaderProgram> shader_program_ptr;
}

#endif //ONE_GL3SHADER_H
