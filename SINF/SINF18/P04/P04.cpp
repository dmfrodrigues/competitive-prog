
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> VI;
#define ALL(v)          (v).begin() , (v).end()
#define FOR(i,n)        for (int i = 0; i < (n); i++)

const lli& INF = numeric_limits<lli>::max();

struct edge { int to, cost; };
class alGraph:public vector< deque<edge> >{ // Adjency List
public:
	alGraph(int s):vector< deque<edge> >(s){}
	void addEdge(int src, int dst, int c = 0) {
		(*this)[src].push_back({dst, c});
		(*this)[dst].push_back({src, c});
	}
};

lli dijkstra(const alGraph &g, int source, int target, VI& dist, VI& prev) {
  unsigned int N = g.size(); if(dist.size() != N || prev.size() != N) return INF;
  fill(ALL(dist), INF); dist[source] = 0;
  fill(ALL(prev),  -1); prev[source] = -1;
  set< pair<int, int> > active; //cost so far, node
  active.insert( {0, source} );
  while (!active.empty()) {
    int cur = active.begin()->second;
    if (cur == target) return dist[cur];
    active.erase( active.begin() );
    for (const edge& ed : g[cur])
      if (dist[ed.to] > dist[cur] + ed.cost) {
        active.erase({dist[ed.to], ed.to});
        dist[ed.to] = dist[cur] + ed.cost;
        prev[ed.to] = cur;
        active.insert({dist[ed.to], ed.to});
      }
  }
  return INF;
}



int main(){
	int N, M; cin >> N >> M;
	alGraph g(N);
	
	int a, b; lli t;
	FOR(i, M){
		cin >> a >> b >> t;
		g.addEdge(a-1, b-1, t);
	}

	VI dist(N), prev(N);

	lli ans = dijkstra(g, 0, N-1, dist, prev);
	cout << ans << endl;

	return 0;
}