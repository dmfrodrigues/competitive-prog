/*
ID: dmfrodr1
TASK: frac1
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,b,e) for(int (i) = (b); (i) < (e); ++(i))

int gcd(int a, int b){
    if(b) return gcd(b, a%b); else return a;
}

struct Fraction{
    int n, d;
    Fraction(int n_, int d_){
        int g = gcd(n_, d_);
        n = n_/g;
        d = d_/g;
    }
    bool operator<(const Fraction &obj) const{
        return (n*obj.d < obj.n*d);
    }
};

int main(){
    ///INPUT
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");
    int N; fin >> N;
    ///PROCESSING
    set<Fraction> s;
    for(int d = 1; d <= N; ++d){
        for(int n = 0; n <= d; ++n){
            s.insert(Fraction(n, d));
        }
    }
    for(const Fraction &f:s){
        fout << f.n << "/" << f.d << endl;
    }
    return 0;
}
