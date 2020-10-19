
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Tareas.h"
//El coste total del algoritmo es O(V+E) 
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int vertices, aristas, a1, a2;
	std::cin >> vertices >> aristas;
	if (!std::cin)
		return false;
	GrafoDirigido g(vertices);
	for (int i = 0; i < aristas; i++) {
		std::cin >> a1 >> a2;
		g.ponArista(a1 - 1, a2 - 1);
	}
	Tareas t(g);
	if (t.esPosible()) {
		std::deque<int> q = t.cola();
		
		while (!q.empty()) {
			std::cout << q.front()+1 << " ";
			q.pop_front();
		}
	}
	else
		std::cout << "Imposible";
	std::cout << std::endl;
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