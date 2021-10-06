#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
//#define REP(i, b, e)            for(auto i =(b); (i) != (e); ++(i))
typedef vector<lli>             VI;
typedef pair< lli, lli>         PII;
#define X first
#define Y second

void PRINT(const VI& v){
    FOR(i,0,v.size()){
        cout << v[i] << " ";
    } cout << endl;
}

PII solve(lli Q, const vector<PII>& p, const vector<char>& d){
    VI GoingW_x(Q, 0);
    VI GoingE_x(Q, 0);
    VI GoingN_y(Q, 0);
    VI GoingS_y(Q, 0);
    FOR(i,0,p.size()){
        switch(d[i]){
            case 'W': ++GoingW_x[p[i].X]; break;
            case 'E': ++GoingE_x[p[i].X]; break;
            case 'N': ++GoingN_y[p[i].Y]; break;
            case 'S': ++GoingS_y[p[i].Y]; break;
        }
    }
    /*
    PRINT(GoingW_x);
    PRINT(GoingE_x);
    PRINT(GoingN_y);
    PRINT(GoingS_y);
    cout << endl;
    */

    VI ComingfromW_x(Q, 0); for(lli x = Q-2; x >= 0; --x) ComingfromW_x[x] = ComingfromW_x[x+1] + GoingW_x[x+1];
    VI ComingfromE_x(Q, 0); for(lli x =   1; x <  Q; ++x) ComingfromE_x[x] = ComingfromE_x[x-1] + GoingE_x[x-1];
    VI ComingfromS_y(Q, 0); for(lli y = Q-2; y >= 0; --y) ComingfromS_y[y] = ComingfromS_y[y+1] + GoingS_y[y+1];
    VI ComingfromN_y(Q, 0); for(lli y =   1; y <  Q; ++y) ComingfromN_y[y] = ComingfromN_y[y-1] + GoingN_y[y-1];

    /*
    PRINT(ComingfromW_x);
    PRINT(ComingfromE_x);
    PRINT(ComingfromN_y);
    PRINT(ComingfromS_y);
    cout << endl;
    */
    VI ComingfromWE_x(Q,0); for(lli x = 0; x < Q; ++x) ComingfromWE_x[x] = ComingfromW_x[x] + ComingfromE_x[x];
    VI ComingfromNS_y(Q,0); for(lli y = 0; y < Q; ++y) ComingfromNS_y[y] = ComingfromN_y[y] + ComingfromS_y[y];

    lli x = max_element(ALL(ComingfromWE_x)) - ComingfromWE_x.begin();
    lli y = max_element(ALL(ComingfromNS_y)) - ComingfromNS_y.begin();

    return PII(x,y);
}

int main(){
    int T; cin >> T;
    FOR(t,0,T){
        int P, Q; cin >> P >> Q; ++Q;
        vector<PII> p(P);
        vector<char> d(P);
        FOR(i,0,P) cin >> p[i].first >> p[i].second >> d[i];
        PII ans = solve(Q, p, d);
        printf("Case #%Ld: %Ld %Ld\n", t+1, ans.X, ans.Y);
    }
    return 0;
}
