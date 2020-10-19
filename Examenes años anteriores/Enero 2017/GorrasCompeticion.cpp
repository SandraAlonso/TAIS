
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	long long  int tam;
	std::cin >> tam;
	if (tam == 0)
		return false;
	PriorityQueue<long long int> cola;
	long long int val;
	for (long long int i = 0; i < tam; i++) {
		std::cin >> val;
		cola.push(val);
	}
	long long int suma = 0;
	while (cola.size() > 1) {
		long long int d1 = cola.top();
		cola.pop();
		long long int d2 = cola.top();
		cola.pop();
		cola.push(d1 + d2);
		suma += d1 + d2;
	}
	std::cout << suma << std::endl;
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
