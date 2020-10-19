#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
//El coste de la solucion es O(N*Log(N)) Siendo N el numero de personas.
//El coste del algoritmo voraz es O(N) porque recorremos todos los elementos del vector una sola vez.
//Si el elemento mas pesado no es compatible con el elemento de menor peso, no lo sera con ninguno.

// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(std::vector<int> const&v, int pesoM) {
	int i = 0; //Iterador que apunta al inicio del vector
	int j = v.size() - 1; //Iterador que apunta al final del vector
	int cont = 0; //Numero de sillas que necesitaremos.
	while (i <= j) {//Recorremos todo el vector para comprobar las parejas compatibles
		if (v[i] + v[j] <= pesoM) {//Entran las dos personas en la silla
			++i;
			--j;
		}
		else//Solo entra el de mas peso en la silla
			--j;
		++cont;
	}
	return cont;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int peso_maximo, N;
	// leer los datos de la entrada
	std::cin >> peso_maximo >> N;
	if (!std::cin)  // fin de la entrada
		return false;
	std::vector<int>telesilla(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> telesilla[i];
	}
	std::sort(telesilla.begin(), telesilla.end(), std::less<int>());//Ordenamos de menor a mayor el vector
	int sol = resolver(telesilla, peso_maximo);
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
