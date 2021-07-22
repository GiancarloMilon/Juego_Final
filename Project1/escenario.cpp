#include "Escenario.h"
using namespace System;




Escenario::Escenario() {
		matriz = new int*[filas];
	}

Escenario::~Escenario(){}

void Escenario::generarMatriz() {
	for (int i = 0; i < filas; i++) {
		matriz[i] = new int[columnas];
	}
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			matriz[i][j] = 0;
		}
	}
	for (int i = 0; i < 10; i++) {
		matriz[0][i] = 1;
	}
	matriz[6][9] = 1;
	matriz[3][9] = 1;
	matriz[3][0] = 1;
	matriz[1][0] = 1;
	matriz[1][9] = 1;
	matriz[2][0] = 1;
	matriz[3][6] = 1;
	matriz[4][4] = 1;
	matriz[4][7] = 1;
	matriz[5][0] = 1;
	matriz[5][1] = 1;
	matriz[6][0] = 1;
	matriz[7][0] = 1;
	matriz[7][9] = 1;
	matriz[8][6] = 1;
	matriz[8][9] = 1;
	matriz[9][0] = 1;
	matriz[9][1] = 1;
	matriz[9][2] = 1;
	matriz[9][6] = 1;
	matriz[9][8] = 1;
	matriz[9][9] = 1;
	matriz[9][3] = 1;
	matriz[7][4] = 3;
	matriz[1][5] = 3;
	matriz[4][1] = 3;
	matriz[4][6] = 3;
	matriz[8][0] = 3;
	matriz[9][7] = 3;
	matriz[5][2] = 3;
	matriz[5][9] = 3;
	matriz[9][5] = 3;
	matriz[9][4] = 3;
	matriz[4][0] = 3;
	matriz[2][9] = 3;
	matriz[4][9] = 3;
}

void Escenario::DibujarMatriz(Graphics^g, Bitmap^bmpBase, Bitmap^bmpSolido, Bitmap^bmpDestruible) {
	int X, Y = 0;
	for (int i = 0; i < filas; i++) {
		X = 0;
		for (int j = 0; j < columnas; j++) {
			if (matriz[i][j] == 1) {
				g->DrawImage(bmpSolido, X, Y, 50, 50);
				X += 50;
			}
			if (matriz[i][j] == 3) {
				g->DrawImage(bmpDestruible, X, Y, 50, 50);
				X += 50;
			}
			if (matriz[i][j] == 0) {
				g->DrawImage(bmpBase, X, Y, 50, 50);
				X += 50;
			}
		}
		Y += 50;
	}
}

int** Escenario::getmatriz() {
	return matriz;
}