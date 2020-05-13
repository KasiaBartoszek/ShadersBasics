#include "pch.h"
#include "Scene.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>
#include <GL/glut.h>
void Scene::updateTimers()
{
	std::chrono::system_clock::time_point tCurr = std::chrono::system_clock::now();

	if (first)
	{
		t = tCurr;
		tBegin = tCurr;
		first = false;
		return;
	}
	wT = (float)std::chrono::duration_cast<std::chrono::microseconds>(tCurr - tBegin).count() / 1000000;
	dT = (float)std::chrono::duration_cast<std::chrono::microseconds>(tCurr - t).count() / 1000000;
	t = tCurr;
}
void Scene::drawVertieces()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_LINES, 0, vGenerator.Size());
}
void Scene::updateGLState()
{
	glutSwapBuffers();
}


void Scene::init()
{
	GLenum err = glewInit();
	program.addShader(std::static_pointer_cast<AShader>(std::make_shared<FragmentShader>())); // dodajemy fragment shader
	program.addShader(std::static_pointer_cast<AShader>(std::make_shared<VertexShader>())); // dodajemy vertex shader
	program.linkShaders(); // linkujemy shadery

	program.bindVertieces(vGenerator); // ��czymy wierzcho�ki
	glm::mat4 modelRot = glm::mat4(1.0f); // macierz 4x4
	/*
		Zadanie 4a.(0.5pkt) Zamieni� rzutowanie ortogonalne na pespektywiczne za pomoc� funkcji znajduj�cych si� w komentarzu.
		Zmodyfikowa� shader wierzcho�k�w tak aby przyjmowa� macierz "view" jako zmienn� uniform wej�ciow�.

		*/
	
	program.addFloat(0.5f, "ballRadius");
	program.addMatrix4x4f(glm::perspective(50.0f, 1000.0f/600.0f, 1.0f, 150.0f), "proj"); // perspective ustala parametry kamery
	// fov (obr�t wzgl�dem x lub y), aspect ratio (stosunek wys. do szer.), near (�uk blisko kamery), far (�uk daleko kamery)
}


void Scene::frame(void)
{
	updateTimers();
	/*
		Zadanie 4b.(0.5pkt) Doda� animacj� kamery (zmiana parametr�w funkcji lookAt() w zale�no�ci od czasu).
		 Czas dost�pny jest poprzez zmienne prywatne - dT - od ostatniej klatki, wT - od pocz�tku.
		 Aktualizacja czasu - metoda updateTimers();
	*/

	AnimateStep(cameraXZDist, zoomDir, minCamDist, maxCamDist, dT * zoomSpeed); // kamera si� przybli�a i oddala
	AnimateStep(ballPosxz, ballPosxzDir, -ballPoszxMinMax, ballPoszxMinMax, dT * ballPosMoveSpeed); // kulka lata na boki
	AnimateStep(ballPosY, ballPosYDir, ballPosYMin, ballPosYMax, dT * ballPosYSpeed); // kulka lata w g�r� i w d�

	program.addMatrix4x4f(glm::lookAt( // lookAt (potrzebne, �eby zrobi� rzutowanie perspektywiczne)
		glm::vec3(cosf(wT) * cameraXZDist, 15.0f, sinf(wT) * cameraXZDist), // eye - kamera, sk�d patrzy
		glm::vec3(0.0f, 0.0f, 0.0f), // center - na co patrzy, k�t pod jakim patrzymy
		glm::vec3(0.0f, -1.0f, 0.0f)), "view"); // up, wektor up, kt�ry m�wi, w kt�r� stron� wok� w�asnej osi obracamy kamer�
	drawVertieces();
	program.addVector3(glm::vec3(ballPosxz, ballPosY, ballPosxz), "ballPos"); // wrzucamy pozycj� pi�ki
	updateGLState();	
}


void Scene::AnimateStep(float &current, bool &dir, float min, float max, float dist)
{
	if (dir) {
		current += dist;
		if (current > max) {
			dir = false;
		}
	}
	else {
		current -= dist;
		if (current < min) {
			dir = true;
		}
	}
	
}

Scene::Scene()
{
}


Scene::~Scene()
{
}
