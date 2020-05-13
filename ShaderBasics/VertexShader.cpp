#include "pch.h"
#include "VertexShader.h"


std::string VertexShader::Source()
{
	/*
	Zadanie 5: zmodyfikowaæ program shadera w taki sposób, by wyœwietlana by³a pofalowana p³aszczyzna
	- modyfikowaæ y za pomoc¹ funkcji trygonometrycznych zale¿nych od pozycji x i y.
	*/

	// VAO - CPU 
	// layout - shader

	// Attrib Array (0, 1) - CPU 
	// location - shader

	// proj - macierz (rzutowanie)
	// view - pozycja kamery
	return
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n" // wejœciowa pozycja
		"layout (location = 1) in vec4 aCol;\n" // wejœciowy kolor
		"out vec4 col;\n" // kolor
		"uniform mat4 proj;\n" // macierz 4x4
		"uniform mat4 view;\n" // macierz 4x4
		"uniform vec3 ballPos;\n" // wektor pozycji pi³ki
		"uniform float ballRadius;\n" // k¹t pi³ki
		"void main()\n"
		"{\n"
		"	float f=5.0;\n"
		"	float b_r=ballRadius; float h=ballPos.y;\n"
		"	float x = length(aPos.xz - ballPos.xz);\n"
		"	float y_0=1/x/b_r;\n"
		"	float y_4=sin((x*f)-(b_r*f))*b_r*f;\n"
		"	float y_1=y_4*(1/(1+x*x));\n"
		"	float y_2=min(y_1+y_0,1);\n"
		"	float y_3=max(y_2*h,0);\n"
		"	float y_t=-1/b_r*x*x+b_r;\n"
		"	float y_t1=max(max(y_t,0)+min(h,0),0);\n"
		"	float y_f=y_t1+y_3;\n"
		"	vec3 offset = vec3(aPos.x, aPos.y + y_f, aPos.z);\n"
		"   gl_Position = proj*view*vec4(offset.xyz, 1.0);\n" // wyœwietlanie ekranu, macierz razy wektor (rzutujemy na 4-wymiarowy wektor)
		"	col = vec4(aCol.xyz, 1.0);\n" // kolor te¿ rzutujemy na 4-wymiarowy wektor
		"}\0";
}

VertexShader::VertexShader()
{
}


VertexShader::~VertexShader()
{
}
