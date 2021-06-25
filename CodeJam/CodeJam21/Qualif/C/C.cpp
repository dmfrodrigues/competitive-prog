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

VI Reversort_create(lli N, lli C){
    C -= N-1;
    VB reversed(N-1, false);
    for(lli i = 0; i < N-1; ++i){
        lli cost = (N-i)-1;
        if(C < cost) continue;
        C -= cost;
        reversed.at(i) = true;
    }
    // for(auto b: reversed) cerr << b << " "; cerr << endl;
    VI v(N);
    FOR(i,0,N) v.at(i) = i+1;
    for(lli i = N-2; i >= 0; --i){
        // have to reverse v[i..N-1]
        if(!reversed[i]) continue;
        reverse(v.begin() + i, v.end());
    }
    if(C != 0) return {};
    return v;
}

lli Reversort(const VI &L_in){
    VI L = L_in;
    lli ret = 0;
    FOR(idx, 0, L.size()-1){
        auto i = L.begin() + idx;
        auto j = min_element(i, L.end())+1;
        reverse(i, j);
        ret += (j - i);
    }
    return ret;
}

int main(){
    int T; cin >> T;
    FOR(t,0,T){
        lli N, C; cin >> N >> C;
        cout << "Case #" << t+1 << ":";
        VI sol = Reversort_create(N, C);
        if(sol != VI({})){
            for(const auto &i: sol) cout << " " << i;
            cout << endl;
            if(C != Reversort(sol)){
                cerr << "WRONG! expected " << C << ", got " << Reversort(sol) << endl;
                exit(1);
            }
        } else{
            cout << " IMPOSSIBLE" << endl;
        }
    }

    return 0;
}
