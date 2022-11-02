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
    string s, t;
    cin >> s >> t;

    {
        size_t a = s.find_last_of("#"); if(a == string::npos) a = -1;
        s = s.substr(a+1, string::npos);
    }
    {
        size_t b = t.find_last_of("#"); if(b == string::npos) b = -1;
        t = t.substr(b+1, string::npos);
    }
    cout << (s == t ? "True" : "False") << endl;

    return 0;
}
