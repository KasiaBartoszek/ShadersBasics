#pragma once
#include "AShader.h"
class VertexShader :
	public AShader
{
private:
	float xRadius=1, zRadius=1, yRadius=1;
	virtual std::string Source();
	virtual int Type() { return GL_VERTEX_SHADER; };
public:
	VertexShader();
	~VertexShader();
};

