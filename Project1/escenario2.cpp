#include "Escenario2.h"
using namespace System;




Escenario2::Escenario2() {
	matriz2 = new int*[filas];
}

Escenario2::~Escenario2() {}

void Escenario2::generarMatriz2() {
	for (int i = 0; i < filas; i++) {
		matriz2[i] = new int[columnas];
	}
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			matriz2[i][j] = 0;
		}
	}

	matriz2[2][0] = 1;
	matriz2[3][0] = 1;
	matriz2[6][0] = 1;
	matriz2[0][1] = 1;
	matriz2[9][1] = 1;
	matriz2[4][2] = 1;
	matriz2[7][2] = 1;
	matriz2[0][3] = 1;
	matriz2[4][3] = 1;
	matriz2[1][4] = 1;
	matriz2[6][4] = 1;
	matriz2[9][4] = 1;
	matriz2[7][5] = 1;
	matriz2[0][6] = 1;
	matriz2[3][6] = 1;
	matriz2[5][6] = 1;
	matriz2[9][6] = 1;
	matriz2[6][7] = 1;
	matriz2[7][7] = 1;
	matriz2[1][8] = 1;
	matriz2[2][8] = 1;
	matriz2[4][9] = 1;
	matriz2[5][9] = 1;
	matriz2[8][9] = 1;
	matriz2[3][1] = 3;
	matriz2[8][1] = 3;
	matriz2[6][2] = 3;
	matriz2[1][3] = 3;
	matriz2[8][3] = 3;
	matriz2[4][4] = 3;
	matriz2[2][5] = 3;
	matriz2[8][6] = 3;
	matriz2[1][7] = 3;
	matriz2[4][7] = 3;
	matriz2[9][9] = 3;
}

void Escenario2::DibujarMatriz2(Graphics^g, Bitmap^bmpEdificio, Bitmap^bmpSuelo, Bitmap^bmpFuente) {
	int X, Y = 0;
	for (int i = 0; i < filas; i++) {
		X = 0;
		for (int j = 0; j < columnas; j++) {
			if (matriz2[i][j] == 1) {
				g->DrawImage(bmpEdificio, X, Y, 50, 50);
				X += 50;
			}
			if (matriz2[i][j] == 3) {
				g->DrawImage(bmpFuente, X, Y, 50, 50);
				X += 50;
			}
			if (matriz2[i][j] == 0) {
				g->DrawImage(bmpSuelo, X, Y, 50, 50);
				X += 50;
			}
		}
		Y += 50;
	}
}

int** Escenario2::getmatriz2() {
	return matriz2;
}