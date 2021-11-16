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

void solve(int R, int C){
    vector<PII> v;
    if(R%2 == 0 && C >= 4){ //R par
        for(int r = 1; r <= R; r += 2){
            for(int c = 3; c <= C; ++c) v.push_back({r, c}), v.push_back({r+1, c-2});
            v.push_back({r+1, C-1}), v.push_back({1,1}), v.push_back({r+1,C}), v.push_back({1,2});
        }
    }else if(C%2 == 0 && R >= 4){ //C par
        for(int c = 1; c <= C; c += 2){
            for(int r = 3; r <= R; ++r) v.push_back({r, c}), v.push_back({r-2,c+1});
            v.push_back({R-1, c+1}), v.push_back({1,1}), v.push_back({R,c+1}), v.push_back({2,1});
        }
    }else{ //ambos ímpares e maiores que 4, ou então um deles é 1 ou 3
        if(R >=4 && C >= 4){
            for(int c = 3; c <= C; ++c){
                for(int r = 1; r <= R; r += 2){
                    
                }
            }
        }
    }
    if(v.empty()) cout << "IMPOSSIBLE" << endl;
    else{
        cout << "POSSIBLE" << endl;
        for(auto p:v) cout << p.first << " " << p.second << endl;
    }
}

int main(){
    int T; cin >> T;
    int R, C;
    FOR(t,0,T){
        cin >> R >> C;
        cout << "Case #" << t+1 << ": ";
        solve(R,C);
    }
    return 0;
}
