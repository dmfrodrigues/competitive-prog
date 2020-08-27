#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
//#define REP(i, b, e)            for(auto i =(b); (i) != (e); ++(i))
typedef vector<lli>             VI;
typedef pair< lli, lli>         PII;
#define X first
#define Y second

lli solve(VI C, VI D, lli K){
    
}

int main(){
    int T; cin >> T;
    FOR(t,0,T){
        int N, K; cin >> N >> K;
        VI C(N);
        VI D(N);
        for(auto& i:C) cin >> i;
        for(auto& i:D) cin >> i;
        lli ans = solve(C,D,K);
        printf("Case #%Ld: %Ld\n", t+1, ans);
    }
    return 0;
}
