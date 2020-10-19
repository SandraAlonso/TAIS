//Sandra Alonso Paz TAIS 05
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "PriorityQueue.h"

struct registro {
	int numeroCaja;
	int colaEspera;
};




bool operator<(registro const& a, registro const& b) {
	return a.colaEspera < b.colaEspera || (a.colaEspera ==b.colaEspera && a.numeroCaja < b.numeroCaja);
}




// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int cajas, clientes, tiempoCliente;
	std::cin >> cajas; // número de usuarios registrados
	if (cajas == 0) // no hay más casos 
		return false;
	std::cin >> clientes;
	PriorityQueue<registro> cola;
	// leemos los registros 
	for (int i = 0; i < cajas; i++){
		cola.push({ i+1,0 });
	}

	for (int i = 0; i < clientes; ++i) {
		std::cin >> tiempoCliente;
		registro e = cola.top();
		cola.pop();
		e.colaEspera += tiempoCliente;
		cola.push(e);

	}
	registro e = cola.top();
	std::cout << e.numeroCaja<<'\n';
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