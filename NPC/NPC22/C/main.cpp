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

int gcd(int a, int b){
    if(b) return gcd(b, a%b); else return a;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(){
    int C; cin >> C;
    int res = 1000000000;
    FOR(c,0,C){
        int y, c1, c2;
        cin >> y >> c1 >> c2;
        res = min(res, y + lcm(c1, c2));
    }
    cout << res << endl;

    return 0;
}
