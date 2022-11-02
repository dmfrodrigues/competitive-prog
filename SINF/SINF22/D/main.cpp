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

lli NMAX = 200000;
lli GMAX = 200;

lli bfs(PII src, PII dst) {
    map<PII, lli> dist;
    queue<PII> q;
    dist[src] = 0; q.push(src);
    while(!q.empty()){
        PII u = q.front(); q.pop();
        if(u == dst) return dist[u];
        PII v;
        v = PII(u.X-2, u.Y-1); if(!dist.count(v)){ dist[v] = dist[u] + 1; q.push(v); }
        v = PII(u.X+2, u.Y-1); if(!dist.count(v)){ dist[v] = dist[u] + 1; q.push(v); }
        v = PII(u.X-2, u.Y+1); if(!dist.count(v)){ dist[v] = dist[u] + 1; q.push(v); }
        v = PII(u.X+2, u.Y+1); if(!dist.count(v)){ dist[v] = dist[u] + 1; q.push(v); }
        v = PII(u.X-1, u.Y-2); if(!dist.count(v)){ dist[v] = dist[u] + 1; q.push(v); }
        v = PII(u.X+1, u.Y-2); if(!dist.count(v)){ dist[v] = dist[u] + 1; q.push(v); }
        v = PII(u.X-1, u.Y+2); if(!dist.count(v)){ dist[v] = dist[u] + 1; q.push(v); }
        v = PII(u.X+1, u.Y+2); if(!dist.count(v)){ dist[v] = dist[u] + 1; q.push(v); }
    }
    return INF;
}

int main(){
    PII src, dst;
    cin >> src.X >> src.Y;
    cin >> dst.X >> dst.Y;

    cout << bfs(src, dst) << endl;

    return 0;
}
