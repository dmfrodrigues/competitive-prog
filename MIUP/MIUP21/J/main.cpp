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
const lli INF = 100000000;

int bfs(const vector<list<int>> &adj, vector<int> &dist, int n){
    queue<int> q;

    fill(ALL(dist), INF);
    dist[n] = 0;
    q.push(n);

    int dmax = 0;
    while(!q.empty()){
        const int &u = q.front(); q.pop();
        dmax = max(dmax, dist[u]);
        for(const int &v: adj.at(u)){
            if(dist[v] != INF) continue;
            dist[v] = dist[u]+1;
            q.push(v);
        }
    }

    return dmax;
}

int main(){
    int N; cin >> N;

    vector<list<int>> adj(N);
    
    FOR(n,0,N-1){
        int u, v; cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vector<int> dist1(N);
    int d1 = bfs(adj, dist1, 0);
    int u = -1;
    FOR(n,0,N){
        if(dist1[n] == d1){
            u = n;
            break;
        }
    }

    vector<int> dist2(N);
    int d2 = bfs(adj, dist2, u);

    cout << d2 << endl;

    return 0;
}
