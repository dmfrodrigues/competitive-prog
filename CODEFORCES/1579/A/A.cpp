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

int main(){
    int T; cin >> T;
    FOR(t,0,T){
        // INPUT
        string s; cin >> s;
        // PROCESSING
        int a = 0, b = 0, c = 0;
        for(const char &ch: s){
            switch(ch){
                case 'A': ++a; break;
                case 'B': ++b; break;
                case 'C': ++c; break;
            }
        }
        bool yes = (a+c == b);
        if(yes) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
