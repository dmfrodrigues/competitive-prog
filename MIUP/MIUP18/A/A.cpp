#include <bits/stdc++.h>
typedef long long int lli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < (e); (i)++)

using namespace std;
typedef vector<lli> VI;
typedef vector<VI> VVI;

int main(){
    ///INPUT
    lli N, R; cin >> N >> R;
    VVI m(R, VI(4));
    for(VI &v:m) for(lli &i:v){ cin >> i; --i; }
    ///PROCESSING
    VI ret(4, 0);
    FOR(x,0,N){
        VI diff(N, 0);
        for(VI &v:m){
            if(v[0] <= x && x <= v[2]){
                diff[v[1]] += 1;
                if(v[3]+1 < N) diff[v[3]+1] -= 1;
            }
        }
        int c = 0;
        for(lli &d: diff){
            c = (c+d+4)%4;
            ++ret[c];
        }
    }
    ///OUTPUT
    cout << ret[0] << " " << ret[1] << " " << ret[2] << " " << ret[3] << endl;
    return 0;
}
