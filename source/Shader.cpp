#include "Shader.h"

JPH::Shader::Shader()
{
}

JPH::Shader::Shader(const char* filedir, GLenum _ShaderType)
{
	this->shaderfile = File(filedir);
	if (!shaderfile.readFile()) {
		std::cout << "Shader file could not be open"<<std::endl;
		
	}
	else {
		this->ShaderCode = shaderfile.getfiledata().c_str();
	}
	this->id = NULL;
	this->ShaderType = _ShaderType;

}

JPH::Shader::Shader(File _ShaderFile, GLenum _ShaderType)
{
	this->shaderfile = _ShaderFile;
	if (!shaderfile.readFile()) {
		std::cout << "Shader file could not be open" << std::endl;

	}
	else {
		this->ShaderCode = shaderfile.getfiledata().c_str();
	}
	this->id = NULL;
	this->ShaderType = _ShaderType;
}

JPH::Shader::~Shader()
{
}

unsigned int JPH::Shader::getid()
{
	return id;
}

const char* JPH::Shader::getShaderCode()
{
	return this->ShaderCode;
}

void JPH::Shader::compileShader()
{
	int success;
	char infoLog[512];

	// vertex Shader
	this->id = glCreateShader(ShaderType);
	glShaderSource(this->id, 1, &ShaderCode, NULL);
	glCompileShader(this->id);
	// print compile errors if any
	glGetShaderiv(this->id, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(this->id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};
}
