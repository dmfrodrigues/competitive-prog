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
const lli INF = 100000000;

int main(){
    lli M; cin >> M;
    lli ret = 0;
    FOR(a,1,(M-1)/2 + 1){
        FOR(b,1,a+1){
            lli cMin = max(max(a-b+1, b-a+1), 1LL);
            lli cMax = min(min(a+b-1, M-a-b), b);
            lli cNum = max(cMax-cMin+1, 0LL);
            ret += cNum;
        }
    }
    cout << ret << endl;
    return 0;
}
