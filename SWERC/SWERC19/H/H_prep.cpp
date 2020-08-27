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

template<class FCN>
PII tortoise_hare(lli x0, FCN f){
    lli tortoise = f(x0), hare = f(f(x0)); while(tortoise != hare){ tortoise = f(tortoise); hare = f(f(hare)); }
    lli mu  = 0; tortoise = x0;            while(tortoise != hare){ tortoise = f(tortoise); hare = f(hare); ++mu ; }
    lli lam = 1; hare     = f(tortoise);   while(tortoise != hare){                         hare = f(hare); ++lam; }
    return PII(mu, lam);
}

const lli M = 1L<<40;
const lli x0 = 0x600DCAFE;
lli f(lli x){
    return (x+(x>>20)+12345)%M;
}

int main(){
    PII ret = tortoise_hare(x0, f);
    lli mu  = ret.first;
    lli lam = ret.second;
    cout << "const lli mu  = " << mu  << ";\n";
    cout << "const lli lam = " << lam << ";\n";

    lli step = 3000000;

    cout << "const lli step = " << step << ";\n";

    VI mu_sol (mu /step + (mu %step ? 1 : 0), 0); VI mu_v ( mu_sol.size(), 0);
    VI lam_sol(lam/step + (lam%step ? 1 : 0), 0); VI lam_v(lam_sol.size(), 0);

    lli x = x0;
    FOR(i,0,mu){
        if(x%2 == 0) ++mu_sol[i/step];
        if(i%step == 0) mu_v[i/step] = x;
        x = f(x);
    }
    FOR(i,0,lam){
        if(x%2 == 0) ++lam_sol[i/step];
        if(i%step == 0) lam_v[i/step] = x;
        x = f(x);
    }
    cout << "const VI mu_sol  = {"; cout << mu_sol [0]; FOR(i,1,mu_sol .size()) cout << ", " << mu_sol [i]; cout << "}; //size=" << mu_sol .size() << "\n";
    cout << "const VI lam_sol = {"; cout << lam_sol[0]; FOR(i,1,lam_sol.size()) cout << ", " << lam_sol[i]; cout << "}; //size=" << lam_sol.size() << "\n";
    cout << "const VI mu_v    = {"; cout << mu_v   [0]; FOR(i,1,mu_v   .size()) cout << ", " << mu_v   [i]; cout << "}; //size=" << mu_v   .size() << "\n";
    cout << "const VI lam_v   = {"; cout << lam_v  [0]; FOR(i,1,lam_v  .size()) cout << ", " << lam_v  [i]; cout << "}; //size=" << lam_v  .size() << "\n";
    return 0;
}
