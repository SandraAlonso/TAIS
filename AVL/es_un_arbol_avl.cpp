
// Nombre y Apellidos: Sandra Alonso Paz

// Comentario general sobre la solucion,
// explicando como se resuelve el problema: recorremos el arbol bien hasta que confirmamos que el arbol es avl o bien uno de sus hijos no lo sea


#include <iostream>
#include <fstream>
#include "bintree_eda.h"


// función que resuelve el problema

typedef struct {
	int altura = 0;
	bool equilibado;
}tSol;
// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

tSol resolver(bintree<int> const arbol, int &max, int &min) {
	if (arbol.empty()) {
		return { 0,true };
	}
	else {
		tSol izq, der;
		if (!arbol.left().empty()) {
			if (arbol.left().root() < min) {
				min = arbol.left().root();
				izq = resolver(arbol.left(), max, min);
			}
			else
				izq.equilibado = false;
		}
		if (!arbol.right().empty()) {
			if (arbol.right().root() > max) {
				max = arbol.right().root();
				der = resolver(arbol.right(), max, min);
			}
			else
				der.equilibado = false;
		}
		if ((izq.equilibado && der.equilibado) && (std::abs(izq.altura - der.altura) < 2))
			return { 1 + std::max(izq.altura, der.altura),true };
		else
			return { 1 + std::max(izq.altura, der.altura), false };



	}
}
void resuelveCaso() {
	bintree<int> arbol;
	arbol = leerArbol(-1);
	int max = arbol.root();
	tSol equilibrado = resolver(arbol, max, max);
	if (equilibrado.equilibado)
		std::cout << "SI" << std::endl;
	else
		std::cout << "NO" << std::endl;

}

int main() {
	// ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}