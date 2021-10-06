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

lli solve(lli X, lli Y, string S){
    lli ret = 0;

    size_t i;
    for(i = 0; i < S.size(); ++i) if(S[i] != '?') break;
    char c = S[i];
    for(; i < S.size(); ++i){
        if     (c == 'C' && S[i] == 'J'){ ret += X; c = S[i]; }
        else if(c == 'J' && S[i] == 'C'){ ret += Y; c = S[i]; }
    }

    return ret;
}

int main(){
    int T; cin >> T;
    FOR(t,0,T){
        int X, Y; cin >> X >> Y;
        string S; cin >> S;
        cout << "Case #" << t+1 << ": " << solve(X, Y, S) << endl;
    }

    return 0;
}

