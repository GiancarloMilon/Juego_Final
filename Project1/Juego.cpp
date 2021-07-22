#include "Juego.h"

Juego::Juego()
{
	oEscenario = new Escenario();
	oEscenario2 = new Escenario2();
	jugador = new Jugador();
	Hadas = new Bonus();
	cant = 0;
	cant1 = 0;
	puntos = 0;
	nivel = 0;
	Alfas = new Alfa*[cant];
	Betas = new Beta*[cant1];
	AgregarAlfas();
	AgregarBetas();
	algo = true;
	vidas = 3;
}

Juego::~Juego()
{

}



void Juego::CambiarNivel(){
	oEscenario->generarMatriz();
}
void Juego::dibujar(Graphics^g, Bitmap^bmpBase, Bitmap^bmpSolido, Bitmap^bmpDestruible){
	oEscenario->DibujarMatriz(g, bmpBase, bmpSolido, bmpDestruible);
}

void Juego::CambiarNivel2() {
	oEscenario2->generarMatriz2();
}
void Juego::dibujar2(Graphics^g, Bitmap^bmpEdificio, Bitmap^bmpSuelo, Bitmap^bmpFuente) {
	oEscenario2->DibujarMatriz2(g, bmpEdificio, bmpSuelo, bmpFuente);
}



int Juego::Get_Nivel() {
	return nivel;
}

void Juego::Disparar()
{
	jugador->CrearBala();
}

void Juego::MoverJugador(Keys key, Graphics ^g)
{
	if (key == Keys::Up)
		jugador->Mover(Direccion::Arriba, g);
	else if (key == Keys::Down)
		jugador->Mover(Direccion::Abajo, g);
	else if (key == Keys::Left)
		jugador->Mover(Direccion::Izquierda, g);
	else if (key == Keys::Right)
		jugador->Mover(Direccion::Derecha, g);
}
void Juego::MostrarJugador(Graphics ^g, Bitmap ^img, int nivel)
{
	
	jugador->MostrarBalas(g);

	if (nivel == 1) {
		jugador->Mostrar(g, img, oEscenario->getmatriz());
	}
	else if (nivel == 2) {
		jugador->Mostrar(g, img, oEscenario2->getmatriz2());
	}

}

void Juego::MoverAlfas(Graphics ^g)
{
	for (int i = 0; i < cant; i++)
	{
		if (Alfas[i]->GetX() > jugador->GetX())
			Alfas[i]->Mover(Direccion::Izquierda, g);
		else if (Alfas[i]->GetX() < jugador->GetX())
			Alfas[i]->Mover(Direccion::Derecha, g);

		if (Alfas[i]->GetY() > jugador->GetY())
			Alfas[i]->Mover(Direccion::Arriba, g);
		else if (Alfas[i]->GetY() < jugador->GetY())
			Alfas[i]->Mover(Direccion::Abajo, g);
	}
}
void Juego::moverBalas() {
	jugador->MoverBalas();
}
void Juego::MoverBetas(Graphics ^g)
{
	for (int i = 0; i < cant1; i++)
		Betas[i]->moverB(g);
}
void Juego::DibujarHada(Graphics ^g, Bitmap^img)
{
	Hadas->dibujar(g, img);
}
void Juego::MoverHada(Graphics ^g)
{
	Hadas->moverBonus(g);
}
void Juego::MostrarAlfas(Graphics ^g, Bitmap ^img)
{
	for (int i = 0; i < cant; i++)
		Alfas[i]->Mostrar(g, img);
}
void Juego::MostrarBetas(Graphics ^g, Bitmap ^img) {
	for (int i = 0; i < cant1; i++)
		Betas[i]->MostrarB(g, img);
}

void Juego::AgregarAlfas()
{
	srand(time(NULL));
	int hola;
	hola = rand() % 10 + 5;
	for (int m = 0; m < hola; m++)
	{

		Alfa **aux = new Alfa*[hola];

		for (int i = 0; i < cant; i++)
			aux[i] = Alfas[i];

		aux[cant] = new Alfa();

		Alfas = aux;
		cant++;
	}
}

