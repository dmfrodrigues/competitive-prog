#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i) = (b) ; (i) < lli (e) ; (i)++ )

const vector<lli> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43, 47};

lli f2(lli N, lli i, lli X, lli K){
    if(i >= (lli)primes.size()) return 1;
    lli p = primes[i];
    lli ret = 1;
    for(lli k = 0; k <= K && N <= X; ++k, N *= p){
        ret = max(ret, (k+1)*f2(N, i+1, X, k));
    }
    return ret;
}

int main(){
    lli X; cin >> X;
    cout << f2(1, 0, X, 50) << endl;
    return 0;
}
