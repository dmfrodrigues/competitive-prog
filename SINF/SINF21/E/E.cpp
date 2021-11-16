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

lli M, N;
vector<vector<bool>> m;

int main(){
    cin >> M >> N;
    m = vector<vector<bool>>(M, vector<bool>(N, false));
    VVI dist(M, VI(N, INF));
    queue<PII> q;
    int in;
    FOR(x,0,M) FOR(y,0,N){
        cin >> in;
        if(in == 1 || in == 2) m[x][y] = true;
        if(in == 2){
            q.push(make_pair(x, y));
            dist[x][y] = 0;
        }
    }

    // FOR(x,0,M){
    //     FOR(y,0,N) cout << m[x][y];
    //     cout << endl;
    // }

    while(!q.empty()){
        PII u = q.front(); q.pop();
        lli d = dist[u.X][u.Y];
        // cout << "u=" << u.X << "," << u.Y << "  d=" << d << endl;
        if(u.X-1 >= 0 && m[u.X-1][u.Y] && dist[u.X-1][u.Y] == INF){ dist[u.X-1][u.Y] = d+1; q.push(make_pair(u.X-1, u.Y)); /*cout << "Added " << u.X-1 << "," << u.Y << endl;*/ }
        if(u.X+1 <  M && m[u.X+1][u.Y] && dist[u.X+1][u.Y] == INF){ dist[u.X+1][u.Y] = d+1; q.push(make_pair(u.X+1, u.Y)); /*cout << "Added " << u.X+1 << "," << u.Y << endl;*/ }
        if(u.Y-1 >= 0 && m[u.X][u.Y-1] && dist[u.X][u.Y-1] == INF){ dist[u.X][u.Y-1] = d+1; q.push(make_pair(u.X, u.Y-1)); /*cout << "Added " << u.X << "," << u.Y-1 << endl;*/ }
        if(u.Y+1 <  N && m[u.X][u.Y+1] && dist[u.X][u.Y+1] == INF){ dist[u.X][u.Y+1] = d+1; q.push(make_pair(u.X, u.Y+1)); /*cout << "Added " << u.X << "," << u.Y+1 << endl;*/ }
    }

    lli sol = -INF;
    FOR(x,0,M) FOR(y,0,N){
        if(m[x][y]) sol = max(sol, dist[x][y]);
    }

    if(sol == INF) cout << -1 << endl;
    else if(sol == -INF) cout << 0 << endl;
    else cout << sol << endl;

    return 0;
}
