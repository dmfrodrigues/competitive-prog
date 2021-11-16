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
const lli INF = 1000000000;

#define MAXN 10000

string solve(const string &s){
    string sol = "";
    int n = 0;
    FOR(i,0,s.size()){
        int n_ = s[i]-'0';
        while(n_ < n){ sol += ')'; --n; }
        while(n_ > n){ sol += '('; ++n; }
        sol += s[i];
    }
    while(n > 0){ sol += ')'; --n; }
    return sol;
}

int main(){
    lli T; cin >> T;
    FOR(t,0,T){
        string s; cin >> s;
        string sol = solve(s);
        cout << "Case #" << t+1 << ": " << sol << "\n";
    }
    cout << flush;
    return 0;
}
