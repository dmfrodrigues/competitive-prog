#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
typedef pair< lli, lli>         PII;
#define X first
#define Y second

int main(){
    lli ret = 0;
    lli N; cin >> N;
    FOR(n,0,N){
        lli P; cin >> P;
        vector<PII> v(P);
        for(PII &p:v) cin >> p.X >> p.Y;
        lli add = 0;
        FOR(i,0,P){
            lli j = (i+1)%P;
            add += (v[j].X+v[i].X)*(v[j].Y-v[i].Y);
        }
        ret += abs(add);
    }
    cout << ret/2 << endl;
    return 0;
}
