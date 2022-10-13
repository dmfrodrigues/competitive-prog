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

double x1A, y1A, x2A, y2A;
double x1M, y1M, x2M, y2M;

int main(){
    cin >> x1M >> y1M >> x1A >> y1A;
    cin >> x2M >> y2M >> x2A >> y2A;

    double dx1 = x1M-x1A;
    double dy1 = y1M-y1A;
    double d1 = sqrt(dx1*dx1 + dy1*dy1);

    double dx2 = x2M-x2A;
    double dy2 = y2M-y2A;
    double d2 = sqrt(dx2*dx2 + dy2*dy2);

    cout << fixed << setprecision(10) << max(d1, d2) << endl;

    return 0;
}
