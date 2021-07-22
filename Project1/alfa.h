#pragma once
#include "Entidad.h"
#include <ctime>
#include <cstdlib>

class Alfa :public Entidad {
public:
	Alfa();
	~Alfa();

	void Mostrar(Graphics ^g, Bitmap ^img);
	void Mover(Direccion direccion, Graphics ^g);
};

