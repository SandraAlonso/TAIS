#include "Grafo.h"
class Bipartito
{
private:
	std::vector<bool> marked;
	std::vector<bool> color;
	bool bipartito;

public:

	Bipartito(Grafo const&g) :marked(g.V(), false), color(g.V()), bipartito(true) {//comprobar todas las componentes conexas
		for (int i = 0; i < g.V() && bipartito; i++) {
			if (!marked[i]) {
				color[i] = true;
				bipartito = dfs(g, i);
			}
		}
	};
	bool dfs(Grafo const & g, int v) {
		marked[v] = true;
		for (int w: g.ady(v)){
			if (!marked[w]) {
				color[w] = !color[v];

				if (!dfs(g, w)) {
					return false;
				}
				
			}
			else {
				if (color[w] == color[v]) {
					return false;
				}
			}
			
		}
		return true;
	}

	bool esBipartito() {
		return bipartito;
	}
	

};