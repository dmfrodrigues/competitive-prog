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

typedef vector< unordered_map<lli, lli> > Graph;

lli B;

lli distance(const PII &a, const PII &b){
    lli dx = a.X - b.X, dy = a.Y - b.Y;
    return ceil(sqrt(dx*dx+dy*dy));
}

lli dijkstra(const vector<PII> &pos, const Graph &g, lli src, lli dst){
    const size_t &N = pos.size();
    VI dist(N, INF); VI co2(N, INF);
    vector<bool> visited(N, false);
    priority_queue<PII, vector<PII>, greater<PII> > q; //cost so far, node
    dist[src] = 0; co2[src] = 0; q.push({co2[src], src});
    while(!q.empty()){
        lli u = q.top().second; q.pop();
        cout << u << ": " << dist[u] << " " << co2[u] << endl;
        if(u == dst) return co2[u];
        if(visited[u]){ continue; } visited[u] = true;
        for(const auto& e : g[u]){
            const lli &v = e.first;
            lli cost_co2  = co2 [u] + e.second;
            lli cost_dist = dist[u] + distance(pos[u], pos[v]);
            if (cost_dist <= B && cost_co2 < co2[v]) {
                dist[v] = cost_dist;
                co2 [v] = cost_co2;
                q.push({dist[v], v});
            }
        }
    }

    throw invalid_argument("");
}

int main(){
    // INPUT
    PII src; cin >> src.X >> src.Y;
    PII dst; cin >> dst.X >> dst.Y;
    cin >> B;
    lli C0; cin >> C0;
    lli T; cin >> T;
    VI C(T+1); C[0] = C0;
    FOR(i,1,T+1) cin >> C[i];
    lli N; cin >> N;
    vector<PII> pos(N+2); pos[N] = src; pos[N+1] = dst;
    vector< vector<PII> > links(N);
    FOR(i,0,N){
        cin >> pos[i].X >> pos[i].Y;
        lli l; cin >> l;
        links[i] = vector<PII>(l);
        FOR(j,0,l){
            cin >> links[i][j].first >> links[i][j].second;
        }
    }

    Graph g(N+2);
    // Add paths to src and dst
    FOR(i,0,N){
        lli d = distance(src, pos[i]);
        g[N][i] = d*C0;
        g[i][N] = d*C0;
    }

    // Add other paths
    FOR(u,0,N){
        const vector<PII> &node_links = links[u];
        for(const PII &p: node_links){
            lli v = p.first;
            lli Ci = C[p.second];
            lli d = distance(pos[u], pos[v]);
            lli c = (g.at(u).count(v) ? g.at(u).at(v) : INF);
            c = min(c, d*Ci);
            g[u][v] = c;
            g[v][u] = c;
        }
    }

    // g now has CO2 costs
    lli ret = dijkstra(pos, g, N, N+1);

    // OUTPUT
    cout << ret << endl;

    return 0;
}
