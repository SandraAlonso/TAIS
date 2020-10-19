#ifndef PUENTE_H_
#define PUENTE_H_

#include <vector>
#include <string>
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"

class Comparador {
public:
	bool operator()(Arista<int> a, Arista<int>b) {
		return a.valor() < b.valor();
	}
};

class puente {
public: //KRUSKAL
	puente(GrafoValorado<int>& g, int intersecciones, int calles)
		:intersecciones(intersecciones), resultado(0), calles(calles), cd(intersecciones) {
		ponerCalles(g, calles);
		while (!pq.empty()) {
			Arista<int> e = pq.top(); pq.pop();
			int v = e.uno(); int w = e.otro(v);
			if (!cd.unidos(v, w)) {
				cd.unir(v, w);
				resultado += e.valor();
			}
		}
	}

	void ponerCalles(GrafoValorado<int>& g, int calles) {
		int de = 0, hasta = 0, coste = 0;

		for (int i = 0; i < calles; i++) {
			std::cin >> de >> hasta >> coste;
			Arista<int> calle(de - 1, hasta - 1, coste);
			g.ponArista(calle);
			pq.push(calle);
		}
	}


	std::string solucion() {
		if (cd.num_cjtos() > 1) return "No hay puentes suficientes";
		return std::to_string(resultado);
	}

private:
	ConjuntosDisjuntos cd;
	PriorityQueue<Arista<int>, Comparador> pq;
	int calles;
	int intersecciones;
	int resultado;
};
#endif // !PUENTE_H_
