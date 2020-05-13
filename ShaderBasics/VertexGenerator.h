#pragma once
class VertexGenerator
{
private:
	int size = 0;
	int count = 0;
	int dim = 0;
	
public:
	
	float* generateVertieces(/*...*/);
	VertexGenerator();
	~VertexGenerator();
	int Size() { return size; }
	int Count() { return count; }
	int Dim() { return dim; }
};

