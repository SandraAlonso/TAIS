#include <iostream>
#include <fstream>
#include <algorithm>
#include "Matriz.h"

struct tSol {
	int total;
	int principio;
};

tSol tablero(Matriz<int> matriz, int filas) {
	Matriz <int>m(filas, filas);
	for (int j = 0; j < filas; j++)
		m[0][j] = matriz[0][j];
	for (int i = 1; i < filas; i++) {
		for (int j = 0; j < filas; j++) {
			if (j > 0 && j < filas - 1) {
				m[i][j] = std::max(m[i - 1][j + 1], m[i - 1][j - 1]) + matriz[i][j];

			}
			else if (j == 0) m[i][j] = m[i - 1][j + 1] + matriz[i][j];

			else {
				m[i][j] = m[i - 1][j - 1] + matriz[i][j];

			}
		}
	}
	int max = 0, columna;
	for (int i = 0; i < filas; i++) {
		if (m[filas - 1][i] > max) {
			max = m[filas - 1][i];
			columna = i;
		}
	}
	return{ max, columna + 1 };
}



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int filas;
	// leer los datos de la entrada
	std::cin >> filas;
	if (!std::cin)  // fin de la entrada
		return false;
	Matriz <int>matriz(filas, filas);
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < filas; j++) {
			std::cin >> matriz[i][j];
		}
	}
	tSol sol = tablero(matriz, filas);
	std::cout << sol.total << " " << sol.principio << std::endl;
	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
