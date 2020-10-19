
// Nombre y Apellidos: Sandra Alonso Paz (tais05)

// Propongo un ejercicio de colas de prioridad basado en el funcionamiento de un sistema operativo multiproceso.

#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.h"

struct pid { //Datos a tener en cuenta de los procesos.
	
	int prioridad;
	int id;
	int tiempo;
};

bool operator<(pid const& a, pid const& b) {//Ordenamos la cola de prioridad según la prioridad del proceso, si son iguales consideramos antes el que mayor tiempo necesite para ejecutarse y si ambos datos coinciden, entonces priorizamos el que menor PID tenga.
	return a.prioridad < b.prioridad || (a.prioridad == b.prioridad && a.tiempo > b.tiempo) || (a.prioridad == b.prioridad&&a.tiempo == b.tiempo&&a.id < b.id);
}


bool resuelveCaso() {
	int N, T, K, C, tC, suma = 0, cont = 0; //inicializamos las variables suma que llevará la cuenta del tiempo invertido y cont que devolverá el número de procesos ejecutados.
	std::string id;
	std::cin >> N >> T >> K >> C>> tC;
	if (!std::cin)  // fin de la entrada
		return false;
	PriorityQueue<pid> cola;
	// leemos los registros 
	for (int i = 0; i < K; i++) {//Leemos los datos de los procesos y los insertamos en la cola de prioridad (O(Log(n))
		pid a;
		std::cin >> id;
		id.length();
		int c = (id.at(id.length() - 1) - '0'); //Cogemos solo el último número del string "PIDX" para obtener la prioridad.
		std::cin >> a.prioridad >> a.tiempo;
		cola.push({ a.prioridad,c,a.tiempo });
	}
	while (suma < T && !cola.empty()) {//Ejecutamos los procesos hasta haber recorrido todos (no quedan procesos) o bien hemos completado el tiempo maximo de ejecucion del sistema operativo.
		pid a = cola.top();
		cola.pop();
		if (a.tiempo > C * tC) { //todavia le queda tiempo para ejecutar
			a.tiempo -= C * tC;//le restamos el tiempo gastado
			cola.push(a);//lo volvemos a intruducir en la cola
			suma += C * tC; //incrementamos el tiempo utilizado
		}
		else {
			suma += a.tiempo;//solo utilizamos el tiempo del proceso, no todo el ciclo.
			cont++;
		}
	}
	if (cont == K)
		std::cout << "SI" << std::endl;//Hemos ejecutado todos los procesos.
	else
		std::cout << "NO " << cont << "\n"; //Devolvemos el número de procesos que no hemos podido ejecutar.

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
