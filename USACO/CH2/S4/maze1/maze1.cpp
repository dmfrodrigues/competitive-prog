/*
ID: dmfrodr1
TASK: maze1
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,b,e) for(int (i) = (b); (i) < int(e); ++(i))

typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<int> VI;
typedef vector<VI> VVI;

const int INF = 1000000;

struct pos_t: public pair<int,int> {
    pos_t():pair<int,int>(){}
    pos_t(int a, int b):pair<int,int>(a,b){}
    pos_t operator+(const pos_t &pos){
        return pos_t(this->first + pos.first, this->second + pos.second);
    }
};

int W, H;

bool is_inside(const pos_t &pos){
    return (0 <= pos.first  && pos.first  < H &&
            0 <= pos.second && pos.second < W);
}

VVB occupied;
set<pos_t> exits;

VVI bfs(const pos_t &pos){
    VVI dist(H, VI(W, INF));
    queue<pos_t> Q;
    dist[pos.first][pos.second] = 0; Q.push(pos);
    while(!Q.empty()){
        pos_t p = Q.front(); Q.pop();
        pos_t q; int d = dist[p.first][p.second]+1;
        q = pos_t(p.first, p.second+1); if(is_inside(q) && !occupied[p.first][p.second] && d < dist[q.first][q.second]){ dist[q.first][q.second] = d; Q.push(q); }
        q = pos_t(p.first, p.second-1); if(is_inside(q) && !occupied[p.first][p.second] && d < dist[q.first][q.second]){ dist[q.first][q.second] = d; Q.push(q); }
        q = pos_t(p.first+1, p.second); if(is_inside(q) && !occupied[p.first][p.second] && d < dist[q.first][q.second]){ dist[q.first][q.second] = d; Q.push(q); }
        q = pos_t(p.first-1, p.second); if(is_inside(q) && !occupied[p.first][p.second] && d < dist[q.first][q.second]){ dist[q.first][q.second] = d; Q.push(q); }
    }
    return dist;
}

int main(){
    // INPUT FILES
    ifstream fin("maze1.in");
    ofstream fout("maze1.out");
    // INPUT
    fin >> W >> H;
    W = 2*W+1;
    H = 2*H+1;
    occupied = VVB(H, VB(W));

    string s; getline(fin, s);
    FOR(i,0,H){
        getline(fin, s);
        FOR(j,0,W){
            occupied[i][j] = (s[j] != ' ');
            bool is_frontier = (i == 0 || i == H-1 ||
                                j == 0 || j == W-1);
            if(!occupied[i][j] && is_frontier) exits.insert(pos_t(i, j));
        }
    }
    // PROCESSING
    VVI dist_min(H, VI(W, INF));
    for(const pos_t &pos: exits){
        VVI dist = bfs(pos);
        FOR(i,0,H) FOR(j,0,W){
            dist_min[i][j] = min(dist_min[i][j], dist[i][j]);
        }
    }
    // OUTPUT
    int ans = 0;
    for(int i = 1; i < H; i += 2) for(int j = 1; j < W; j += 2){
        ans = max(ans, dist_min[i][j]);
    }
    ans = (ans+1)/2;
    fout << ans << endl;

    return 0;
}
