#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i)=(b); (i) < lli(e); (i)++)
typedef vector<lli> VI;

int main(){
    lli S, P; cin >> S >> P;
    VI v(P);
    for(lli &i:v) cin >> i;
    VI s(P, 0);
    FOR(k,0,S){
        lli i = 0;
        FOR(j,0,P){
            lli ki = v[i]*(s[j]+1);
            lli kj = v[j]*(s[i]+1);
            if     ( ki  !=  kj ){ i = ( ki  >  kj ? i : j); }
            else if(v[i] != v[j]){ i = (v[i] < v[j]? i : j); }
            else                 { i = i; }
        }
        ++s[i];
    }
    FOR(i,0,P) cout << s[i] << endl;
    return 0;
}
