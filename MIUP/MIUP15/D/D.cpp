#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < lli(e); ++(i))
typedef vector<lli> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef vector<VVVI> VVVVI;

VVVVI DP;

lli KMAX;
lli NMAX;

lli f(int n, int a, int b, int k){
    if(n < 1 || n-a > a || k > min(KMAX,NMAX) || k <= 0) return 0;
    if(DP[n][a][b][k] != -1) return DP[n][a][b][k];
    if(k > 1){
        if(b) return DP[n][a][b][k] = f(n-1,a  ,1,k-1);
        else  return DP[n][a][b][k] = f(n-1,a-1,0,k-1);
    }
    DP[n][a][b][k] = 0;
    if(b) FOR(k_,1,KMAX+1) DP[n][a][b][k] += f(n-1,a  ,0,k_); //termina em B
    else  FOR(k_,1,KMAX+1) DP[n][a][b][k] += f(n-1,a-1,1,k_);   //termina em A
    return DP[n][a][b][k];
}

int main(){
    int T; cin >> T;
    while(T--){
        cin >> NMAX >> KMAX;
        DP = VVVVI(NMAX+1, VVVI(NMAX/2+1, VVI(2, VI(KMAX+1, -1))));
        DP[1][1][0][1] = 1;
        lli ret = 0;
        FOR(k,0,NMAX+1) ret += f(NMAX,NMAX/2,0,k) + f(NMAX,NMAX/2,1,k);
        cout << ret << endl;
    }
    return 0;
}
