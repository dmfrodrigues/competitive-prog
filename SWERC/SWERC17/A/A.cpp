#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n)        for (lli i = 0; i < lli(n); i++)
#define REP(i, b, e)    for (lli i=b; i < lli(e); ++i)
#define ALL(v)          (v).begin() , (v).end()
typedef long long int lli;
typedef vector<int> VI;

lli solve(const VI& inVtr, const VI& outVtr){
    unordered_map<lli,lli> counter;
    lli t;
    for(const auto& tout:outVtr){
        for(const auto& tin:inVtr){
            t = tout-tin;
            if(t >= 0){
                ++counter[t];
            }
        }
    }
    lli ret = 0, c = 0;
    for(auto it = counter.begin(); it != counter.end(); ++it){
        if(it->second > c ||
           (it->second == c && it->first < ret)){
            ret = it->first;
            c = it->second;
        }
    }
    return ret;
}

int main(){
    int M, N; cin >> N >> M;
    VI Nvtr(N);
    for(auto& n:Nvtr)
        cin >> n;
    VI Mvtr(M);
    for(auto& m:Mvtr)
        cin >> m;
    lli ans = solve(Nvtr, Mvtr);
    cout << ans << endl;
}

[close]
