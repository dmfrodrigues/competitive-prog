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

double XMIN = -10, XMAX = 20;
double YMIN = -10, YMAX = 20;

struct Point{
    double x, y;
};

lli ATTEMPTS = 10000000;

double rand_range(double a, double b){
    double r = double(rand())/double(RAND_MAX);
    return a + (b-a)*r;
}

double dist2(const Point &a, const Point &b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx*dx + dy*dy;
}

int main(){
    int N; cin >> N;
    vector<pair<Point, double>> v(N);
    Point p; double r;
    FOR(n,0,N){
        cin >> p.x >> p.y >> r;
        v[n] = make_pair(p, r);
    }
    lli inside = 0;
    FOR(i,0,ATTEMPTS){
        Point a{
            rand_range(XMIN, XMAX),
            rand_range(YMIN, YMAX)
        };
        FOR(n,0,N){
            const Point &b = v[n].first;
            const double &r = v[n].second;
            if(dist2(a, b) < r*r){
                ++inside;
                break;
            }
        }
    }

    double areaDestroyed = (XMAX-XMIN)*(YMAX-YMIN) * double(inside) / double(ATTEMPTS);
    cout << fixed << setprecision(10) << areaDestroyed << endl;

    return 0;
}
