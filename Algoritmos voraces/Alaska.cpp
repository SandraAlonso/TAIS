
// Nombre y Apellidos Sandra Alonso Paz.


#include <iostream>
#include <fstream>
#include <vector>
#include "PriorityQueue.h"



// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	// leer los datos de la entrada
	int personas, altura, suma=0;
	std::cin >> personas;
	if (personas==0)
		return false;
	PriorityQueue<int> p;
	PriorityQueue<int> esquies;
	for (int i = 0; i < personas; ++i) {
		std::cin >> altura;
		p.push(altura);
	}
	for (int i = 0; i < personas; ++i) {
		std::cin >> altura;
		esquies.push(altura);
	}
	for (int i = 0; i < personas; ++i) {
		int a = p.top();
		int b = esquies.top();
		p.pop();
		esquies.pop();
		suma += std::abs(a-b);
	}
	std::cout << suma << '\n';

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
