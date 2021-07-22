#include "Bonus.h"
#include <cstdlib>
#include <ctime>

using namespace System;
using namespace System::Drawing;

Bonus::Bonus()
{
	Random f;
	x = f.Next(100, 400);
	System::Threading::Thread::Sleep(10);
	y = f.Next(200, 400);
	System::Threading::Thread::Sleep(10);

	fila = columna = 1;
	posicion = rand() % 4;
	conta = 0;

}

void Bonus::dibujar(Graphics ^g, Bitmap ^img)
{
	alto = 32;
	ancho = 25;

	Rectangle porcionAUsar = Rectangle(columna*ancho, fila*alto, ancho, alto);
	Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 2, alto * 2);
	img->MakeTransparent(img->GetPixel(0, 0));
	g->DrawImage(img, aumentoPersonaje, porcionAUsar, GraphicsUnit::Pixel);

	if (columna >= 0 || columna <= 2) {
		columna++;
		if (columna == 2)
			columna = 0;
	}
}

void Bonus::moverBonus(Graphics ^g) {

	switch (posicion) {
	case 0:

		fila = 0;
		if (columna >= 0 || fila <= 2) {
			columna++;
			conta++;
			if (columna == 2)
				columna = 0;
			if (conta == 20) {
				posicion = rand() % 4;
				conta = 0;
			}
		}
		break;
	case 1:
		fila = 1;
		if (columna >= 0 || columna <= 2) {
			columna++;
			conta++;
			if (columna == 2)
				columna = 0;
			if (conta == 20) {
				posicion = rand() % 4;
				conta = 0;
			}
		}
		break;
	case 2:
		fila = 2;
		if (columna >= 0 || columna <= 2) {
			columna++;
			conta++;
			if (columna == 2)
				columna = 0;
			if (conta == 20) {
				posicion = rand() % 4;
				conta = 0;
			}
		}
		break;

	case 3:
		fila = 3;
		if (columna >= 0 || columna <= 2) {
			columna++;
			conta++;
			if (columna == 2)
				columna = 0;
			if (conta == 20) {
				posicion = rand() % 4;
				conta = 0;
			}
		}
		break;
	}
};