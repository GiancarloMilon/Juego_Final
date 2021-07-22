#include "Beta.h"
 Beta::Beta() {
	Random f;
	x = f.Next(100, 400);
	System::Threading::Thread::Sleep(10);
	y = f.Next(200, 400);
	System::Threading::Thread::Sleep(10);
	dx = 0;
	dy = 0;
	columna = 1;
	fila = 1;
	ancho = 25;
	alto = 32;
	posicion = rand() % 4;
}
void Beta::MostrarB(Graphics^ g, Bitmap^ bmpBeta) {
	alto = 32;
	ancho = 25;

	Rectangle porcionAUsar = Rectangle(columna*ancho, fila*alto, ancho, alto);
	Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 2, alto * 2);
	bmpBeta->MakeTransparent(bmpBeta->GetPixel(0, 0));
	g->DrawImage(bmpBeta, aumentoPersonaje, porcionAUsar, GraphicsUnit::Pixel);
	x += dx;
	y += dy;
}

void Beta::moverB(Graphics ^g) {
	switch (posicion) {
	case 0:

		fila = 0;
		if (columna >= 0 || fila <= 2) {
			columna++;
			if (columna == 2)
				columna = 0;
			if (y + dy < 0)
				posicion = 2;
		}
		dx = 0;
		dy = -10;
		break;
	case 1:
		fila = 1;
		if (columna >= 0 || columna <= 2) {
			columna++;
			if (columna == 2)
				columna = 0;
			if (x + dx > 450)
				posicion = 3;
		}
		dx = +10;
		dy = 0;
		break;
	case 2:
		fila = 2;
		if (columna >= 0 || columna <= 2) {
			columna++;
			if (columna == 2)
				columna = 0;
			if (y + dy > 440)
				posicion = 0;
		}
		dx = 0;
		dy = +10;
		break;

	case 3:
		fila = 3;
		if (columna >= 0 || columna <= 2) {
			columna++;
			if (columna == 2)
				columna = 0;
			if (x + dx < 0)
				posicion = 1;
		}
		dx = -10;
		dy = 0;
		break;
	}
}
