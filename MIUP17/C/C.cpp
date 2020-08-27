#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < lli(e); ++(i))
typedef vector<lli> VI;

int main(){
    /// INPUT
    lli N, M, K; cin >> N >> M >> K;
    deque< pair< deque<lli>, lli> > v(M);
    FOR(i,0,M){
        lli r; cin >> r;
        lli p;
        FOR(j,0,r){ cin >> p; v[i].first.push_back(p); }
        cin >> v[i].second;
    }
    /// PROCESSING
    vector<bool> b(N, false); lli S = 0;
    lli S_prev = -1;
    while(S != S_prev){
        S_prev = S;
        for(const auto &c:v){
            if(b[c.second]) continue;
            bool good = true;
            for(const lli &i:c.first){
                if(!b[i]){
                    good = false;
                    break;
                }
            }
            if(good){
                b[c.second] = true;
                ++S;
            }
        }
        if(b[K]){ cout << "YES" << endl; return 0; }
    }
    /// OUTPUT
    cout << "NO" << endl;
    return 0;
}