void Juego::AgregarBetas() {
	srand(time(NULL));
	int hola1;
	hola1 = rand()%10+5;
	for (int m = 0; m < hola1; m++)
	{

		Beta **aux1 = new Beta*[hola1];

		for (int i = 0; i < cant1; i++)
			aux1[i] = Betas[i];

		aux1[cant1] = new Beta();

		Betas = aux1;
		cant1++;
	}
}

void Juego::EliminarAlfas(int n)
{
	Alfa **aux = new Alfa*[cant - 1];
	delete Alfas[n];
	for (int i = 0; i < n; i++)
		aux[i] = Alfas[i];
	for (int i = n; i < cant - 1; i++)
		aux[i] = Alfas[i + 1];
	cant--;
	Alfas = aux;
}

void Juego::EliminarBetas(int n)
{
	Beta **aux = new Beta*[cant1 - 1];
	delete Betas[n];
	for (int i = 0; i < n; i++)
		aux[i] = Betas[i];
	for (int i = n; i < cant1 - 1; i++)
		aux[i] = Betas[i + 1];
	cant1--;
	Betas = aux;
}

void Juego::Colisiones()
{
	Rectangle bala;
	Rectangle Enemigo;
	Rectangle Enemigo1;
	Rectangle Yo;

	Bala *BALA;
inicio:
	for (int b = 0; b < jugador->GetCantBalas(); b++)
	{
		BALA = jugador->GetBala(b);
		Yo = Rectangle(jugador->GetX(), jugador->GetY(), jugador->GetAncho(), jugador->GetAlto());
		bala = Rectangle(BALA->GetX(), BALA->GetY(), BALA->GetAncho(), BALA->GetAlto());
		for (int e = 0; e < cant; e++) {
			Enemigo = Rectangle(Alfas[e]->GetX(), Alfas[e]->GetY(), Alfas[e]->GetAncho(), Alfas[e]->GetAlto());
			if (bala.IntersectsWith(Enemigo))
			{
				EliminarAlfas(e);
				jugador->EliminarBala(b);
				puntos += 5;
				goto inicio;
			}
		}
		for (int e = 0; e < cant1; e++) {
			Enemigo1 = Rectangle(Betas[e]->GetX(), Betas[e]->GetY(), Betas[e]->GetAncho(), Betas[e]->GetAlto());
			if (bala.IntersectsWith(Enemigo1))
			{
				EliminarBetas(e);
				jugador->EliminarBala(b);
				puntos += 3;
				goto inicio;
			}
		}
	}
	for (int e = 0; e < cant; e++)
	{
		Enemigo = Rectangle(Alfas[e]->GetX(), Alfas[e]->GetY(), Alfas[e]->GetAncho(), Alfas[e]->GetAlto());
		Yo = Rectangle(jugador->GetX(), jugador->GetY(), jugador->GetAncho(), jugador->GetAlto());
		if (Yo.IntersectsWith(Enemigo))
		{
			EliminarAlfas(e);
			if (vidas>0)
			vidas -=1;
			goto inicio;
		}
	}
	for (int e = 0; e < cant1; e++) {
		Enemigo1 = Rectangle(Betas[e]->GetX(), Betas[e]->GetY(), Betas[e]->GetAncho(), Betas[e]->GetAlto());
		Yo = Rectangle(jugador->GetX(), jugador->GetY(), jugador->GetAncho(), jugador->GetAlto());
		if (Yo.IntersectsWith(Enemigo1))
		{
			EliminarBetas(e);
			if (vidas>0)
			vidas -= 1;
			goto inicio;
		}
	}
}
void Juego::Colisiones1()
{
	Rectangle Yo;
	Rectangle Hada;
	Yo = Rectangle(jugador->GetX(), jugador->GetY(), jugador->GetAncho(), jugador->GetAlto());
	Hada = Rectangle(Hadas->GetX(), Hadas->GetY(), Hadas->GetAncho(), Hadas->GetAlto());
	if (Yo.IntersectsWith(Hada)) {
		if (vidas<=3 && algo == true)
		vidas += 1;
		algo = false;
	}
}
bool Juego::Get_algo() {
	Colisiones1();
	return algo;
}
int Juego::Get_vidas() {
	Colisiones1();
	return vidas;
}
int Juego::Get_Puntos() {
	return puntos;
}
int Juego::GetEnemigos()
{
	return cant;
}
int Juego::GetEnemigos1()
{
	return cant1;
}
