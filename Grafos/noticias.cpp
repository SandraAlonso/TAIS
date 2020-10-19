#include <iostream>
#include <fstream>
#include "ConjuntosDisjuntos.h"



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N, M;
	// leer los datos de la entrada
	std::cin >> N >> M;
	if (!std::cin)  // fin de la entrada
		return false;
	ConjuntosDisjuntos part(N);
	while (M--) {
		int tam;
		std::cin >> tam;
		if (tam > 0) {
			int prim, otro;
			std::cin >> prim;
			--prim;
			for (int i = 1; i < tam; i++){
				std::cin >> otro;
				--otro;
				part.unir(prim, otro);
			}
		}
		
	}
	for (int i = 0; i < N; i++){
		std::cout << part.tam(i)<<" ";
	}
	std::cout << "\n";


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
