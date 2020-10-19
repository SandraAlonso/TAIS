
#include <iostream>
#include <fstream>
#include <vector>


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int  longitud, numAgujeros, agujero, sol=1, j=1, comienzo;
	// leer los datos de la entrada
	std::cin >> numAgujeros>> longitud;
	if (!std::cin)  // fin de la entrada
		return false;
	std::vector<int> manguera;
	for (int i = 0; i < numAgujeros; i++){
		std::cin >> agujero;
		manguera.push_back(agujero);
	}
	comienzo = manguera[0];
	while(j<manguera.size()) {
		if (manguera[j] - comienzo > longitud) {
			comienzo = manguera[j];
			sol++;
			
		}
		j++;
	}
	
	std::cout << sol << '\n';
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
