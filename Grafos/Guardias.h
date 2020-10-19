#include "Grafo.h"
#include <algorithm>
class Guardias
{
	 struct numGuardia {
		int a;
		int b;
		int numgfinales;
	};
private:
	std::vector<bool> marked;
	std::vector<bool> guardia;//guardia = true.
	bool posible;
	numGuardia gu;
	


public:

	Guardias(Grafo const&g) :marked(g.V(), false), guardia(g.V()), posible(true), gu({ 0,1 }) {
		
		for (int i = 0; i < g.V() && posible; i++) {
			if (!marked[i]) {
				posible = dfs(g, i);
				gu.numgfinales += std::min(gu.a, gu.b);
				gu = { 0,1,gu.numgfinales };

			}
		}
	};
	bool dfs(Grafo const & g, int v) {
		marked[v] = true;
		for (int w : g.ady(v)) {
			if (!marked[w]) {
				guardia[w] = !guardia[v];

				if (guardia[w]) gu.a++;
				else gu.b++;

				if (!dfs(g, w))	return false;
			}
			else 
				if (guardia[w] == guardia[v]) return false;

		}
		return true;
	}
	int numGuardias(Grafo const &g) {
		return gu.numgfinales;
	}
	bool esPosible() {
		return posible;
	}


};