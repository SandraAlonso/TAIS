//Sandra Alonso Paz
//TAIS05
//Coste del algoritmo: O(V+E) => O(C+N)
#include <iostream>
#include <iomanip>
#include <fstream>
#include "NodoLejano.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int N, C, TTL, origen, v, w, n;
	std::cin >> N >> C;
	if (!std::cin)
		return false;
	Grafo g(N);
	for (int i = 0; i < C; ++i) {
		std::cin >> v >> w;
		g.ponArista(v-1, w-1);
	}
	std::cin >> n;
	for (int j = 0; j < n; ++j) {
		std::cin >> origen >> TTL;
		std::cout<<NodoLejano(g, origen-1, TTL).sonInalcanzables()<<'\n';
		
	}
	std::cout << "---\n";
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}