
// Nombre y Apellidos Sandra Alonso Paz
// Coste: O(Nlog(N)) siendo N el numero de tareas.
// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include "PriorityQueue.h"

struct tDatos{
	int ini;
	int fin;
};

bool operator<(const  tDatos a, const tDatos b) {
	return a.ini < b.ini;
}
// función que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...


// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int numActs, ini, fin;
	// leer los datos de la entrada
	std::cin >> numActs;
	if (numActs==0)
		return false;
	PriorityQueue<tDatos>cola;
	std::cin >> ini >> fin;
	cola.push({ ini, fin });
	for (int i = 0; i < numActs-1; ++i) {
		std::cin >> ini >> fin;
		if (cola.top().ini < ini &&cola.top().fin>ini) {
			cola.push({ ini, fin });
		}
		else {
			tDatos a = cola.top();
			cola.pop();
			if (a.fin < fin)
				a.fin = fin;
			else
				a.ini = ini;
			cola.push(a);

		}
	}
	// escribir sol
	std::cout<<cola.size() - 1<<'\n';
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
