#include <iostream>
#include <fstream>
#include "Camion.h"

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int intersecciones, calles, a1, a2, valor, consultas;
	// leer los datos de la entrada
	std::cin >> intersecciones >> calles;
	if (!std::cin)  // fin de la entrada
		return false;
	GrafoValorado<int>g(intersecciones);
	for (int i = 0; i < calles; i++) {
		std::cin >> a1 >> a2 >> valor;
		g.ponArista({ a1 - 1, a2 - 1, valor });
	}
	std::cin >> consultas;
	for (int i = 0; i < consultas; i++) {
		std::cin >> a1 >> a2 >> valor;
		Camion c(g, a1 - 1, valor);
		if (c.hayCamino(a2 - 1) && c.elCamionPasa(a2 - 1))
			std::cout << "SI" << std::endl;
		else
			std::cout << "NO" << std::endl;	
	}

	// escribir sol

	return true;
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
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
