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
const lli INF = 1000000000;

int main(){
    lli t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> v(n); for(string &s:v) cin >> s;
        int k = 0;
        bool used[10] = {false};
        for(string &s:v){
            if(used[s[0]-'0'] && count(ALL(v), s) > 1){
                int i;
                for(i = 0; i < 10; ++i){
                    string changed = s;
                    changed[0] = '0'+i;
                    if(!used[i] && find(ALL(v), changed) == v.end()) break;
                }
                s[0] = '0'+i;
                ++k;
            }
            used[s[0]-'0'] = true;
        }
        cout << k << endl;
        for(const string &s:v) cout << s << endl;
    }
    return 0;
}
