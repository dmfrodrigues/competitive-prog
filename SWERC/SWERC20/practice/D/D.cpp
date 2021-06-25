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
const lli INF = 10000000000000000;

lli cost(const VI &v1, const VI &v2){
    const size_t &N = v1.size();
    unordered_map<lli, size_t> m1, m2;
    FOR(i,0,N){
        if(v1[i] != 0) m1[v1[i]] = i;
        if(v2[i] != 0) m2[v2[i]] = i;
    }
    lli ret;
    for(const auto &p: m1){
        const lli &S = p.first;
        ret += S*abs(lli(m1[S]-m2[S]));
    }
    cout << ret;
    return ret;
}

int main(){
    // INPUT
    lli N, K; cin >> N >> K;
    VI v(N, 0);
    FOR(i,0,K){
        lli P, S; cin >> P >> S;
        P -= 1;
        v[P] = S;
    }
    // PROCESS
    VI v_sol(ALL(v));
    sort(ALL(v_sol));
    lli c = cost(v, v_sol);
    FOR(i,0,N){
        VI v_perhaps = v_sol;
        lli j = N-1; while(j >= 0 && v_perhaps[j] != 0) --j;
        for(lli j = N-1; j > i; --j) v_perhaps[j] = v_perhaps[j-1];

        lli c_perhaps = cost(v, v_perhaps);
        if(c > c_perhaps){
            v_sol = v_perhaps;
            c = c_perhaps;
        }
    }

    cout << c << endl;

    return 0;

}
