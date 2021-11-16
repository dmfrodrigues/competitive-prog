/*
ID: dmfrodr1
TASK: sprime
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

ifstream fin("sprime.in");
ofstream fout("sprime.out");

bool is_prime_fcn(long n){
    if(n%2==0) return false;
    long lim = min(long(sqrt(n)+1), n);
    for(long i = 3; i < lim; i += 2){
        if(n%i == 0) return false;
    }
    return true;
}

void get_sprimes(long N){
    deque<long> prev;
    deque<long> curr({2,3,5,7});
    while(--N){
        prev = curr;
        curr.clear();
        for(const long &n:prev){
            for(long k, i = 0; i <= 9; ++i){
                k = 10L*n+i;
                if(is_prime_fcn(k)){
                    curr.push_back(k);
                }
            }
        }
    }
    for(const long &n:curr) fout << n << endl;
}

int main(){
    ///INPUT
    long N; fin >> N;
    ///PROCESSING
    get_sprimes(N);
    return 0;
}
