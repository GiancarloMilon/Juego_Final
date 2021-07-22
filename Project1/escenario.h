#pragma once
#include <ctime>
#include <cstdlib>
#define columnas 10
#define filas 10
using namespace System::Drawing;
class Escenario
{

private :
	
	int** matriz;

public:
	


	Escenario();
	~Escenario();
	void generarMatriz();
	void DibujarMatriz(Graphics^g, Bitmap^bmpBase, Bitmap^bmpSolido, Bitmap^bmpDestruible);
	int** getmatriz();
};


