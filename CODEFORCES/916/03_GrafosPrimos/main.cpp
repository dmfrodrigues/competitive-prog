/// JAMIE AND INTERESTING GRAPH
/// http://codeforces.com/contest/916/problem/C

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

typedef unsigned long long int PrimeT;

std::vector<PrimeT> PrimeSieve(const PrimeT& PrimeMax){
    std::vector<bool> IsPrime(PrimeMax+1, true);
    std::deque<PrimeT> PrimesDeque;
    IsPrime[0] = IsPrime[1] = false;
    for(PrimeT i = 2; i < IsPrime.size(); ++i){
        if(!IsPrime[i]) continue;
        PrimesDeque.push_back(i);
        for(PrimeT j = 2*i; j < IsPrime.size(); j += i) IsPrime[j] = false;
    }

    std::vector<PrimeT> PrimesVtr(PrimesDeque.begin(), PrimesDeque.end());
    return PrimesVtr;
}

class Edge{
public:
    PrimeT u;
    PrimeT v;
    PrimeT w;
    Edge(const PrimeT& u_, const PrimeT& v_, const PrimeT& w_):u(u_),v(v_),w(w_){}
    Edge(){}
};

void resolver1(const PrimeT& N, const PrimeT& M){
    PrimeT objective = N-1;
    PrimeT PrimeMax = objective + 1e4;
    std::vector<PrimeT> Primes = PrimeSieve(PrimeMax);
    PrimeT Prime_index = std::lower_bound(Primes.begin(), Primes.end(), objective) - Primes.begin();
    PrimeT Prime = Primes[Prime_index];

    PrimeT sp = Prime;
    PrimeT mstw = sp;

    std::cout << sp << " " << mstw << std::endl;

    PrimeT w12 = sp - (N-2);

    std::vector<Edge> EdgesVtr(M);
    EdgesVtr[0] = Edge(1, 2, w12);
    for(PrimeT i = 2; i <= N-1; ++i){
        EdgesVtr[i-1] = Edge(i, i+1, 1);
    }



    PrimeT counter = (N-2)+1;
    for(PrimeT u = 1; u <= N; ++u){
        if(counter >= EdgesVtr.size()) break;
        for(PrimeT v = u+2; v <= N; ++v){
            if(counter >= EdgesVtr.size()) break;
            EdgesVtr[counter++] = Edge(u,v,Prime+1);
        }
    }

    for(std::vector<Edge>::const_iterator i = EdgesVtr.begin(); i < EdgesVtr.end(); ++i){
        std::cout << i->u << " " << i->v << " " << i->w << std::endl;
    }


}

int main(){
    PrimeT n, m;
    std::cin >> n >> m;
    resolver1(n, m);
    return 0;
}
