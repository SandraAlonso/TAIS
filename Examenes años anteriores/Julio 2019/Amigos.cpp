#include <iostream>
#include <fstream>
#include "ConjuntosDisjuntos.h"
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int amigos, grupos, personas, id, id2;
	// leer los datos de la entrada
	std::cin >> amigos >> grupos;
	if (!std::cin)  // fin de la entrada
		return false;
	ConjuntosDisjuntos c(amigos);
	for (int i = 0; i < grupos; i++) {
		std::cin >> personas;
		if (personas > 0) {
			std::cin >> id;
			for (int j = 0; j < personas-1; j++) {
				std::cin >> id2;
				c.unir(id - 1, id2 - 1);

			}
		}
	}
	for (int i = 0; i < amigos; i++) {
		std::cout<<c.tam(i)<<" ";
	}
	std::cout << std::endl;

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
