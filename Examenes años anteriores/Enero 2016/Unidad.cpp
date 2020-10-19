
#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"

struct tDatos {
	int id;
	int periodo;
	int tiempo;
};

bool operator<(tDatos const& a, tDatos const&b) {
	return (a.tiempo < b.tiempo) || (a.tiempo == b.tiempo && a.id < b.id);
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int usuarios, k;
	// leer los datos de la entrada
	std::cin >> usuarios;
	if (usuarios ==0)
		return false;
	tDatos dato;
	PriorityQueue<tDatos>cola;
	std::string basura;
	for (int i = 0; i < usuarios; ++i) {
		std::cin >> basura;
		std::cin >> dato.id >> dato.periodo;
		cola.push({ dato.id, dato.periodo,dato.periodo });
	}
	std::cin >> k;
	while (k != 0) {
		tDatos mensaje = cola.top();
		cola.pop();
		std::cout << mensaje.id<<std::endl;
		cola.push({ mensaje.id, mensaje.periodo, mensaje.tiempo + mensaje.periodo });
		k--;
	}
	std::cout << "----" << std::endl;

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
