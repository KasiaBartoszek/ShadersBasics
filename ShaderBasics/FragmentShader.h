#pragma once
#include "AShader.h"
class FragmentShader :
	public AShader
{
	virtual std::string Source();
	virtual int Type() { return GL_FRAGMENT_SHADER; };
public:
	FragmentShader();
	~FragmentShader();
};

