#pragma once
#include <string>
#include <GL/glew.h>
#include <vector>
#include <iostream>
class AShader
{
	const char* source;
	int length;
	GLuint aShader;
	virtual std::string Source() = 0;
	virtual int Type() = 0;
	bool shaderCompileStatus();
	
public:
	AShader();
	void initialize();
	bool Compile();
	GLuint& ShaderGLObj() { return aShader; }
	virtual ~AShader();

};

