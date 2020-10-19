#include "GrafoValorado.h"
#include <queue>
class Camion
{
public:
	Camion(GrafoValorado <int> const& g, int s, int camion):marked(g.V(), false), correcto(g.V(), true) , distTo(g.V(), 100000){
		int i = 0;
		bfs(g, s, camion);
	}

	bool elCamionPasa(int v) {
		return correcto[v];
	}
	bool hayCamino(int v) {
		return distTo[v];
	}

private:
	std::vector<bool>marked;// evitar ciclos
	std::vector<bool>correcto;// el camion puede pasar
	std::vector<int> distTo;//hemos llegado al vertice

	void bfs(GrafoValorado <int> const& g, int s, int camion) {
		std::queue<int>cola;
		cola.push(s);
		distTo[s] = 0;
		marked[s] = true;
		while (!cola.empty()) {
			int v = cola.front();
			cola.pop();
			for (auto w : g.ady(v)) {
				if (w.valor() >= camion) {
					if (!marked[w.otro(v)]) {
						distTo[w.otro(v)] = distTo[v] + 1;
						cola.push(w.otro(v));
					}
					marked[w.otro(v)] = true;
				}
				else correcto[w.otro(v)] = false;
			}
		}
	}
};

