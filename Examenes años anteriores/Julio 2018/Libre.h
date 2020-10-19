#include"Grafo.h"
class Libre
{
public:
	Libre(Grafo const& g, int v) :marked(g.V(), false), libre(true){
		int i = 0;
		dfs(g, v);
		while (i < g.V()&&libre) {
			if (!marked[i]) {
				libre = false;
			}
			i++;
		}
	}
	bool esLibre() {
		return libre;
	}

private:
	std::vector<bool>marked;
	bool libre;
	void dfs(Grafo const& g, int v) {
		marked[v] = true;
		for (auto w : g.ady(v)) {
			if (!marked[w]) {
				marked[w] = true;
				dfs(g, w);
			}
		}
	}

};

