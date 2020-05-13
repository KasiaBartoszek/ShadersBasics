#include "pch.h"
#include "FragmentShader.h"


std::string FragmentShader::Source()
{
	return
		"#version 330 core\n"
		"in vec4 col;\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"		FragColor = col;\n"
		"}\0";
}

FragmentShader::FragmentShader()
{
	
}


FragmentShader::~FragmentShader()
{
}
