#include <iostream>
#include <fstream>
#include "Libre.h"


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int vertices, aristas, a1, a2;
	// leer los datos de la entrada
	std::cin >> vertices >> aristas;
	if (!std::cin)  // fin de la entrada
		return false;
	if (vertices == aristas + 1) {//SOLO ENTONCES SERA ACICLICO
		Grafo g(vertices);
		for (int i = 0; i < aristas; i++) {
			std::cin >> a1 >> a2;
			g.ponArista(a1, a2);
			
		}
		Libre l(g, 0);
		if(l.esLibre())
			std::cout << "SI" << std::endl;
		else
			std::cout << "NO" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}

	// escribir sol

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
