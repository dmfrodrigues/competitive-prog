#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
const lli INF = 1000000000;

class flow_graph{
public:
	vector< deque<lli> > adj; VVI cap;
	flow_graph(lli s):adj(s),cap(s,VI(s,0)){}
	void addEdge(lli src, lli dst, lli c = 0) {
		adj[src].push_back(dst); cap[src][dst] += c;
		adj[dst].push_back(src); cap[dst][src] += c; // remove if not bidirectional
	}
	size_t size()const{ return adj.size(); }
};
bool bfs_dinic(flow_graph &g, VI &prev, lli s, lli t){
	fill(ALL(prev), -1); queue<lli> q;
	prev[s] = -2; q.push(s);
	while(!q.empty() && prev[t] == -1){
		lli u = q.front(); q.pop();
		for(const lli &v:g.adj[u]){
			if(prev[v] == -1 && g.cap[u][v]){
				prev[v] = u; q.push(v);
			}
		}
	} return (prev[t] != -1);
}
lli dinic(flow_graph &g, lli s, lli t ) {
	lli f = 0;
	VI prev(g.size());
	while(bfs_dinic(g,prev,s,t)){
		lli f_ = INF; //Go back all the way and see how much we can increase the flow
		for(lli v = t; prev[v] >= 0; v = prev[v]){ f_ = min(f_, g.cap[prev[v]][v] ); }
		for(lli v = t; prev[v] >= 0; v = prev[v]){ g.cap[prev[v]][v] -= f_; g.cap[v][prev[v]] += f_; }
		f += f_;
	}
	return f;
}

int main(){
    lli N, M; cin >> N >> M;
	flow_graph fg(N+2);{
		bool b;
		FOR(i,1,N+1){
			cin >> b;
			if(!b) fg.addEdge(0,  i,1);
			else   fg.addEdge(i,N+1,1);
		}
		lli fr, to;
		FOR(i,0,M){
			cin >> fr >> to;
			fg.addEdge(fr, to, 1);
		}
	}
    lli ans = dinic(fg, 0, N+1);
    cout << ans << endl;
    return 0;
}
