/*
ID: dmfrodr1
TASK: butter
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
typedef vector<bool>            VB;
typedef vector<VB>              VVB;
typedef pair< lli, lli>         PII;
typedef pair<ulli,ulli>         PUU;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second
const lli INF = 1000000000;

struct edge {
	lli fr, to, c;
	bool operator<(const edge& e)const{
		if(c  != e.c ) return (c  < e.c );
		if(fr != e.fr) return (fr < e.fr);
		return (to < e.to);
	}
	bool operator==(const edge& e)const{ return !(*this < e || e <  *this); }
	bool operator> (const edge& e)const{ return !(*this < e || *this == e); }
};

class alGraph:public vector< deque<edge> >{ // Adjency List
public:
	alGraph(lli s):vector< deque<edge> >(s){}
	void addEdge(lli src, lli dst, lli c = 0) {
		(*this)[src].push_back({src, dst, c});
	}
	alGraph transpose() const{
		alGraph GT(size());
		FOR(u,0,size()) for(const edge &e:(*this)[u])
			GT.addEdge(e.to, e.fr, e.c);
		return GT;
	}
};

lli dijkstra(const alGraph &g, lli src, lli dst, VI& dist, VI& prev) {
    if(dist.size() != g.size() || prev.size() != g.size()) return INF;
    fill(ALL(dist), INF); fill(ALL(prev),  -1);
    vector<bool> visited(g.size(), false);
    priority_queue<PII, vector<PII>, greater<PII> > q; //cost so far, node
    dist[src] = 0; prev[src] = -1; q.push({0, src});
    while(!q.empty()){
        lli u = q.top().second; q.pop();
        if(u == dst) return dist[u];
        if(visited[u]){ continue; } visited[u] = true;
        for(const auto& e : g[u])
            if (dist[e.to] > dist[u] + e.c) {
                dist[e.to] = dist[u] + e.c;
                prev[e.to] = u;
                q.push({dist[e.to], e.to});
            }
    }
    return INF;
}

int main(){
    ifstream fin("butter.in");
    ofstream fout("butter.out");
    
    ///INPUT
    int N, P, C; fin >> N >> P >> C;
    vector<int> n(N);
    FOR(i,0,N){ fin >> n[i]; --n[i]; }
    alGraph g(P);
    {
        int u, v, c;
        FOR(i,0,C){
            fin >> u >> v >> c;
            --u;
            --v;
            g.addEdge(u,v,c);
            g.addEdge(v,u,c);
        }
    }

    ///PROCESSING
    lli best_ans = INF;

    VI dist(P); VI prev(P);
    FOR(i,0,P){
        dijkstra(g, i, -1, dist, prev);
        lli ans = 0;
        for(const int &cow: n){
            ans += dist[cow];
        }

        best_ans = min(best_ans, ans);
    }
    
    ///OUTPUT
    fout << best_ans << endl;

    return 0;
}
