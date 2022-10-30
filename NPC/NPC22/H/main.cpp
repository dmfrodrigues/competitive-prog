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
const lli INF = 1000000000000000000LL;

const lli NMAX = 100000;

VI dijkstra(const VI &t, const vector<unordered_set<lli>> &adj, const lli &src){
    const lli &N = t.size();
    VI dist(N, INF);
    VB visited(N, false);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    dist[src] = t[src]; q.push({dist[src], src});
    while(!q.empty()){
        lli u = q.top().second; q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(const lli &v: adj[u]){
            if(dist[v] > dist[u] + t[v]){
                dist[v] = dist[u] + t[v];
                q.push({dist[v], v});
            }
        }
    }
    return dist;
}

class flow_graph{
public:
	vector< deque<lli> > adj; unordered_map<lli, unordered_map<lli, lli>> cap;
	flow_graph(lli s):adj(s){}
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
lli dinic(flow_graph &g, lli s, lli t){
	lli f = 0;
	VI prev(g.size());
	while(bfs_dinic(g,prev,s,t)){
		lli f_ = INF; //Go back and see how much we can increase flow
		for(lli v = t; prev[v] >= 0; v = prev[v])
			{ f_ = min(f_, g.cap[prev[v]][v]); }
		for(lli v = t; prev[v] >= 0; v = prev[v])
			{ g.cap[prev[v]][v] -= f_; g.cap[v][prev[v]] += f_; }
		f += f_;
	}
	return f;
}

VI bfs(const flow_graph &G, lli src){
    VI dist(G.size(), INF);
    queue<lli> q;
    dist[src] = 0; q.push(src);
    while(!q.empty()){
        lli u = q.front(); q.pop();
        for(const lli &v: G.adj[u]){
            if(G.cap.at(u).at(v) <= 0) continue;
            dist[v] = dist[u]+1;
            q.push(v);
        }
    }
    return dist;
}

int main(){
    lli N, M, K;
    cin >> N >> M >> K;

    VI t(N);
    FOR(n,0,N) cin >> t[n];

    vector<unordered_set<lli>> adj(N);
    FOR(m,0,M){
        lli u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    // Only care about minimum paths
    {
        VI dist1 = dijkstra(t, adj,   0);
        VI dist2 = dijkstra(t, adj, N-1);

        lli d = dist1[N-1];
        FOR(u,0,N){
            lli d_ = dist1[u] + dist2[u] - t[u];
            if(d_ < d) throw logic_error("d_ cannot be smaller than d");
            else if(d_ > d){
                for(const lli &v: adj[u]) adj[v].erase(u);
                adj[u].clear();
            }
        }
    }

    set<lli> cut1;
    set<lli> cut2;
    {
        flow_graph G(2*NMAX);
        FOR(u,1,N-1){
            G.addEdge(u, u+NMAX, 1);
        }
        FOR(u,1,N){
            for(const lli &v: adj[u]){
                if(v <= u) continue;
                G.addEdge(u+NMAX, v, 1);
            }
        }
        dinic(G, 0+NMAX, N);

        VI dist = bfs(G, 0+NMAX);
        FOR(u,0,NMAX){
            if(dist[u] != INF && dist[u+NMAX] == INF) cut1.insert(u);
            for(const lli &v: G.adj[u]){
                if(dist[u+NMAX] != INF && dist[v] == INF) cut1.insert(v);
            }
        }

        for(const lli &u: cut1){
            for(const lli &v: G.adj[u]){
                if(dist[v] == INF)
                    cut2.insert(v);
            }
        }
    }

    string sol;
    {
        char smallestGroup = 'N';
        lli smallestCount = K;
        if(N-K < K){
            smallestGroup = 'S';
            smallestCount = N-K;
        }
        char largestGroup = (smallestGroup == 'N' ? 'S' : 'N');
        lli largestCount = N-K;

        if(smallestCount < (lli)cut1.size()){
            cout << "impossible" << endl;
            return 0;
        }

        sol = string(N, '-');
        for(const lli &u: cut1){
            sol[u] = smallestGroup;
            --smallestCount;
        }
        for(const lli &v: cut2){
            sol[v] = largestGroup;
            --largestCount;
        }
        lli i = 0;
        while(smallestCount > 0){
            if(cut1.count(i)){ ++i; continue; }
            if(cut2.count(i)){ ++i; continue; }
            sol[i++] = smallestGroup;
            smallestCount--;
        }
        while(largestCount > 0){
            if(cut1.count(i)){ ++i; continue; }
            if(cut2.count(i)){ ++i; continue; }
            sol[i++] = largestGroup;
            largestCount--;
        }
    }

    cout << sol << endl;

    return 0;
}
