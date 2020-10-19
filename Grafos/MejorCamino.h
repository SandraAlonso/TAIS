#include "GrafoValorado.h"
#include "IndexPQ.H"
#include <queue>


class MenorCamino
{

public:
	MenorCamino(GrafoValorado<int> const& g, int s) : marked(g.V(), false), distTo(g.V(), 1000000), dist(g.V(), 1000000), pq(g.V()), cont(g.V()) {
		bfs(g, s);
	}
	bool hayCamino(int v) {
		return dist[v] != 1000000;
	}
	int valor(int v) {
		return dist[v];
	}
	bool soniguales(int k) {
		return cont[k]==distTo[k];
	}

private:
	std::vector<int> distTo;//devuelve la distancia sin valorar(solo contando calles)
	std::vector<int> dist;//devuelve la distancia en metros
	std::vector<bool> marked;
	std::vector<int> cont;
	bool sonIguales=true;
	IndexPQ<int>pq;

	void bfs(GrafoValorado<int> const& g, int s) {
		std::queue<int>cola;
		distTo[s] = 0;
		dist[s] = 0;
		cola.push(s);
		marked[s] = true;
		while (!cola.empty()) {
			int v = cola.front();
			cola.pop();
			for (auto w : g.ady(v)) {
				if (!marked[w.otro(v)]) {
					distTo[w.otro(v)] = distTo[v] + 1;
					marked[w.otro(v)] = true;
					cola.push(w.otro(v));
					
				}
				int k = w.otro(v);
				if (dist[k] > dist[v] + w.valor()) {
					dist[k] = dist[v] + w.valor();
					cont[k]=cont[v]+1;//numero de aristas por el camino de menos peso
					pq.update(k, dist[k]);
				}
			}
		}
	}

};

