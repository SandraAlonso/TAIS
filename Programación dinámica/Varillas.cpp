
// Nombre y Apellidos

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Matriz.h"

/*
Llamada inicial : varillaTotal(i,j) donde i son los cofres que emtes y j la longitud de la varilla total.
Funcion recursiva: min(varillaTotal(i-1, j), varillaTotal(i-1, j-coste(i-1)+coste(i)).
Rango de variables: 0<=i<=numVarillas, 0<=j<=LongitudTotal.
Casos base: varillaTotal(0, j)=0 varillaTotal(i, 0)=0.




*/

struct tDatos {
	int longitud;
	int coste;
};
struct tSol {
	int cont;
	int min;
};

tSol varillaTotal(std::vector<tDatos>varilla, int l){
	Matriz<int> v(varilla.size() + 1, l + 1, 1000000);
	v[0][0] = 0;
	for (int i = 1; i < varilla.size(); i++) {
		v[i][0] = 0;
		for (int j=l; j >0 ; j--) {
			if (varilla[i].longitud > j)
				v[i][j] = v[i - 1][j];//no cabe la nueva varilla por la longitud.
			else 
				v[i][j]= std::min(v[i-1][j], v[i-1][j-varilla[i].longitud]+varilla[i].coste);// la nueva varilla cabe pero debemos comprobar si hayq ue sacar la anterior o no.
		}
	}
	int cont = 0;
	int min = v[0][l];
	for (int i = 0; i < varilla.size(); i++) {
		if (v[i][l] > l) {
			cont++;
			if (min> v[i][l])
				min = v[i][l];
		}
	}
	return { cont, min };
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int varillas, l;
	// leer los datos de la entrada
	std::cin >> varillas >> l;
	if (!std::cin)  // fin de la entrada
		return false;
	std::vector<tDatos> varilla(varillas);
	varilla[0] = { 0,0 };
	for (int i = 1; i < varillas; i++) {
		std::cin >> varilla[i].longitud >> varilla[i].coste;
	}
	tSol sol = varillaTotal(varilla, l);
	if (sol.min == 1000000)std::cout << "NO" << std::endl;
	else std::cout << "SI " << sol.cont <<" "<< sol.min << std::endl;
	// escribir sol

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
