#pragma once
#include "Entidad.h"
#include "Bala.h"

using namespace System::Drawing;
class Jugador : public Entidad
{
private:
	Direccion direccion;
	Bala **balas;
	Rectangle CDI;
	Rectangle CAB;
	int cant2;
public:
	Jugador();
	~Jugador();

	void CrearBala();
	void EliminarBala(int p);
	void MostrarBalas(Graphics ^g);
	void MoverBalas();
	void ValidarMovimiento(int **matriz);
	Bala* GetBala(int i);
	int GetCantBalas();

	void Mostrar(Graphics ^g, Bitmap ^img, int **matriz);
	void Mover(Direccion direccion, Graphics ^g);
};

