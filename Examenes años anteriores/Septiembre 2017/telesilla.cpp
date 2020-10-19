
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int resolver(std::vector<int> const&v, int pesoMax) {
	int i = 0, j=v.size() - 1, cont=0;
	while (i <=j) {
		if (v[i] + v[j] <= pesoMax) {//entran en el asiento
			i++;
			j--;
		}
		else {
			j--;
		}
		cont++;
	}
	return cont;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int pesoMax, tam;
	std::cin >> pesoMax >> tam;
	if (!std::cin)  // fin de la entrada
		return false;
	std::vector<int>v(tam);
	for (int&n : v)
		std::cin >> n;
	std::sort(v.begin(), v.end(), std::less<int>());//Ordenamos de menor a mayor el vector
	int sol = resolver(v, pesoMax);
	std::cout << sol << std::endl;
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
