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

const double epsilon = 0.00001;

int main(){
    int C; cin >> C;
    FOR(i,0,C){
        double l1, l2, H; cin >> l1 >> l2 >> H;
        if(l1 < l2) swap(l1, l2);

        double a = 0, b = l2;
        while(b-a > epsilon){
            double w = a + (b-a)/double(2.0);
            double alpha = acos(w/l1);
            double beta  = acos(w/l2);
            double w2 = w*tan(alpha)/(tan(alpha)+tan(beta));
            double h = w2 * tan(beta);
            if(h > H) a = w;
            else      b = w;
        }

        cout << fixed << setprecision(4) << a + (b-a)/2 << endl;
    }

    return 0;
}
