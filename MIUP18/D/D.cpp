#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i, b, e) for(lli (i) = (b); (i) < lli(e); (i)++)

int main(){
    ///INPUT
    lli omega, z, tmax, n, p; cin >> omega >> z >> tmax >> n >> p;
    vector<bool> g(360, false);
    lli s, e;
    while(n--){
        cin >> s >> e;
        FOR(i,s,e) g[i] = true;
        g[e%360] = true;
    }
    vector<int> period(p, 0);
    FOR(i,0,p) cin >> period[i];
    ///PROCESSING
    omega = (360-omega%360)%360;
    lli pos = z;
    lli ret = 0;
    FOR(t,0,tmax){
        if(period[t%p]){
            if(g[pos]) ++ret;
            else break;
        }
        pos = (pos+omega)%360;
    }
    ///OUTPUT
    cout << ret << endl;
    return 0;
}
