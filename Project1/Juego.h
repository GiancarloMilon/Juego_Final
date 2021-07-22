#pragma once
#include "Jugador.h"
#include "Alfa.h"
#include "Bonus.h"
#include "Beta.h"
#include "Escenario.h"
#include "Escenario2.h"
#include <ctime>
#include <cstdlib>

using namespace System::Windows::Forms;
class Juego
{
private:
	Jugador *jugador;
	Alfa **Alfas;
	Beta **Betas;
	Bonus *Hadas;
	Escenario *oEscenario;
	Escenario2 *oEscenario2;
	int cant;
	int cant1;
	int puntos;
	int nivel;
	bool algo;
	int vidas;
public:

	Juego();
	~Juego();

	int Get_Nivel();
	void CambiarNivel();
	void dibujar(Graphics^g, Bitmap^bmpBase, Bitmap^bmpSolido, Bitmap^bmpDestruible);

	void CambiarNivel2();
	void dibujar2(Graphics^g, Bitmap^bmpEdificio, Bitmap^bmpSuelo, Bitmap^bmpFuente);

	void AgregarAlfas();
	void AgregarBetas();

	void MoverJugador(Keys key, Graphics ^g);
	void MostrarJugador(Graphics ^g, Bitmap ^img, int nivel);

	void moverBalas();
	void MoverAlfas(Graphics ^g);
	void MostrarAlfas(Graphics ^g, Bitmap ^img);
	void MoverBetas(Graphics ^g);
	void MostrarBetas(Graphics ^g, Bitmap^img);

	void DibujarHada(Graphics ^g, Bitmap^img);
	void MoverHada(Graphics ^g);


	void Disparar();
	void Colisiones();
	void Colisiones1();

	
	void EliminarAlfas(int n);
	void EliminarBetas(int n);

	int GetEnemigos();
	int GetEnemigos1();
	int Get_Puntos();
	bool Get_algo();
	int Get_vidas();
};

