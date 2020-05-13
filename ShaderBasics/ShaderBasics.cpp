#include "pch.h"
#include "Scene.h"
#include <GL/glew.h>
#include <GL/glut.h>
Scene scene;

void timer(int t) {
	glutPostRedisplay();
	glutTimerFunc(16, timer, 0);
}

void display() {
	glEnable(GL_CULL_FACE);
	glCullFace(GL_FRONT);
	scene.frame();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
	
	glutCreateWindow("GK: Fragment and vertex shaders");
	glutReshapeWindow(1000, 600);
	glutDisplayFunc(display);
	glutTimerFunc(16, timer, 0);

	std::cout << glGetString(GL_VERSION) << std::endl;
	
	scene.init();
	glutMainLoop();
	return 0;
}
