#include <iostream>
#include <GL/glew.h>
#include "File.h"

namespace JPH {
	class Shader{
	public:
		Shader();
		Shader(const char* filedir, GLenum _ShaderType);
		Shader(File _ShaderFile, GLenum _ShaderType);
		virtual ~Shader();
		unsigned int getid();
		const char* getShaderCode();
		void compileShader();
	private:
		File shaderfile;
		unsigned int id;
		const char* ShaderCode;
		GLenum ShaderType;
	};
}