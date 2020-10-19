#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"
struct tDatos {
	std::string nombre;
	int gravedad;
	int llegada;
};

bool operator<(tDatos const& a, tDatos const& b) {
	return (a.gravedad > b.gravedad) || (a.gravedad == b.gravedad&&a.llegada > b.llegada);
}
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int eventos;
	std::string caso;
	std::cin >> eventos;
	if (eventos==0)
		return false;
	PriorityQueue<tDatos>cola;
	tDatos dato;
	while (eventos != 0) {
		std::cin >> caso;
		if (caso == "I") {
			std::cin >> dato.nombre >> dato.gravedad;
			cola.push({ dato.nombre, dato.gravedad, eventos });
		}
		else {
			tDatos paciente = cola.top();
			cola.pop();
			std::cout << paciente.nombre << std::endl;
		}
		eventos--;
	}
	std::cout << "----"<<std::endl;
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
