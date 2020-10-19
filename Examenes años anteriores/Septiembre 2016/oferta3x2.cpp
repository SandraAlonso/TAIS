#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int resolver(std::vector<int> const&v) {
	int i = 0, ahorro=0;
	while (i +2< v.size()) {
		ahorro+=v[i + 2];
		i += 3;
	}
	return ahorro;
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int tam;
	// leer los datos de la entrada
	std::cin >> tam;
	if (!std::cin)  // fin de la entrada
		return false;
	std::vector<int> v(tam);
	for (int&n:v)
		std::cin >> n;
	std::sort(v.begin(), v.end(), std::greater<int>());
	int sol = resolver(v);
	std::cout << sol << std::endl;

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
