/*
ID: dmfrodr1
TASK: cowtour
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

typedef int node_t;

typedef double dist_t;
const dist_t INF = 1000000000;

struct pos_t {
    int x, y;
    dist_t dist(){
        return sqrt(x*x + y*y);
    }
    pos_t operator-(const pos_t &u) const {
        return pos_t({x-u.x, y-u.y});
    }
};

vector<node_t> getFields(const vector<pos_t> &pos, const vector<list<node_t> > &adj){
    const node_t N = pos.size();
    vector<node_t> ret(N);
    vector<bool> visited(N, false);
    queue<node_t> q;
    FOR(i,0,N){
        q.push(i);
        while(!q.empty()){
            node_t u = q.front(); q.pop();
            if(visited[u]) continue;
            visited[u] = true;
            ret[u] = i;
            for(node_t v: adj[u]) q.push(v);
        }
    }
    return ret;
}

dist_t getMaxDist(node_t i, const vector<pos_t> &pos, const vector<list<node_t>> &adj){
    const auto &N = pos.size();
    vector<dist_t> dist(N, INF);
    vector<bool> visited(N);
    priority_queue<pair<dist_t,int>, vector<pair<dist_t,int>>, greater<pair<dist_t,int>>> a;
    dist[i] = 0.0; a.push({0.0, i});
    while(!a.empty()){
        node_t u = a.top().second; a.pop();
        if(visited[u]){ continue; } visited[u] = true;
        for(const node_t &v : adj[u]){
            if (dist[v] > dist[u] + (pos[v]-pos[u]).dist()) {
                dist[v] = dist[u] + (pos[v]-pos[u]).dist();
                a.push({dist[v], v});
            }
        }
    }
    dist_t ret = 0.0;
    FOR(i,0,N) if(visited[i]) ret = max(ret, dist[i]);
    return ret;
}

unordered_map<node_t, dist_t> getFieldsDiameter(const vector<node_t> &fields, const vector<dist_t> &maxDist){
    const size_t &N = fields.size();

    unordered_map<node_t, dist_t> ret;
    FOR(i,0,N){
        if(!ret.count(fields[i])) ret[fields[i]] = 0.0;
        ret[fields[i]] = max(ret[fields[i]], maxDist[i]);
    }

    return ret;
}

int main(){
    // INPUT FILES
    ifstream fin("cowtour.in");
    ofstream fout("cowtour.out");
    // INPUT
    node_t N;
    fin >> N;
    vector<pos_t> pos(N);
    FOR(i,0,N) fin >> pos[i].x >> pos[i].y;
    vector<list<node_t>> adj(N);
    FOR(i,0,N){
        string line;
        fin >> line;
        FOR(j,0,N) if(line[j] == '1') adj[i].push_back(j);
    }
    // PROCESS
    vector<node_t> fields = getFields(pos, adj);
    vector<dist_t> maxDist(N);
    FOR(i,0,N) maxDist[i] = getMaxDist(i, pos, adj);
    unordered_map<node_t, dist_t> fieldDiameter = getFieldsDiameter(fields, maxDist);
    
    dist_t sol = INF;
    FOR(i,0,N) FOR(j,i+1,N){
        if(fields[i] == fields[j]) continue;
        sol = min(
            sol,
            max(
                max(
                    fieldDiameter[fields[i]],
                    fieldDiameter[fields[j]]
                ),
                maxDist[i] + (pos[j]-pos[i]).dist() + maxDist[j]
            )
        );
    }

    fout << fixed << setprecision(6) << sol << endl;

    return 0;
}
