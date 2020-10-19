#include <queue>
#include <vector>
#include "Grafo.h"
class NodoLejano
{
public:
	NodoLejano(Grafo const &g, int origen, int TTL): distTo(g.V()), marked(g.V()), inalcanzables(g.V()) {
		bfs(g, origen);
		inalcanzables = g.V();
		for (int i =0; i < g.V(); ++i) {
			if (marked[i] && distTo[i] <= TTL) {
				--inalcanzables;
			}
		}
	}
	int sonInalcanzables() {
		return inalcanzables;
	}

private:
	int inalcanzables;
	std::vector<int> distTo;
	std::vector<bool> marked;
	void bfs(Grafo const&g, int s) {
		std::queue<int> q;
		distTo[s] = 0;
		marked[s] = true;
		q.push(s);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int w : g.ady(v)) {
				if (!marked[w]) {
					distTo[w] = distTo[v] + 1;
					marked[w] = true;
					q.push(w);
				}
			}
		}
	}

};

