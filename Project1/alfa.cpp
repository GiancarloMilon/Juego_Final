#include "Alfa.h"
using namespace System;
using namespace System::Drawing;
Alfa::Alfa()
{
	Random j;
	x = j.Next(100, 400);
	System::Threading::Thread::Sleep(10);
	y = j.Next(200, 400);
	System::Threading::Thread::Sleep(10);
	dx = dy = 2;
	fila = columna = 1;
}
Alfa::~Alfa()
{

}

void Alfa::Mostrar(Graphics ^g, Bitmap ^img)
{

	alto = 32;
	ancho = 25;

	Rectangle porcionAUsar = Rectangle(columna*ancho, fila*alto, ancho, alto);
	Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 2, alto * 2);
	img->MakeTransparent(img->GetPixel(0, 10));
	g->DrawImage(img, aumentoPersonaje, porcionAUsar, GraphicsUnit::Pixel);

	if (columna >= 0 || columna <= 2) {
		columna++;
		if (columna == 2)
			columna = 0;
	}

}
void Alfa::Mover(Direccion direccion, Graphics ^g)
{
	switch (direccion)
	{
	case Direccion::Arriba:

		fila = 0;
		if (y - dy >= 0)
			y -= dy;

		break;

	case Direccion::Abajo:
		fila = 2;
		if (y + alto + dy <= 480)
			y += dy;
		break;
	case Direccion::Izquierda:
		fila = 3;
		if (x - dx >= 0)
			x -= dx;
		break;

	case Direccion::Derecha:
		fila = 1;
		if (x + ancho + dx <= 500)
			x += dx;
		break;
	}
}