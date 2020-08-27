#include <bits/stdc++.h>
using namespace std;
typedef long long int           LLI;
typedef unsigned long long int  ULLI;
typedef long double             LD;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, n)               for(ULLI i = 0 ; (i)  < (n); ++(i))
#define REP(i, b, e)            for(LLI i =(b); (i) != (e); ++(i))
typedef vector<LLI>             VI;

string solve(int N, string s){
    if(s[0] == 'S'){
        if(s[s.size()-1] == 'E') return string(N-1, 'E') + string(N-1, 'S');
        else{
            int c = 0;
            for(unsigned i = 0; i+1 < s.size(); ++i){
                if(s[i] == 'E') ++c;
                if(s[i] == 'E' && s[i+1] == 'E') break;
            }
            return string(c, 'E') + string(N-1, 'S') + string(N-1-c, 'E');
        }
    }else{
        if(s[s.size()-1] == 'S') return string(N-1, 'S') + string(N-1, 'E');
        else{
            int c = 0;
            for(unsigned i = 0; i+1 < s.size(); ++i){
                if(s[i] == 'S') ++c;
                if(s[i] == 'S' && s[i+1] == 'S') break;
            }
            return string(c, 'S') + string(N-1, 'E') + string(N-1-c, 'S');
        }
    }
}

int main(){
    int T; cin >> T;
    int N; string s, ans;
    for(int t = 0; t < T; ++t){
        cin >> N >> s;
        ans = solve(N, s);
        printf("Case #%d: %s\n", t+1, ans.c_str());
    }
    return 0;
}
