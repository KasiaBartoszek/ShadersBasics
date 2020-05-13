#include "pch.h"
#include "AShader.h"


AShader::AShader()
{
}

void AShader::initialize()
{
	aShader = glCreateShader(Type());
	std::string src = Source();
	source=_strdup(src.c_str());
	length = Source().size();
	glShaderSource(aShader, 1, &source, &length);
}

bool AShader::Compile()
{
	glCompileShader(aShader);
	return (shaderCompileStatus());
}


bool AShader::shaderCompileStatus()
{
	GLint status;
	glGetShaderiv(aShader, GL_COMPILE_STATUS, &status);
	if (status == GL_FALSE) {
		GLint length;
		glGetShaderiv(aShader, GL_INFO_LOG_LENGTH, &length);
		std::vector<char> log(length);
		glGetShaderInfoLog(aShader, length, &length, &log[0]);
		std::cout << &log[0];
		return false;
	}
	std::cout << "Compiled with no errors :-) \n";
	return true;
}

AShader::~AShader()
{
	delete[] source;
}
