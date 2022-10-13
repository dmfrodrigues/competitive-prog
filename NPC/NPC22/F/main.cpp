#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(int i =(b); (i)  < (int)(e); ++(i))
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

const lli WMAX = 1000;

struct Point{
    int h, w;

    bool operator==(const Point &p) const {
        return h == p.h && w == p.w;
    }
};

namespace std{
    template<> struct hash<Point>{
        size_t operator()(const Point &v) const{
            return v.h * (WMAX+1) + v.w;
        }
    };
}

VVI bfs(const VVB &map, const Point &p){
    const size_t &H = map.size();
    const size_t &W = map[0].size();

    VVI dist(H, VI(W, INF));
    
    queue<Point> q;

    dist[p.h][p.w] = 0;
    q.push(p);

    while(!q.empty()){
        const Point &u = q.front(); q.pop();
        Point v;
        int vDist = dist[u.h][u.w]+1;
        v = Point{u.h  , u.w-1}; if(map[v.h][v.w] && dist[v.h][v.w] > vDist){ dist[v.h][v.w] = vDist; q.push(v); }
        v = Point{u.h  , u.w+1}; if(map[v.h][v.w] && dist[v.h][v.w] > vDist){ dist[v.h][v.w] = vDist; q.push(v); }
        v = Point{u.h-1, u.w  }; if(map[v.h][v.w] && dist[v.h][v.w] > vDist){ dist[v.h][v.w] = vDist; q.push(v); }
        v = Point{u.h+1, u.w  }; if(map[v.h][v.w] && dist[v.h][v.w] > vDist){ dist[v.h][v.w] = vDist; q.push(v); }
    }

    return dist;
}

int main(){
    int W, H; cin >> W >> H;
    VVB map(H, VB(W, false));
    Point start;
    FOR(h,0,H){
        string line; cin >> line;
        FOR(w,0,W){
            if(line[w] == 'S') start = Point{h, w};
            map[h][w] = (line[w] == '#' ? false : true);
        }
    }

    string instructions; cin >> instructions;
    unordered_set<Point> prevPositions;
    prevPositions.insert(start);
    FOR(i,0,instructions.size()){
        const char &instruction = instructions[i];
        unordered_set<Point> positions;
        for(const Point &u: prevPositions){
            char dir; int h, w;
            dir = 'W'; h = u.h  ; w = u.w-1; if(map[h][w] && dir != instruction) positions.insert(Point{h, w});
            dir = 'E'; h = u.h  ; w = u.w+1; if(map[h][w] && dir != instruction) positions.insert(Point{h, w});
            dir = 'N'; h = u.h-1; w = u.w  ; if(map[h][w] && dir != instruction) positions.insert(Point{h, w});
            dir = 'S'; h = u.h+1; w = u.w  ; if(map[h][w] && dir != instruction) positions.insert(Point{h, w});
        }
        prevPositions = positions;
    }

    VVI dist = bfs(map, start);

    VVB solutions(H, VB(W, false));
    for(const Point &p: prevPositions){
        if(dist[p.h][p.w] == (lli)instructions.size())
            solutions[p.h][p.w] = true;
    }

    FOR(h,0,H){
        FOR(w,0,W){
            if(!map[h][w]) cout << "#";
            else if(h == start.h && w == start.w) cout << "S";
            else cout << (solutions[h][w] ? "!" : ".");
        }
        cout << "\n";
    }

    return 0;
}
