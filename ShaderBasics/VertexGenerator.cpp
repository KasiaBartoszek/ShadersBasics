#include "pch.h"
#include "VertexGenerator.h"
#include <iostream>

using namespace std;

float * VertexGenerator::generateVertieces()
{
	float xMin = -4, xMax = 4.1, zMin = -4, zMax = 4.1; // zakres wierzcho³ków
	float stepX = 0.1, stepZ = 0.1; // skoki miêdzy wierzcho³kami
	
	int xCount = ((xMax - xMin) / stepX) + 1; // iloœæ wierzcho³ków x (maks x - min x przez step + 1)
	int zCount = ((zMax - zMin) / stepZ) + 1; // iloœæ wierzcho³ków z
	int alloc = xCount * zCount * 7 * 4; // iloœæ wierzcho³ków x razy z razy 7 wartoœci (x, y, z, R, G, B, A) razy 4
	count = alloc; // iloœæ wierzcho³ków razy wymiarowoœæ wierzcho³ka (wymiarowoœæ wierzcho³ka to 7)
	size = alloc / 7; // iloœæ wierzcho³ków
	float* v = (float*) new float[alloc]; // tablica wierzcho³ków

	int i = 0;
	for (float x = xMin; x < xMax; x+=stepX)
	{
		for (float z = zMin; z < zMax; z += stepZ)
		{
			if (x < xMax - stepX) {
				v[i] = x; i++;
				v[i] = 0; i++;
				v[i] = z; i++;
				v[i] = 0; i++;
				v[i] = 1; i++;
				v[i] = 0; i++;
				v[i] = 1; i++;

				v[i] = x + stepX; i++;
				v[i] = 0; i++;
				v[i] = z; i++;
				v[i] = 0; i++;
				v[i] = 1; i++;
				v[i] = 0; i++;
				v[i] = 1; i++;
			}
			if (z < zMax - stepZ) {
				v[i] = x; i++;
				v[i] = 0; i++;
				v[i] = z; i++;
				v[i] = 0; i++;
				v[i] = 0; i++;
				v[i] = 1; i++;
				v[i] = 1; i++;

				v[i] = x; i++;
				v[i] = 0; i++;
				v[i] = z + stepZ; i++;
				v[i] = 0; i++;
				v[i] = 0; i++;
				v[i] = 1; i++;
				v[i] = 1; i++;
			}
		}
	}
	float lastX = v[i - 7];
	float lastZ = v[i - 5];
	int end = i;

	/*
	Zadanie 1 (1 pkt):
		- zaimplementowaæ metodê, która polega na stworzeniu regularnej siatki wierzcho³ków
		  w p³aszczyŸnie xz pomiêdzy zadanymi wartoœciami brzegowymi i z zadanym skokiem.
		  y ustawiæ na 0. Wierzcho³ek ma mieæ dwa atrybuty: pozycjê (3D) i kolor (RGBA).
		  Ustawiæ odpowiednie wartoœci: size (iloœæ wierzcho³ków), dim - wymiarowoœæ wierzcho³ka, count - size*dim
	*/

	return v;
}

VertexGenerator::VertexGenerator()
{
	

}


VertexGenerator::~VertexGenerator()
{
}
