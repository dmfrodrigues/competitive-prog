#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define contain(Set,i)          ( (Set) & (1Lu<<(i)) )
#define mk(a,b)                 make_pair((a), (b))
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
//#define REP(i, b, e)            for(auto i =(b); (i) != (e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
typedef pair< lli, lli>         PII;
typedef pair<ulli,ulli>         PUU;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second

vector<PII> solve(int R, int C){
    vector<PII> v;
    if((R >= 3 && C >= 4)||(R == 2 && C >= 5)){
        for(int c = 3; c <= C; ++c){
            for(int r = 1; r <= R; r += 2){
                v.push_back({r,c});
                if(r+1 <= R) v.push_back({r+1,c-2});
            }
        }
        for(int r = 1; r <= R; r += 2){
            v.push_back({r,1});
            if(r+1 <= R) v.push_back({r+1, C-1});
        }
        for(int r = 1; r <= R; r += 2){
            v.push_back({r,2});
            if(r+1 <= R) v.push_back({r+1, C});
        }
    }else if((C >= 3 && R >= 4)||(C == 2 && R >= 5)){
        for(int r = 3; r <= R; ++r){
            for(int c = 1; c <= C; c += 2){
                v.push_back({r,c});
                if(c+1 <= C) v.push_back({r-2,c+1});
            }
        }
        for(int c = 1; c <= C; c += 2){
            v.push_back({1,c});
            if(c+1 <= C) v.push_back({R-1,c+1});
        }
        for(int c = 1; c <= C; c += 2){
            v.push_back({2,c});
            if(c+1 <= C) v.push_back({R,c+1});
        }
    }
    return v;
}

int main(){
    int T; cin >> T;
    int R, C;
    FOR(t,1,T+1){
        cin >> R >> C;
        auto v = solve(R,C);
        if(v.empty()) printf("Case #%Ld: IMPOSSIBLE\n", t);
        else{
            printf("Case #%Ld: POSSIBLE\n", t);
            for(auto p:v) printf("%Ld %Ld\n", p.first, p.second);
        }
    }
    return 0;
}
