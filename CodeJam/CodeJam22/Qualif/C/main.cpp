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
    FOR(i,0,T){
        int N; cin >> N;
        priority_queue<
            lli,
            vector<lli>,
            greater<lli>
        > q;
        FOR(j,0,N){
            lli s; cin >> s;
            q.push(s);
        }
        lli sol = 0;
        while(!q.empty()){
            lli s = q.top(); q.pop();
            if(s >= sol+1) ++sol;
        }
        cout << "Case #" << i+1 << ": " << sol << "\n";
    }
}
