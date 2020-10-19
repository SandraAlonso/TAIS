#include <iostream>
#include <fstream>
#include "GrafoValorado.h"
#include "Puente.h"


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int numIslas, puentes, a1, a2, valor;
	// leer los datos de la entrada
	std::cin >> numIslas >> puentes;
	if (!std::cin)  // fin de la entrada
		return false;
	GrafoValorado <int> g(numIslas);
	puente p(g, numIslas, puentes);
	std::cout<<p.solucion()<<std::endl;


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
