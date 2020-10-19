
// Nombre y Apellidos Sandra Alonso Paz

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Matriz.h"
struct tDatos {
	int tiempo;
	int monedas;
};
/*
	Llamada inicial: tesoro(i, j) siendo i el numero de cofre y j el tiempo.
	Llamada recursiva: tesoro (i, j)= max(tesoro(i-1, j), tesoro(i, j-cofre[i].tiempo)+cofre[i].monedas.
	Casos base: tesoro(0, j) y tesoro(i, 0).
	Parametros: 0<=i<=cofres, 0<=j<=t.
	Coste en tiempo y espacio: cofres* tiempo.
	*/

int tesoro(Matriz<int> matriz, std::vector<tDatos> cofres, int c, int t, std::vector<tDatos>&sol) {
	matriz[0][0] = 0;
	for (int i = 1; i < c+1; i++) {
		matriz[i][0] = 0;
		for (int j = 1; j < t+1; j++) {
			matriz[0][j] = 0;
			if (cofres[i - 1].tiempo > j) 
				matriz[i][j] = matriz[i - 1][j];
			else
				matriz[i][j] = std::max(matriz[i - 1][j], matriz[i - 1][j - cofres[i - 1].tiempo] + cofres[i - 1].monedas);
		}
	}
	int j = t;
	for (int i = c; i > 0; i--) {
		if (matriz[i - 1][j] < matriz[i][j]) {
			j -= cofres[i-1].tiempo;
			sol.push_back(cofres[i-1]);
		}
	}
	return matriz[c][t];
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int tiempo, cofres, t;
	// leer los datos de la entrada
	std::cin >> tiempo >> cofres;
	if (!std::cin)  // fin de la entrada
		return false;
	Matriz <int> matriz(cofres + 1, tiempo + 1);
	std::vector<tDatos> v(cofres);
	std::vector<tDatos> sol;
	
	for (int i = 0; i < cofres; i++) {
		std::cin >> t >> v[i].monedas;
		v[i].tiempo = t * 3;

	}
	int sol1 = tesoro(matriz, v, cofres, tiempo, sol);
	// escribir sol
	std::cout << sol1 << std::endl;
	std::cout << sol.size() << std::endl;
	for (int i=sol.size()-1;i>=0;i--)
		std::cout << sol[i].tiempo/3 << " " << sol[i].monedas << std::endl;
	std::cout<<"---"<<std::endl;
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
