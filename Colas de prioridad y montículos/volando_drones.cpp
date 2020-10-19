//Sandra Alonso Paz TAIS 05
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "PriorityQueue.h"



struct registroMayorMenor {
	int edad;
};


//cola
bool operator<(registroMayorMenor const& a, registroMayorMenor const& b) {
	return a.edad > b.edad;
}





// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int edadPrimero, numParejas, edad, edad2;
	std::cin >> edadPrimero;
	if (edadPrimero == 0) // no hay más casos 
		return false;
	std::cin >> numParejas;
	PriorityQueue<registroMayorMenor> cola;
	PriorityQueue<int> cola2;
	cola2.push({ edadPrimero });
	for (int i = 0; i < numParejas; ++i) {
		std::cin >> edad >> edad2;
		if (edad < cola2.top()) {
			cola.push({ edad });
			if (cola.size() > cola2.size()) {
				registroMayorMenor r = cola.top();
				int p= r.edad;
				cola.pop();
				cola2.push(p);
			}
		}
		else {
			cola2.push({ edad });
			if (cola.size()+1 < cola2.size()) {
				registroMayorMenor p;
				p.edad = cola2.top();
				cola2.pop();
				cola.push(p);
			}
		}
		if (edad2 < cola2.top()) {
			cola.push({ edad2 });
			if (cola.size() > cola2.size()) {
				registroMayorMenor r = cola.top();
				int p = r.edad;
				cola.pop();
				cola2.push(p);
			}
		}
		else{
			cola2.push({ edad2 });
			if (cola.size() + 1 < cola2.size()) {
				registroMayorMenor p;
				p.edad = cola2.top();
				cola2.pop();
				cola.push(p);
			}
		}
		std::cout << cola2.top()<< " ";
	}
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