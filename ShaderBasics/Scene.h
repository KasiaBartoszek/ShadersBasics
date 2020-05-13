#pragma once
#include <gl/glew.h>

#include <ctime>
#include <chrono>
#include "FragmentShader.h"
#include "VertexShader.h"
#include "GPUProgram.h"
class Scene
{
private:
	std::chrono::system_clock::time_point t;
	std::chrono::system_clock::time_point tBegin;
	bool first = true;
	float dT;
	float wT;

	const float minCamDist = 15.0f;
	const float maxCamDist = 30.0f;
	const float zoomSpeed = 3.0f;

	float cameraXZDist = maxCamDist;
	bool zoomDir = false;

	float sceneAngle = 45.0f;
	float modelAngle = 45.0f;

	float ballPosxz = -2;
	const float ballPoszxMinMax = 3;
	bool ballPosxzDir = true;
	float ballPosMoveSpeed = 1.0f;

	float ballPosY = 0.0f;
	bool ballPosYDir = true;
	float ballPosYSpeed = 0.4f;
	const float ballPosYMin = -0.5f;
	const float ballPosYMax = 0.5f;

	GPUProgram program;
	VertexGenerator vGenerator;
	void updateTimers();
	void drawVertieces();
	void updateGLState();
	void AnimateStep(float& current, bool& dir, float min, float max, float dist);
public:
	void init();
	void frame(void);

	Scene();
	~Scene();
};

