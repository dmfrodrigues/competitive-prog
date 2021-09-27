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

struct quadruple {
    long a, b, c, k;
};

int main(){
    ifstream fin("ratios.in");
    ofstream fout("ratios.out");

    ///INPUT
    long y1, y2, y3; fin >> y1 >> y2 >> y3;
    long a1, a2, a3; fin >> a1 >> a2 >> a3;
    long b1, b2, b3; fin >> b1 >> b2 >> b3;
    long c1, c2, c3; fin >> c1 >> c2 >> c3;

    ///PROCESSING
    quadruple sol = {-1, -1, -1, -1};
    FOR(a,0,8634){
        FOR(b,0,8634){
            long k_up = a*(a1*c2 - a2*c1) + b*(b1*c2 - b2*c1);
            if(k_up == 0) continue;
            long k_do = y1*c2 - y2*c1;
            if(k_up % k_do != 0) continue;
            long k = k_up/k_do;
            long c_up = k*y1 - a*a1 - b*b1;
            if(c_up % c1 != 0) continue;
            long c = c_up/c1;

            if(a*a1 + b*b1 + c*c1 != k*y1) continue;
            if(a*a2 + b*b2 + c*c2 != k*y2) continue;
            if(a*a3 + b*b3 + c*c3 != k*y3) continue;

            if(sol.k == -1 || sol.k > k) sol = {a, b, c, k};
        }
    }

    ///OUTPUT
    if(sol.k == -1) fout << "none" << endl;
    else fout << sol.a << " " << sol.b << " " << sol.c << " " << sol.k << endl;

    return 0;
}
