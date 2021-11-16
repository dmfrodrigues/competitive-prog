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

string solve(vector<string> v){
    if(v.empty()) return "";

    string l = "";{
        for(const string &s:v){
            int i = find(ALL(s), '*')-s.begin();
            if(i > l.size()) l = s.substr(0, i);
        }
        for(const string &s:v){
            int i = find(ALL(s), '*')-s.begin();
            if(!equal(s.begin(), s.begin()+i, l.begin())) return "*";
        }
    }

    

}

int main(){
    lli T; cin >> T;
    FOR(t,0,T){
        lli N; cin >> N;
        vector<string> v(N);
        for(string &s:v){
            cin >> s;
        }
        string ans = solve(v);
        cout << ans << endl;
    }
    return 0;
}
