//Sandra Alonso Paz
//tais05
//COSTE COMPROBADO: O(Tlog(N+M) siendo m y n las tareas y t el tiempo
#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

struct registro {
	int inicio;
	int fin;
	int periodo;
};

bool operator<(registro const&a, registro const&b) {//cambiar signo
	return a.inicio < b.inicio;
}

// función que resuelve el problema

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int actCortas, actLargas, tiempo, inicio, fin, periodo;
	bool conflicto=false;
	std::cin >> actCortas;
	if (!std::cin)
		return false;
	std::cin >> actLargas >> tiempo;
	PriorityQueue<registro>cola;
	for (int i = 0; i < actCortas; i++){//rellenamos la cola de actividades de una repeticion.
		std::cin >> inicio >> fin;
		cola.push({ inicio, fin, 0 });
	}
	for (int i = 0; i < actLargas; i++){//rellenamos la cola de dactividades de varias repeticiones.
		std::cin >> inicio >> fin>>periodo;
		cola.push({ inicio, fin, periodo });
	}
	int i = 0;
		while (cola.size()>1 && cola.top().fin < tiempo && !conflicto) {//IMPORTANTE, PUEDE QUE EN LA COLA SOLO HAYA UNA ACTIVIDAD ENTONCES NOS DA ERROR AL ACCESO DE UN ELEMENTO QUE NO EXISTE.
			registro r = cola.top();
			cola.pop();
			if (r.fin > cola.top().inicio) {//hay conflicto
				conflicto = true;
			}
			else {//todavia no hay conflicto
				if (r.periodo != 0) {//tarea no simple, la sacamos de la cola porque ya no coincide.
					r.inicio += r.periodo;
					r.fin += r.periodo;
					cola.push(r);
				}

			}
		}
	if (conflicto)
		std::cout << "SI\n";
	else
		std::cout << "NO\n";
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
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