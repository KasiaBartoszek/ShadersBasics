#pragma once
#include <GL/glew.h>
#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include "AShader.h"
#include "VertexGenerator.h"
class GPUProgram
{
private:
	GLuint shaderProgram;
	std::vector< std::shared_ptr<AShader>> shaders;
	bool programLinkStatus();
public:
	GPUProgram();
	bool addShader(std::shared_ptr<AShader> shader);
	bool linkShaders();
	bool bindVertieces(VertexGenerator& vGen);
	GLuint ShaderProgram() { return shaderProgram; }
	void addMatrix4x4f(glm::mat4 matrix, const GLchar* varName);
	void addFloat(GLfloat, const GLchar* varName);
	void addVector3(glm::vec3 v, const GLchar* varName);
	~GPUProgram();
};

