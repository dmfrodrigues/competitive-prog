/*
ID: dmfrodr1
TASK: comehome
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

typedef char node_t;
typedef int dist_t;

const dist_t INF = 1000000000;

struct edge_t {
    node_t to;
    dist_t c;
};

edge_t dijkstra(const unordered_map<node_t, list<edge_t> > &adj){
    unordered_map<node_t, dist_t> dist;
    unordered_map<node_t, bool> visited;
    for(const auto &p: adj){
        dist[p.first] = INF;
        visited[p.first] = false;
    }

    priority_queue<
        pair<dist_t, node_t>,
        vector<pair<dist_t, node_t>>,
        greater<pair<dist_t, node_t>>
    > q;
    dist.at('Z') = 0; q.push({0, 'Z'});
    while(!q.empty()){
        node_t u = q.top().second; q.pop();
        if(isupper(u) && u != 'Z') return edge_t({u, dist[u]});
        if(visited[u]){ continue; } visited[u] = true;
        for(const edge_t& e : adj.at(u)){
            if (dist[e.to] > dist[u] + e.c) {
                dist[e.to] = dist[u] + e.c;
                q.push({dist[e.to], e.to});
            }
        }
    }

    throw invalid_argument("");
}

int main(){
    // INPUT FILES
    ifstream fin("comehome.in");
    ofstream fout("comehome.out");
    // INPUT
    size_t P;
    fin >> P;
    unordered_map<node_t, list<edge_t> > adj;
    FOR(i,0,P){
        node_t fr, to; dist_t c;
        fin >> fr >> to >> c;
        adj[fr].push_back(edge_t({to, c}));
        adj[to].push_back(edge_t({fr, c}));
    }
    // PROCESS
    edge_t ret = dijkstra(adj);
    // OUTPUT
    fout << ret.to << " " << ret.c << endl;

    return 0;
}
