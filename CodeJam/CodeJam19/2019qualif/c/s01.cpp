#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long  ULLI;
//#define REP(i, b, e)            for(ULLI i =(b); (i) != (e); ++(i))
typedef vector<ULLI>             VI;

string solve(ULLI N, const VI& vtr){



    N += 10;
    ULLI L = vtr.size();
    VI numv(L+1); set<ULLI> myset;
    for(ULLI n = 2; n <= N; ++n){
        if(vtr.at(0)%n == ULLI(0)){
            numv.at(0) = n;
            myset.insert(n);
            break;
        }
    }



    ULLI n;
    for(ULLI i = 0; i < L; ++i){
        n = vtr.at(i)/numv.at(i);
        numv.at(i+1) = n; myset.insert(n);
    }
    map<ULLI, char> mymap;
    char cr = 'A';
    for(const auto& i:myset) mymap[i] = cr++;
    string ret = "";
    for(const auto& i:numv){
        ret += mymap[i];
    }
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
