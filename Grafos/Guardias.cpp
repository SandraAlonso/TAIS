
// Sandra Alonso Paz
//Coste: numero de aristas + numero de vertices.

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema
//COSTE TOTAL COMPROBADO ES EL NUMERO DE VERTICES MAS EL NUMERO DE ARISTAS.
#include <iostream>
#include <fstream>
#include "Guardias.h"


// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int aristas, vertices, a, v;
	std::cin >> vertices >> aristas;
	if (!std::cin)  // fin de la entrada
		return false;
	Grafo g(vertices);
	for (int i = 0; i < aristas; ++i) {
		std::cin >> a;
		std::cin >> v;
		g.ponArista(a -1, v -1);
	}
	Guardias gu (g);
	if (gu.esPosible())
		std::cout << gu.numGuardias(g)<<"\n";
	else
		std::cout << "IMPOSIBLE\n";
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
