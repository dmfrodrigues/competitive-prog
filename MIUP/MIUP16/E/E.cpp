#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e)  for(lli (i) = (b); (i) < lli(e); ++(i))
#define ALL(v)      (v).begin(), (v).end()
#define INF 200000000
typedef vector<lli> VI;
typedef pair<lli,lli> PII;

struct edge {
	lli fr, to, c;
};

class alGraph:public vector< deque<edge> >{ // Adjency List
public:
	alGraph(lli s):vector< deque<edge> >(s){}
	void addEdge(lli src, lli dst, lli c = 0) {
		(*this)[src].push_back({src, dst, c});
        (*this)[dst].push_back({dst, src, c});
	}
};

lli dijkstra(const alGraph &g, lli src, VI& dist) {
    if(dist.size() != g.size()) return INF;
    fill(ALL(dist), INF);
    vector<bool> v(g.size(), false);
    priority_queue<PII, vector<PII>, greater<PII> > a; //cost so far, node
    dist[src] = 0; a.push({0, src});
    while(!a.empty()){
        lli cur = a.top().second; a.pop();
        if(v[cur]){ continue; } v[cur] = true;
        for(const auto& e : g[cur])
            if (dist[e.to] > dist[cur] + e.c) {
                dist[e.to] = dist[cur] + e.c;
                a.push({dist[e.to], e.to});
            }
    }
    return INF;
}

int main(){
    lli C, R; cin >> C >> R;
    alGraph al(C);
    lli c1, c2, l;
    FOR(i,0,R){
        cin >> c1 >> c2 >> l;
        al.addEdge(c1, c2, l);
    }
    lli X, Y; cin >> X >> Y;
    VI distX(C), distY(C);
    dijkstra(al, X, distX);
    dijkstra(al, Y, distY);
    lli inX = 0, inY = 0, inXY = 0;
    FOR(i,0,C){
        if     (distX[i] < distY[i]) ++inX;
        else if(distX[i] > distY[i]) ++inY;
        else                         ++inXY;
    }
    cout << inX << " " << inY << " " << inXY << endl;
    return 0;
}
