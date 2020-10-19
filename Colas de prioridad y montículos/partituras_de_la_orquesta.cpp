//Sandra Alonso Paz TAIS 05
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "PriorityQueue.h"

struct registro {
	int musicos;
	int musicosPorPartitura=musicos;
	int partituras=1;
};

bool operator<(registro const& a, registro const& b) {
	return a.musicosPorPartitura > b.musicosPorPartitura;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int numInstrumentos, numPartituras, instrumento;
	std::cin >> numPartituras;
	if (!std::cin)
		return false;
	std::cin >> numInstrumentos;
	PriorityQueue<registro> cola;
	for (int i = 0; i < numInstrumentos; i++) {
		std::cin >> instrumento;
		cola.push({ instrumento });
	}
	numPartituras -= numInstrumentos;

	for (int i = 0; i < numPartituras; i++) {
		registro e = cola.top();
		cola.pop();
		e.partituras++;
		int nuevo = e.musicos % e.partituras;
		if (nuevo > 0)//tenemos que hacer esta comprobacion porque puede que el resto sea mas que uno y en ese caso se repartirian entre el resto de subgrupos.
			e.musicosPorPartitura = e.musicos / e.partituras + 1;
		else
			e.musicosPorPartitura = e.musicos / e.partituras;

		cola.push(e);

	}
	registro e = cola.top();
	int resto = e.musicos%e.partituras;
	if (resto > 0)
		std::cout << (e.musicos / e.partituras) + 1 << '\n';
	else
		std::cout << (e.musicos / e.partituras) << '\n';

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