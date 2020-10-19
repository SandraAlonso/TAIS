
// Nombre y Apellidos Sandra Alonso Paz

// Comentario general sobre la solución, O(N*LOG(N))

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int numPartidos;
	// leer los datos de la entrada
	std::cin >> numPartidos;
	if (numPartidos == 0)
		return false;
	std::vector<int>r(numPartidos);
	std::vector<int>b(numPartidos);
	for (int i = 0; i < numPartidos; ++i) {
		std::cin >> r[i];
	}
	for (int i = 0; i < numPartidos; ++i) {
		std::cin >> b[i];
	}
	std::sort(r.begin(), r.end(), std::less<int>());//ordenado de menor a mayor
	std::sort(b.begin(), b.end(), std::greater<int>());//ordenado de mayor a menor
	int sol = 0, i = 0;
	bool correcto = true;
	while (correcto &&i < numPartidos) {
		if (b[i] > r[i]) {
			sol += (b[i] - r[i]);
		}
		else
			correcto = false;
		++i;
	}

	// escribir sol
	std::cout << sol << "\n";
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
