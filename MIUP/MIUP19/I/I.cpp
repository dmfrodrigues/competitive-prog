/**
 * Process from the top to the bottom. Keep a set of ranges R of shields that we
 * might want to turn on later, and a set of buildings B that are not yet
 * protected.
 * 
 * If we find a building that is not protected and cannot be protected by any of
 * the shields in R nor by any shield at the same level, enable it, remove from
 * B the buildings that are now protected, and continue;
 * 
 * If we find a building that is protected, add its shield to R.
 * 
 * If we find a building that is not protected but can be protected by some of
 * the shields in R (R'), we are forced to choose one of the shields in R'.
 * 
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
const lli INF = 1000000000;

int main(){
    

    return 0;
}
