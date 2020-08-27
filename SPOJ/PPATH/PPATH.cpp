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
VI sieve(vector<bool>& isprime){
	auto N = isprime.size()-1;
	fill(ALL(isprime), true); isprime[0] = isprime[1] = false;
	for(ulli i = 2; i*i<=N; ++i) if(isprime[i])
		for(ulli j = i*i; j <= N; j += i) isprime[j] = false;
	VI primes; FOR(i,0,N+1) if(isprime[i]) primes.push_back(i);
	return primes;
}
int main(){
    deque<lli> d;{
        vector<bool> isprime(10000);
        VI primes = sieve(isprime);
        d = deque<lli>(ALL(primes));
        while(!d.empty() && d.front() < 1000) d.pop_front();
    }
    vector<string> v(d.size());{
        for(size_t i = 0; i < v.size(); ++i){
            v[i] = to_string(v)
        }
    }
    return 0;
}