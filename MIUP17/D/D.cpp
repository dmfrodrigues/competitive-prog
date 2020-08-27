#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < lli(e); ++(i))
typedef vector<lli> VI;
typedef deque<lli> DI;
#define CMAX 30000

DI sieve(const ulli &N){
    vector<bool> isprime(N+1, true);
	isprime[0] = isprime[1] = false;
	for(ulli i = 2; i*i<=N; ++i) if(isprime[i])
		for(ulli j = i*i; j <= N; j += i) isprime[j] = false;
	DI primes; FOR(i,0,N+1) if(isprime[i]) primes.push_back(i);
	return primes;
}

int main(){
    /// INPUT
    lli x0, x1, x2, x3; cin >> x0 >> x1 >> x2 >> x3;
    /// PROCESSING
    lli XMAX = max(x0, max(x1, max(x2, x3)));
    DI primes = sieve(CMAX);
    primes.pop_back(); primes.pop_back(); // pop 2 and 3
    for(const lli &c:primes){
        if(XMAX >= c) continue;
        FOR(a, 1, c){
            lli b = x1-a*x0;
            b = (b%c+c)%c;
            if(x1%c == (a*x0+b)%c &&
               x2%c == (a*x1+b)%c &&
               x3%c == (a*x2+b)%c){
                cout << (a*x3+b)%c << endl;
                return 0;
            }
        }
    }
    return 0;
}
