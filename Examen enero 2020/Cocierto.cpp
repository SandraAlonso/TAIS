#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Matriz.h"


/*
Festival(i,j) = maximixar cantidad de conciertos que podemos ver teniendo en cuenta un dineroTotal
casos base:
Festival(i,0) = 0
Festival(0, j) = 0

caso rescursivo:
Festival(i,j) |  (precio > dineroTotal)  Festival(i - 1, j) 
			  |
			  |	std::max(Festival(i - 1, j), Festival(i, dineroTotal - precio) + numGrupos)
			  |
*/

struct tConcierto{
	int numGrupos;
	int precio;
};

/*int resolver(std::vector<tConcierto> const&concierto, int numConciertos, int dinero) {
	Matriz <int>Festival(numConciertos + 1, dinero + 1);

	for (int i = 1; i <= numConciertos; ++i) {
		Festival[i][0] = 0;
		for (int j = dinero; j > 0; --j) {
			Festival[0][j] = 0;
			if (concierto[i - 1].precio > j) Festival[i][j] = Festival[i - 1][j];//el nuevo concierto no entra dentro del presupuesto
			else Festival[i][j] = std::max(Festival[i - 1][j], Festival[i - 1][j - concierto[i - 1].precio] + concierto[i - 1].numGrupos);//el nuevo concierto entra dentro del presupuesto, debemos decidir si entran juntos o no
		}
	}

	return Festival[numConciertos][dinero];
}*/ 

int resolver(std::vector<tConcierto> const & concierto, int numConciertos, int dinero) {
	std::vector<int> Festival(dinero + 1);
	Festival[0] = 0;
	for (int i = 1; i <= numConciertos; i++) {
		for (int j = concierto[i - 1].precio; j <= dinero; j++) {
			Festival[j] = std::max(Festival[j], Festival[j - concierto[i - 1].precio] + concierto[i - 1].numGrupos);
		}
	}
	return Festival[dinero];
}


bool resuelveCaso() {
	int dinero, numConciertos;
	std::cin >> dinero;
	if (!std::cin) return false;

	std::cin >> numConciertos;
	std::vector<tConcierto> concierto(numConciertos);
	for (int i = 0; i < numConciertos; ++i) {
		std::cin >>concierto[i].numGrupos >> concierto[i].precio;
	}

	int total = resolver(concierto, numConciertos, dinero);
	std::cout << total << "\n";
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
