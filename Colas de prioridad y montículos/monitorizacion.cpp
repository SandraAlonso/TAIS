//Sandra Alonso Paz TAIS 05
#include <iostream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"

//o(NlogN+KlogN) donde N es el numero de usuarios y K el numero de consultas
struct registro {
	int momento; // cuándo le toca 
	int id; // identificador (se utiliza en caso de empate) 
	int periodo; // tiempo entre consultas 
};


// función que resuelve el problema


bool operator<(registro const& a, registro const& b) { 
	return a.momento < b.momento || (a.momento == b.momento && a.id < b.id);
}




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int N;
	std::cin >> N; // número de usuarios registrados
	if (N == 0) // no hay más casos 
		return false;
	PriorityQueue<registro> cola;
	// leemos los registros 
	for (int i = 0; i < N; ++i) {
		int id_usu, periodo;
		std::cin >> id_usu >> periodo;
		cola.push({ periodo, id_usu, periodo });
	}
	int envios; // número de envíos a mostrar
	std::cin >> envios;
	while (envios--) {
		registro e = cola.top();
		cola.pop();
		std::cout << e.id << '\n';
		e.momento += e.periodo;
		cola.push(e);
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