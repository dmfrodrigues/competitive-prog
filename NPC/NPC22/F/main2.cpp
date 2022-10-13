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
};

VVI bfs(const VVB &map, const Point &p, const string &instructions){
    const size_t &H = map.size();
    const size_t &W = map[0].size();

    VVI dist(H, VI(W, INF));
    
    queue<Point> q;

    dist[p.h][p.w] = 0;
    q.push(p);

    while(!q.empty()){
        const Point &u = q.front(); q.pop();
        int uDist = dist[u.h][u.w];
        if(uDist >= (lli)instructions.size()) return dist;
        char instruction = instructions[uDist];
        Point v;
        int vDist = uDist+1;
        char dir;
        dir = 'W'; v = Point{u.h  , u.w-1}; if(dir != instruction && map[v.h][v.w] && dist[v.h][v.w] == INF){ dist[v.h][v.w] = vDist; q.push(v); }
        dir = 'E'; v = Point{u.h  , u.w+1}; if(dir != instruction && map[v.h][v.w] && dist[v.h][v.w] == INF){ dist[v.h][v.w] = vDist; q.push(v); }
        dir = 'N'; v = Point{u.h-1, u.w  }; if(dir != instruction && map[v.h][v.w] && dist[v.h][v.w] == INF){ dist[v.h][v.w] = vDist; q.push(v); }
        dir = 'S'; v = Point{u.h+1, u.w  }; if(dir != instruction && map[v.h][v.w] && dist[v.h][v.w] == INF){ dist[v.h][v.w] = vDist; q.push(v); }
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

    VVI dist = bfs(map, start, instructions);
    // FOR(h,0,H){
    //     FOR(w,0,W){
    //         if(dist[h][w] == INF) cout << "-";
    //         else cout << dist[h][w];
    //     }
    //     cout << "\n";
    // }

    FOR(h,0,H){
        FOR(w,0,W){
            if(!map[h][w]) cout << "#";
            else if(h == start.h && w == start.w) cout << "S";
            else cout << (dist[h][w] == (lli)instructions.size() ? "!" : ".");
        }
        cout << "\n";
    }

    return 0;
}
