#pragma once

#include <glad/glad.h>
#include <string>

namespace Renderer {

	class ShaderProgram
	{
	public:
		ShaderProgram(const std::string& vertexShader, const std::string& fragmentShader);
		~ShaderProgram();
		bool isCompiled() const { return m_isCompiled; }
		void use() const;

		ShaderProgram() = delete;//запрет на пустой конструктор
		ShaderProgram(ShaderProgram&) = delete; //запрет с тем жеуказателем
		ShaderProgram& operator = (const ShaderProgram&) = delete; //запрет на приравнивание
		ShaderProgram& operator = (ShaderProgram&& shaderProgram) noexcept;
		ShaderProgram(ShaderProgram&& shaderProgram) noexcept; 

	private:
		bool createShader(const std::string& source, const GLenum shaderType, GLuint& shaderID);
		bool m_isCompiled = false;
		GLuint m_ID = 0;
	};
}