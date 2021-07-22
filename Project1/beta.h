#include <ctime>
#include <cstdlib>
#include "Entidad.h"

using namespace System::Drawing;
using namespace System;

class Beta :public Entidad{

public:
	//
	Beta();
	//
	~Beta() {}
	//
	void MostrarB(Graphics^ g, Bitmap^ bmpEnemigo);
	void moverB(Graphics ^g);
};


