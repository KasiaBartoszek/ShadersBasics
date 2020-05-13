#include "pch.h"
#include "VertexGenerator.h"
#include <iostream>

using namespace std;

float * VertexGenerator::generateVertieces()
{
	float xMin = -4, xMax = 4.1, zMin = -4, zMax = 4.1; // zakres wierzcho�k�w
	float stepX = 0.1, stepZ = 0.1; // skoki mi�dzy wierzcho�kami
	
	int xCount = ((xMax - xMin) / stepX) + 1; // ilo�� wierzcho�k�w x (maks x - min x przez step + 1)
	int zCount = ((zMax - zMin) / stepZ) + 1; // ilo�� wierzcho�k�w z
	int alloc = xCount * zCount * 7 * 4; // ilo�� wierzcho�k�w x razy z razy 7 warto�ci (x, y, z, R, G, B, A) razy 4
	count = alloc; // ilo�� wierzcho�k�w razy wymiarowo�� wierzcho�ka (wymiarowo�� wierzcho�ka to 7)
	size = alloc / 7; // ilo�� wierzcho�k�w
	float* v = (float*) new float[alloc]; // tablica wierzcho�k�w

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
		- zaimplementowa� metod�, kt�ra polega na stworzeniu regularnej siatki wierzcho�k�w
		  w p�aszczy�nie xz pomi�dzy zadanymi warto�ciami brzegowymi i z zadanym skokiem.
		  y ustawi� na 0. Wierzcho�ek ma mie� dwa atrybuty: pozycj� (3D) i kolor (RGBA).
		  Ustawi� odpowiednie warto�ci: size (ilo�� wierzcho�k�w), dim - wymiarowo�� wierzcho�ka, count - size*dim
	*/

	return v;
}

VertexGenerator::VertexGenerator()
{
	

}


VertexGenerator::~VertexGenerator()
{
}
