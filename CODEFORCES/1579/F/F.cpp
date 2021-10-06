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

int main(){
    int T; cin >> T;
    FOR(t,0,T){
        // INPUT
        size_t N, D; cin >> N >> D;
        vector<bool> a(N);
        bool b;
        FOR(i,0,N){ cin >> b; a[i] = b; }

        // PROCESSING
        vector<size_t> dist(N, INF);

        queue<size_t> q;
        FOR(i,0,N) if(!a[i]){
            dist[i] = 0;
            q.push(i);
        }

        while(!q.empty()){
            size_t u = q.front(); q.pop();
            size_t v = (u+D)%N;
            size_t d = dist[u] + 1;
            if(dist[v] > d){
                dist[v] = d;
                q.push(v);
            }
        }

        // OUTPUT
        if(find(ALL(dist), INF) != dist.end()){
            cout << -1 << endl;
        } else {
            cout << *max_element(ALL(dist)) << endl;
        }
    }

    return 0;
}
