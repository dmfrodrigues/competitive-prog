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
const lli INF = 100000000;

const lli XMAX = 10000;

struct Point {
    int x, y;

    bool operator==(const Point &p) const {
        return x == p.x && y == p.y;
    }
};

struct compX {
    bool operator()(const Point &a, const Point &b) const {
        if (a.x != b.x) return a.x < b.x;
        else return a.y < b.y;
    }
};

struct compY {
    bool operator()(const Point &a, const Point &b) const {
        if (a.y != b.y) return a.y < b.y;
        else return a.x < b.x;
    }
};

int distance2(const Point &a, const Point &b){
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx*dx + dy*dy;
}

class Neighbors {
    const int delta;
    vector<set<Point, compY>> stripes;
public:
    Neighbors(int delta_): delta(delta_){
        int imax = XMAX / delta;
        stripes = vector<set<Point, compY>>(imax+1);
    }
    void addPoint(const Point &p){
        int i = p.x / delta;
        stripes.at(i).insert(p);
    }
    void removePoint(const Point &p){
        int i = p.x / delta;
        stripes.at(i).erase(p);
    }
    list<Point> nearest(const Point &p, int dist){
        list<Point> ret;
        const int d2 = dist*dist;
        int xmin = p.x - dist;
        int xmax = p.x + dist;
        int imin = max(xmin / delta, 0);
        int imax = min(xmax / delta, (int)stripes.size()-1);
        FOR(i,imin,imax+1){
            auto it1 = stripes.at(i).lower_bound(Point{p.x, p.y - dist});
            auto it2 = stripes.at(i).upper_bound(Point{p.x, p.y + dist});
            for(auto it = it1; it != it2; ++it){
                if(distance2(*it, p) <= d2) ret.push_back(*it);
            }
        }
        return ret;
    }
};

namespace std {
    template<> struct hash<Point>{
        size_t operator()(const Point &p) const {
            return hash<lli>()(p.y*XMAX + p.x);
        }
    };
}

void solve(const list<Point> &points, Neighbors nn, int R, int H){
    unordered_map<Point, int> dist;
    queue<Point> q;
    for(const Point &p: points){
        if(p.y <= R){
            nn.removePoint(p);
            dist[p] = 1;
            q.push(p);
        }
    }
    while(!q.empty()){
        Point u = q.front(); q.pop();
        int uDist = dist.at(u);
        if(u.y+R >= H) { cout << uDist << endl; return; }
        // cout << "L107" << endl;
        const list<Point> &adj = nn.nearest(u, R);
        // cout << "L109" << endl;
        int vDist = uDist + 1;
        for(const Point &v: adj){
            nn.removePoint(v);
            dist[v] = vDist;
            q.push(v);
        }
    }
    cout << "unreachable" << endl;
}

int main(){
    int N, H, C;
    cin >> N >> H >> C;
    
    list<Point> points;
    Neighbors nn(50);

    Point p;
    FOR(n,0,N){
        cin >> p.x >> p.y;
        nn.addPoint(p);
        points.push_back(p);
    }

    FOR(c,0,C){
        int R; cin >> R;
        solve(points, nn, R, H);
    }

    return 0;
}
