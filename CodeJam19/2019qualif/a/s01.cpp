#include <bits/stdc++.h>
using namespace std;
typedef long long int           LLI;
typedef unsigned long long int  ULLI;
typedef long double             LD;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, n)               for(ULLI i = 0 ; (i)  < (n); ++(i))
#define REP(i, b, e)            for(LLI i =(b); (i) != (e); ++(i))
typedef vector<LLI>             VI;

int main(){
    int T; cin >> T;
    string Ns, As, Bs;
    for(int t = 0; t < T; ++t){
        cin >> Ns;
        As = Bs = "";
        for(auto c:Ns){
            if(c == '4'){
                As += '3';
                Bs += '1';
            }else{
                As += c;
                Bs += '0';
            }
        }
        printf("Case #%d: %d %d\n", t+1, stoi(As), stoi(Bs));
    }
    return 0;
}
