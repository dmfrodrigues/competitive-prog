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

const int inf = 500000;

struct node_t {
    int x, y;

    bool operator<(const node_t &v) const {
        if(x < v.x) return true;
        if(x == v.x && y < v.y) return true;
        return false;
    }

    bool operator==(const node_t &v) const {
        return (x == v.x && y == v.y);
    }
};

namespace std{
    template<> struct hash<node_t>{
        size_t operator()(const node_t &v) const{
            size_t ret = 0;
            ret ^= v.x + 0x9e3779b9 + (ret<<6) + (ret>>2);
            ret ^= v.y + 0x9e3779b9 + (ret<<6) + (ret>>2);
            return ret;
        }
    };
}

node_t go(const node_t &u, const char &c){
    switch(c){
        case 'N': return {u.x, u.y+1};
        case 'S': return {u.x, u.y-1};
        case 'E': return {u.x+1, u.y};
        case 'W': return {u.x-1, u.y};
        default: throw invalid_argument("c can't be " + string(1,c) + ", can only be one of N,S,E,W");
    }
}

int bfs(const unordered_map<node_t, set<node_t>> &adj, const node_t &finish){
    unordered_map<node_t, int> dist;
    queue<node_t> q;

    for(const auto &p: adj) dist[p.first] = inf;

    dist[{0,0}] = 0; q.push({0,0});

    while(!q.empty()){
        node_t u = q.front(); q.pop();
        if(u == finish) return dist[u];
        for(const node_t &v: adj.at(u)){
            if(dist[v] == inf){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }

    return inf;
}

int main(){
    int M; cin >> M;
    unordered_map<node_t, set<node_t>> adj;
    node_t u = {0,0};
    adj[u];
    FOR(i,0,M){
        string s; cin >> s;
        for(const char &c: s){
            node_t v = go(u, c);
            adj[u].insert(v);
            adj[v].insert(u);
            u = v;
        }
    }

    cout << bfs(adj, u) << endl;

    return 0;
}
