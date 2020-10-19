
// Nombre y Apellidos: Sandra Alonso Paz.

// Comentario general sobre la solución,
// explicando cómo se resuelve el problema

#include <iostream>
#include <fstream>
#include <queue>
#include "PriorityQueue.h"
struct tDatos {
	int id;
	int cargaInicial;
	int tiempoAcumulado;
};

bool operator<(tDatos const&a, tDatos const&b) {
	return (a.tiempoAcumulado < b.tiempoAcumulado) || (a.tiempoAcumulado == b.tiempoAcumulado&&a.id < b.id);
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int numBaterias, tiempo, numBateriasRepuesto, k, descuento, i = 0, cargaActual;
	// leer los datos de la entrada
	std::cin >> numBaterias;
	if (!std::cin)  // fin de la entrada
		return false;
	PriorityQueue<tDatos>baterias;
	for (i; i < numBaterias; i++) { //lectura de baterias normales (siempre son al menos una)
		std::cin >> cargaActual;
		baterias.push({ i + 1, cargaActual, cargaActual });
	}
	std::cin >> numBateriasRepuesto;
	std::vector<tDatos> bateriasRepuesto;
	for (int j = i; j < numBateriasRepuesto + i; j++) {//lectura de baterias de repuesto (puede ser 0)
		std::cin >> cargaActual;
		bateriasRepuesto.push_back({ j+1, cargaActual, cargaActual });
	}
	std::cin >> descuento >> tiempo;


	k = baterias.top().tiempoAcumulado;// El tiempo inicial es el tiempo de la primera bateria ( la que tiene menor carga) Se asegura que hay al menos una bateria al inicio de la ejecucion.
	int bateriaDeRepuestoActual = 0;// la primera bateria de repuesto que utilizaremos es la primera anadida, es decir, la que se encuentra en primera posicion
	while (k <= tiempo&&!baterias.empty()) {
		tDatos bateria = baterias.top();
		baterias.pop();
		if (descuento < bateria.cargaInicial) {//podemos volver a recargarla: bateria en 6, descuento en 4 ==> bateria en 2
			baterias.push({ bateria.id, bateria.cargaInicial - descuento, bateria.tiempoAcumulado+bateria.cargaInicial - descuento });
		}
		else {//no podemos volver a rercargar.
			if (bateriaDeRepuestoActual <bateriasRepuesto.size()) {//nos quedan baterias de respuesto
				bateriasRepuesto[bateriaDeRepuestoActual].tiempoAcumulado += bateria.tiempoAcumulado;
				baterias.push(bateriasRepuesto[bateriaDeRepuestoActual]);
				bateriaDeRepuestoActual++;
			}
		}
		if (!baterias.empty()) {
			k = baterias.top().tiempoAcumulado;
		}

	}
	if (baterias.size() == 0)
		std::cout << "ABANDONEN INMEDIATAMENTE LA BASE" << std::endl;

	else if (baterias.size() == numBaterias) 
		std::cout << "CORRECTO" << std::endl;

	else 
		std::cout << "FALLO EN EL SISTEMA" << std::endl;
	
	while (!baterias.empty()) {
		std::cout << baterias.top().id << " " << baterias.top().tiempoAcumulado <<std::endl;
		baterias.pop();
	}

	std::cout << "---" << std::endl;
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
