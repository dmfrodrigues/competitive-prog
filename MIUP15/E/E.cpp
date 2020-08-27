#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < lli(e); ++(i))
#define INF 1000000000L
typedef vector<lli> VI;
typedef vector<VI> VVI;

VVI DP; //0->nada; 1->canoa; 2->tabua; 3->balao

lli solve(const string &s){
    const lli &N = s.size();
    DP = VVI(N+1, VI(4, INF)); //`DP[i][0]` descreve quanto tempo demorou a chegar ligeiramente antes da zona `i`.
    DP[0][0] = 0;
    FOR(i,1,N+1){
        const char &c = s[i-1];
        if(c == '_' || c == 'c' || c == 'p' || c == 'b'){
            DP[i][0] = min(DP[i-1][0]+1,    //vem sem nada e sai sem nada
                       min(DP[i-1][1]+2,    //vem com canoa e deixa
                       min(DP[i-1][2]+2,    //vem com tabua e deixa
                           DP[i-1][3]+2))); //vem com balao e deixa
            DP[i][1] = DP[i-1][1]+3;        //vem com canoa e sai com a canoa
            DP[i][2] = DP[i-1][2]+3;        //vem com tabua e sai com a tabua
            DP[i][3] = DP[i-1][3]+3;        //vem com balao e sai com a balao
            switch(c){
                case 'c': DP[i][1] = min(DP[i][1], DP[i-1][0]+2); break; //vem sem nada  e apanha canoa
                case 'p': DP[i][2] = min(DP[i][2], DP[i-1][0]+2); break; //vem sem nada  e apanha tabua
                case 'b': DP[i][3] = min(DP[i][3], DP[i-1][0]+2); break; //vem sem nada  e apanha balao
                default: break;
            }
        }
        if(c == 'L'                        ) DP[i][1] = DP[i-1][1]+4;
        if(c == 'L' || c == 'P'            ) DP[i][2] = DP[i-1][2]+5;
        if(c == 'L' || c == 'P' || c == 'M') DP[i][3] = DP[i-1][3]+6;
    }
    lli ret = min(DP[N][0],
              min(DP[N][1],
              min(DP[N][2],
                  DP[N][3])));
    return ret;
}

int main(){
    int N; cin >> N;
    while(N--){
        string s; cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
