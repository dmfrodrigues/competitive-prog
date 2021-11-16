/*
ID: dmfrodr1
TASK: pprime
LANG: C++11
*/
#include <bits/stdc++.h>
#define PMAX 10005
using namespace std;

deque<long> primes;
void start_primes(){
    bool is_prime[PMAX];
    fill(is_prime, is_prime+PMAX, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for(long i = 2; i < PMAX; ++i){
        if(is_prime[i]){
            for(long j = i*i; j < PMAX; j += i) is_prime[j] = false;
            primes.push_back(i);
        }
    }
}
bool is_prime(long n){
    if(n < 2) return false;
    for(const long &p:primes){
        if(p >= n) break;
        if(n%p == 0) return false;
    }
    return true;
}

long my_pow(long b, long a){
    long ret = 1L;
    while(a--){
        ret *= b;
    }
    return ret;
}
deque<long> create_pal(){
    deque<long> ret;
    for(long sz = 1; sz <= 8; ++sz){
        long sz_ = sz/2 + sz%2;
        long l = my_pow(10L, sz_-1);
        long r = my_pow(10L, sz_  );
        for(long i = l; i < r; ++i){
            string s1;{
                stringstream ss;
                ss << i;
                ss >> s1;
            }
            string s2;{
                if(sz%2 == 0) s2 = s1;
                else          s2 = s1.substr(0, s1.size()-1);
                reverse(s2.begin(), s2.end());
            }
            string s = s1+s2;

            long ins;{
                stringstream ss;
                ss << s;
                ss >> ins;
            }
            ret.push_back(ins);
        }
    }
    return ret;
}

int main(){
    ///INPUT
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");
    long a, b; fin >> a >> b;
    deque<long> pal = create_pal();
    start_primes();
    for(const long &i:pal){
        if(is_prime(i) && a <= i && i <= b) fout << i << endl;
    }

    return 0;
}
