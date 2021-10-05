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
        ///INPUT
        lli n, H; cin >> n >> H;
        lli best1 = 0, best2 = 0;
        lli a_in;
        FOR(i,0,n){
            cin >> a_in;
            if(a_in > best2) best2 = a_in;
            if(best2 > best1) swap(best1, best2);
        }

        ///PROCESSING
        lli sol = 0;
        lli b = best1+best2;
        lli m = H/b;
        H -= m*b;
        sol += 2*m;
        if(H > 0){
            sol += (H <= best1 ? 1 : 2);
        }

        ///OUTPUT
        cout << sol << endl;
    }
    return 0;
}
