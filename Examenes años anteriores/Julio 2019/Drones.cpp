#include <iostream>
#include <fstream>
#include <algorithm>
#include "PriorityQueue.h"

struct tDato {
	int pila;
};
bool operator<(tDato const & a, tDato const & b) {
	return a.pila > b.pila;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int drones, pequenas, grandes, dato, i=0;
	std::cin >> drones >> grandes >> pequenas;
	if (!std::cin)  // fin de la entrada
		return false;

	PriorityQueue<tDato> colaG;
	for (int i = 0; i < grandes; ++i) {
		std::cin >> dato;
		colaG.push({ dato });
	}
	PriorityQueue<tDato> colaP;
	for (int i = 0; i < pequenas; ++i) {
		std::cin >> dato;
		colaP.push({ dato });
	}
	int suma = 0;
	while (colaP.size() > 0 && colaG.size() > 0) {
		while(colaP.size() > 0 && colaG.size() > 0&&i < drones){
			tDato pequena = colaP.top();
			colaP.pop();
			tDato grande = colaG.top();
			colaG.pop();
			suma += std::min(pequena.pila, grande.pila);
			if (pequena.pila > grande.pila) {
				pequena.pila -= grande.pila;
				colaP.push(pequena);
			}
			else if (pequena.pila < grande.pila) {
				grande.pila -= pequena.pila;
				colaG.push(grande);
			}
			i ++;
		}
		std::cout << suma << " ";
		i = 0;
		suma = 0;
	}
	std::cout << std::endl;

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
