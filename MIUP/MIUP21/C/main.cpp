/**
 * Complexity: O(log N)
 */

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

// 2y = 3x²+x
// Given y, find the largest integer x such that 2y >= 3x²+x

int main(){
    lli y; cin >> y;
    lli yy = 2*y;
    lli l = 0, r = INF;
    while(r-l > 1){
        lli m = l + (r-l)/2;
        lli f = 3*m*m + m;
        if(f == yy){ l = m; r = m+1; }
        else if(f < yy){
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << endl;

    return 0;
}
