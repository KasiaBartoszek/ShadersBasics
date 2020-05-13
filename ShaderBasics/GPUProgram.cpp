 #include "pch.h"
#include "GPUProgram.h"
#include <vector>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>
bool GPUProgram::programLinkStatus()
{
	{
		GLint status;
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
		if (status == GL_FALSE) {
			GLint length;
			glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> log(length);
			glGetProgramInfoLog(shaderProgram, length, &length, &log[0]);
			std::cout << &log[0];
			return false;
		}
		std::cout << "Shaders linked to the program succesfully :-)";
		return true;
	}
}

GPUProgram::GPUProgram()
{
	
}

bool GPUProgram::addShader(std::shared_ptr<AShader> shader)
{
	shader->initialize();
	if (!shader->Compile())
		return false;
	shaders.push_back(shader);
	return true;
}

bool GPUProgram::linkShaders()
{
	shaderProgram = glCreateProgram();
	for (auto shader = shaders.begin(); shader != shaders.end(); ++shader) {
		glAttachShader(shaderProgram, (*shader)->ShaderGLObj());
	}
	glLinkProgram(shaderProgram);
	return programLinkStatus();
	
}

bool GPUProgram::bindVertieces(VertexGenerator& vGen)
{
	GLuint VBO, VAO;

	glGenVertexArrays(1, &VAO); // Vertex Array Object, kontener na bufory
	glGenBuffers(1, &VBO); // Vertex Buffer Object, bufor
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);


	/**Zadanie 2 (1 pkt):
		- stworzyæ tablicê wierzcho³ków - u¿yæ metody generate generateVertieces()z klasy VertexGenerator
		- stworzyæ dwie tablice atrybutów - dla trójwymiarowej pozycji i czterowymiarowego koloru i przypisaæ
		  je do VBO i VAO.
	*/
	float* vertices = vGen.generateVertieces();
	//tworzenie tablic wierzcho³ków
	glGenBuffers(1, &VBO); // generuj bufor VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // ³¹czy VBO z Vertex Artibutes
	glBufferData(GL_ARRAY_BUFFER, vGen.Count() * sizeof(float), vertices, GL_STATIC_DRAW); // zawartoœæ VBO
	// (target) vertex artibutes, (size) il. wierzch. * wym. wierzch., (data) wierzcho³ki, (usage pattern of data store)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0); // tablica danych wierzcho³ków (pozycja)
	// (index), (size) l. komponentów dla wierzcho³ka (xyz), (type), (normalized) converted directly when accessed, (stride) offset miêdzy nimi, 
	// (pointer) pierwszy komponent
	glEnableVertexAttribArray(0); // indeks 0
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 *sizeof(float))); // tablica danych wierzcho³ków (kolor)
	// (index) 1, (size) 4, bo RGBA, ..., (pointer) tak przesuniêty, ¿eby przeskoczyæ pozycjê (xyz) i dojœæ do kolorów
	glEnableVertexAttribArray(1); // indeks 1
	//koniec zadania drugiego.
	glUseProgram(shaderProgram);
	delete[] vertices;
	return true;
}


void GPUProgram::addMatrix4x4f(glm::mat4 matrix, const GLchar* varName)
{
	/* Zadanie 3a (0.5pkt):
	Napisaæ metodê dodaj¹c¹ macierz 4x4f do programu shadera
	*/
	GLuint loc = glGetUniformLocation(shaderProgram,varName); // zwraca lokalizacjê uniforma
	// (program), (name)
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(matrix)); 
	// (location), (count) liczba macierzy, (transpose) czy transponowaæ macierz, (value) wskaŸnik na tablicê
}

void GPUProgram::addFloat(GLfloat f, const GLchar * varName)
{
	/* Zadanie 3a (0.5pkt):
	Napisaæ metodê dodaj¹c¹ zmienn¹ typu float do programu shadera
	*/
	GLuint loc = glGetUniformLocation(shaderProgram, varName);
	glUniform1f(loc, f); 
	// (location), (v0) dla wart. skalarnych - nowa wartoœæ u¿ywana do uniforma
}

void GPUProgram::addVector3(glm::vec3 v, const GLchar* varName)
{
	GLuint loc = glGetUniformLocation(shaderProgram, varName);
	glUniform3f(loc, v.x, v.y, v.z);
}

GPUProgram::~GPUProgram()
{
}
