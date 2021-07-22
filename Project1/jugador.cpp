#include "Jugador.h"
using namespace System;

Jugador::Jugador()
{
	
	x = 80;
	y = 40;
	dx = dy = 1;
	columna = 1; fila = 2;
	cant2 = 0;
	direccion = Direccion::Abajo;
}
Jugador::~Jugador()
{

}

void Jugador::ValidarMovimiento(int **matriz) {
	int X, Y = 0;
	for (int i = 0; i < 10; i++) {
		X = 0;
		for (int j = 0; j < 10; j++) {
			Rectangle c1 = Rectangle(X, Y, 50, 50);
			if (matriz[i][j] == 1 || matriz[i][j] == 3) {
				if (CDI.IntersectsWith(c1))dx = 0;
				if (CAB.IntersectsWith(c1))dy = 0;
			}



			X += 50;
		}
		Y += 50;
	}


}

void Jugador::CrearBala()
{
	Bala **aux = new Bala*[cant2 + 1];

	for (int i = 0; i < cant2; i++)
		aux[i] = balas[i];

	int dx = 0, dy = 0;
	switch (direccion)
	{
	case Direccion::Arriba:  dy = -16; break;
	case Direccion::Abajo:   dy = 16; break;
	case Direccion::Izquierda:  dx = -16; break;
	case Direccion::Derecha:    dx = 16; break;
	}

	aux[cant2] = new Bala(x + ancho / 2, y + alto / 2, dx, dy);

	cant2++;
	balas = aux;
}
void Jugador::EliminarBala(int p)
{
	Bala **aux = new Bala*[cant2 - 1];

	delete balas[p];

	for (int i = 0; i < p; i++)
		aux[i] = balas[i];

	for (int i = p; i < cant2 - 1; i++)
		aux[i] = balas[i + 1];

	cant2--;
	balas = aux;
}
void Jugador::MostrarBalas(Graphics ^g)
{
	for (int i = 0; i < cant2; i++)
		balas[i]->Mostrar(g);
}
void Jugador::MoverBalas()
{
	for (int i = 0; i < cant2; i++)
		balas[i]->Mover();
}

int Jugador::GetCantBalas()
{
	return cant2;
}
Bala* Jugador::GetBala(int i)
{
	return balas[i];
}

void Jugador::Mostrar(Graphics ^g, Bitmap ^img, int **matriz)
{
	CDI = Rectangle(x + 2 * 2 + dx + 5, y + 15 * 2, (ancho - 4) * 2 - 20, (alto - 15) * 2 - 20);
	CAB = Rectangle(x + 2 * 2 + 5, y + 15 * 2 + dy - 5, (ancho - 4) * 2 - 20, (alto - 15) * 2 - 10);

	g->DrawRectangle(Pens::Transparent, CDI);
	g->DrawRectangle(Pens::Transparent, CAB);

	ValidarMovimiento(matriz);


	alto = 32;
	ancho = 25;

	Rectangle porcionAUsar = Rectangle(columna*ancho, fila*alto, ancho, alto);
	Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 2, alto * 2);
	img->MakeTransparent(img->GetPixel(0, 0));
	g->DrawImage(img, aumentoPersonaje, porcionAUsar, GraphicsUnit::Pixel);
	x += dx;
	y += dy;
	dy = 0;
	dx = 0;
}

void Jugador::Mover(Direccion direccion, Graphics ^g)
{
	int mov;
	switch (direccion) {
	case Direccion::Arriba:
		fila = 0;
		mov = 1;
		if (columna >= 0 && columna <= 3) {
			columna+=mov;
			if (columna == 0)
				columna = 2;
			if (columna == 3)
				columna = 0;
		}
		if (y - dy >= 0) {
			dx = 0;
			dy = -5;
		}
		this->direccion = Direccion::Arriba;
		break;
	case Direccion::Abajo:
		fila = 2;
		mov = 1;
		if (columna >= 0 && columna <= 3) {
			columna += mov;
			if (columna == 0)
				columna = 2;
			if (columna == 3)
				columna = 0;
		}
		if (y + dy < 440) {
			dx = 0;
			dy = +5;
		}
		this->direccion = Direccion::Abajo;
		break;
	case Direccion::Derecha:
		fila = 1;
		mov = 1;
		if (columna >= 0 && columna <= 3) {
			columna += mov;
			if (columna == 0)
				columna = 2;
			if (columna == 3)
				columna = 0;
		}
		if (x + dx < 460) {
			dx = +5;
			dy = 0;
		}
		this->direccion = Direccion::Derecha;
		break;
	case Direccion::Izquierda:
		fila = 3;
		mov = 1;
		if (columna >= 0 && columna <= 3) {
			columna += mov;
			if (columna == 0)
				columna = 2;
			if (columna == 3)
				columna = 0;
		}
		if (x - dx >= 0) {
			dx = -5;
			dy = 0;
		}
		this->direccion = Direccion::Izquierda;
		break;
	}
}
