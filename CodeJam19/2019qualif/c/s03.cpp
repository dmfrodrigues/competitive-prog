#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long  ULLI;
typedef vector<ULLI>             VI;

ULLI isqrt(ULLI n){
    auto x = n;
    auto y = (x+1)/2;
    while(y < x){
        x = y;
        y = (x+n/x)/2;
    }
    return x;
}

string solve(ULLI N, const VI& v){
    ULLI L = v.size();
    VI vn(L+1);
    for(ULLI i = 1; i < L+1; ++i){
        if(v[i-1] == v[i]) vn[i] = isqrt(v[i]);
        else               vn[i] = gcd(v[i-1, i]);
    }
    vn[0] = v[0]/vn[1];
    vn[L] = v[L-1]/vn[L-1]

    set<ULLI> s(vn.begin(), vn.end());
    map<ULLI,char> m;
    char c = 'A';
    for(const auto& i:s) m[i] = c++;

    string ret = "";
    for(const auto& i:vn) ret += m[i];

    return ret;

}

int main(){
    int T; cin >> T;
    for(int t = 0; t < T; ++t){
        ULLI N, L; cin >> N >> L;
        VI v(L);
        for(ULLI i = 0; i < L; ++i) cin >> v[i];
        string ans = solve(N, v);
        printf("Case #%d: %s\n", t+1, ans.c_str());
    }
    return 0;
}
