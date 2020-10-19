//Sandra Alonso Paz TAIS 05
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "PriorityQueue.h"

struct registro {
	int prioridad;
	std::string nombre;
	int cont;//en caso de ser misma prioridad ordeno por tiempo de llegada
};




bool operator<(registro const& a, registro const& b) {
	return a.prioridad > b.prioridad || (a.prioridad==b.prioridad && a.cont<b.cont) ;
}




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	std::cin >> N; // número de usuarios registrados
	if (N == 0) // no hay más casos 
		return false;
	PriorityQueue<registro> cola;
	char letra;
	std::string nomb;
	int prio, cont=0;
	// leemos los registros 
	for (int i = 0; i < N; ++i) {

		std::cin >> letra;
		if (letra == 'I') {
			std::cin >> nomb >> prio;
			cola.push({ prio, nomb, cont });
			cont++;
		}
		else {
			registro e = cola.top();
			cola.pop();
			std::cout << e.nombre << '\n';
		}

	}

	std::cout << "---" << '\n';
	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}