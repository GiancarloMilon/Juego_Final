#include "Entidad.h"
#include "Bala.h"

using namespace System::Drawing;

class Bonus : public Entidad {
private:
	int conta;
public:
	Bonus();
	void dibujar(Graphics ^g, Bitmap ^img);
	void moverBonus(Graphics ^g);
};