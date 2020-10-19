
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "mc.h"

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int intersecciones, calles, a1, a2, valor;
	// leer los datos de la entrada
	std::cin >> intersecciones >> calles;
	if (!std::cin)  // fin de la entrada
		return false;
	GrafoValorado<int> g(intersecciones);
	for (int i = 0; i < calles; i++) {
		std::cin >> a1 >> a2 >> valor;
		g.ponArista({ a1 - 1, a2 - 1, valor });
	}
	int casos, v, w;
	std::cin >> casos;
	for (int i = 0; i < casos; i++) {
		std::cin >> v >> w;
		MenorCamino c(g, v - 1);

		if (c.hayCamino(w - 1)) {
			std::cout << c.valor(w - 1);
			if (c.soniguales(w-1))
				std::cout << " SI" << std::endl;
			else
				std::cout << " NO" << std::endl;
		}
		else std::cout << "SIN CAMINO" << std::endl;
	}
	std::cout << "---" << std::endl;

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
