/*
ID: dmfrodr1
TASK: ratios
LANG: C++11
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

template<class T>
using matrix = vector<vector<T>>;

lli gcd(lli a, lli b){
    if(b) return gcd(b, a%b); else return a;
}
void divbygcd(lli& a, lli& b) {
	lli g=gcd(a,b); a/=g; b/=g;
}
lli lcm(lli a, lli b){
    return (a*b)/gcd(a, b);
}

struct fraction {
    lli num, div;

    void fix_negative_div(){
        if(div < 0){
            div = -div;
            num = -num;
        }
    }

    fraction():fraction(0){}
    fraction(lli num_):fraction(num_, 1){}
    fraction(lli num_, lli div_):num(num_), div(div_){
        fix_negative_div();
    }
    void reduce(){
        divbygcd(num, div);
    }
    void mult(lli l){
        num *= l;
        div *= l;
    }
    fraction operator*(const fraction &f) const {
        return fraction(num * f.num, div * f.div);
    }
    fraction operator/(const fraction &f) const {
        return fraction(num * f.div, div * f.num);
    }
    fraction& operator*=(const fraction &f){
        num *= f.num;
        div *= f.div;
        return *this;
    }
    fraction& operator/=(const fraction &f){
        num *= f.div;
        div *= f.num;
        fix_negative_div();
        return *this;
    }
    fraction operator-(const fraction &f) const {
        fraction f1 = *this; f1.reduce();
        fraction f2 = f; f2.reduce();
        lli l = lcm(f1.div, f2.div);
        return fraction(f1.num*l/f1.div - f2.num*l/f2.div, l);
    }
    fraction& operator-=(const fraction &f){
        return (*this = *this - f);
    }
};

istream& operator>>(istream &is, fraction &f){
    lli n; is >> n;
    f = fraction(n);
    return is;
}

/*
ostream& operator<<(ostream &os, fraction &f){
    return os << f.num << "/" << f.div;
}
*/

template<class T> matrix<T> gauss_elimination(matrix<T> A, matrix<T> y){
    const size_t N = A.size();
    FOR(i,0,N){
        y[i][0] /= A[i][i];                                 // Divide yi by Aii
        for(lli j = N-1; j >= i; --j) A[i][j] /= A[i][i];   // Divide values to right of Aii by Aii
        FOR(i_, i+1, N){                                    // Zero out values below Aii
            y[i_][0] -= y[i][0] * A[i_][i];
            for(lli j = N-1; j >= i; --j) A[i_][j] -= A[i][j] * A[i_][i];
        }
    }
    for(lli i = N-1; i >= 0; --i) FOR(i_,0,i){              // Zero out values above Aii
        y[i_][0] -= A[i_][i] * y[i][0];
        A[i_][i] -= A[i_][i] * A[i][i];
    }
    return y;
}

int main(){
    ifstream fin("ratios.in");
    ofstream fout("ratios.out");

    ///INPUT
    matrix<fraction> A(3, vector<fraction>(3, 0));
    matrix<fraction> y(3, vector<fraction>(1, 0));
    fin >> y[0][0] >> y[1][0] >> y[2][0];
    fin >> A[0][0] >> A[1][0] >> A[2][0];
    fin >> A[0][1] >> A[1][1] >> A[2][1];
    fin >> A[0][2] >> A[1][2] >> A[2][2];

    ///PROCESSING
    matrix<fraction> x = gauss_elimination(A, y);

    FOR(i,0,3) x[i][0].reduce();
    lli k = lcm(lcm(x[0][0].div, x[1][0].div), x[2][0].div);
    lli a = x[0][0].num * (k/x[0][0].div);
    lli b = x[1][0].num * (k/x[1][0].div);
    lli c = x[2][0].num * (k/x[2][0].div);

    ///OUTPUT
    if(k <= 0 || a < 0 || b < 0 || c < 0) fout << "NONE" << endl;
    else fout << a << " " << b << " " << c << " " << k << endl;

    return 0;
}
