#include <bits/stdc++.h>
#define NMAX 50000

using namespace std;

deque<long> primes;

void buildPrimes(){
    bool isprime[NMAX];
    fill(isprime,isprime+NMAX, true);
    for(long i = 2; i < NMAX; ++i){
        if(isprime[i]){
            primes.push_back(i);
            for(long j = i*i; j < NMAX; j += i){
                isprime[j] = false;
            }
        }
    }
}

bool isprime(long n){
    for(const long& p:primes){
        if(p > n) break;
        if(n != p && n%p == 0){
            return false;
        }
    }
    return true;
}

void primesBetween(long m, long n){
    for(long p = max(m,2L); p <= n; ++p){
        if(isprime(p)){
            cout << p << "\n";
        }
    }
}

int main(){
    buildPrimes();
    long t; cin >> t;
    for(long i = 0; i < t; ++i){
        long m, n; cin >> m >> n;
        primesBetween(m, n);
        if(i != t-1) cout << endl;
    }
    return 0;
}
