#include "GrafoDirigido.h"
#include <deque>
#include <algorithm>

//un grafo tendra ciclos si tiene alguna arista en direccion contraria al resto de las aristas.
class Tareas
{
public:
	Tareas(GrafoDirigido const& g): marked(g.V(), false), HayCiclos(false), markedBucle(g.V(), false){
		for (int v=0; v < g.V(); v++) {
			if (!marked[v] && !HayCiclos) {
				dfs(g, v);
			}
		}
	}

	std::deque <int>cola() {
		return ordenado;
	}
	bool esPosible() {
		return !HayCiclos;
	}

private:
	std::vector<bool>marked;
	std::vector<bool>markedBucle;
	std::deque<int> ordenado;
	bool HayCiclos;

	void dfs(GrafoDirigido const&g, int v) {
		marked[v] = true;
		markedBucle[v] = true;
		if (!HayCiclos) {
			for (int w : g.ady(v)) {
				if (!marked[w]) {
					dfs(g, w);

				}
				if (markedBucle[w])
					HayCiclos = true;

			}
			ordenado.emplace_front(v);
			markedBucle[v] = false;
		}
	}
};

