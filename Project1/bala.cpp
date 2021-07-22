#include "Bala.h"

Bala::Bala(int x, int y, int dx, int dy)
{
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;

	ancho = alto = 10;
}
Bala::~Bala()
{
}
void Bala::Mostrar(Graphics ^g)
{
	g->FillEllipse(Brushes::Black, x, y, ancho, alto);
}
void Bala::Mover()
{
	x += dx;
	y += dy;
}