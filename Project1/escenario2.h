#pragma once
#include <ctime>
#include <cstdlib>
#define columnas 10
#define filas 10
using namespace System::Drawing;
class Escenario2
{

private:

	int** matriz2;

public:



	Escenario2();
	~Escenario2();
	void generarMatriz2();
	void DibujarMatriz2(Graphics^g, Bitmap^bmpEdificio, Bitmap^bmpSuelo, Bitmap^bmpFuente);
	int** getmatriz2();
};


