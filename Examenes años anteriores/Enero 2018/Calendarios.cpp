#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

struct tDatos {
	int inicio;
	int fin;
	int periodo;
};

bool operator<( tDatos const & a, tDatos const & b ) {
	return a.inicio < b.inicio;
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int tareasUnicas, tareasPeriodicas, tiempo, i;
	std::cin >> tareasUnicas >> tareasPeriodicas >> tiempo;
	if (!std::cin)  // fin de la entrada
		return false;
	tDatos dato;
	PriorityQueue<tDatos> cola;
	for (int i = 0; i < tareasUnicas; ++i) {
		std::cin >> dato.inicio >> dato.fin;
		cola.push({ dato.inicio, dato.fin, 0 });
	}
	for (int i = 0; i < tareasPeriodicas; ++i) {
		std::cin >> dato.inicio >> dato.fin>>dato.periodo;
		cola.push({ dato.inicio, dato.fin, dato.periodo });
	}
	bool sinconflicto = true;
	i = cola.top().fin;
	while (i < tiempo&&sinconflicto&&cola.size()>1) {
		tDatos tarea= cola.top();
		cola.pop();
		if (tarea.fin > cola.top().inicio) {//hay conflicto
			sinconflicto = false;
		}
		else {
			if (!tarea.periodo == 0) {
				cola.push({ tarea.inicio + tarea.periodo, tarea.fin + tarea.periodo, tarea.periodo });
			}
		}
		i = cola.top().fin;	
	}
	// escribir sol
	if (!sinconflicto)std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl;
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
