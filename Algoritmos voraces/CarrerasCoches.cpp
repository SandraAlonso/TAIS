
// Nombre y Apellidos Sandra Alonso Paz

// Comentario general sobre la solución,0(N*LOG(N)) siendo N el numero de pilas.

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>


// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...
int resolver(std::vector<int> const&v, int pesoM) {
	int i = 0; //Iterador que apunta al inicio del vector
	int j = v.size() - 1; //Iterador que apunta al final del vector
	int cont = 0; //Numero de coches que cargaremos
	while (i < j) {//Recorremos todo el vector para comprobar las parejas de pilas compatibles
		if (v[i] + v[j] >= pesoM) {//Llenan la carga minima
			++i;
			--j;
			++cont;
		}
		else//No es compatible la mas pequeña con ninguna
			++i;
	}
	return cont;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int pila_minima, N;
	// leer los datos de la entrada
	std::cin >>  N >> pila_minima;
	std::vector<int>pilas(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> pilas[i];
	}
	std::sort(pilas.begin(), pilas.end(), std::less<int>());//Ordenamos de menor a mayor el vector
	int sol = resolver(pilas, pila_minima);
	// escribir sol
	std::cout << sol << "\n";
}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}
