#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<lli,lli> PII;
typedef vector<lli> VI;
typedef vector<VI> VVI;
#define ALL(v) (v).begin(), (v).end()
#define FOR(i,b,e) for(lli (i) = (b); (i) < (e); ++(i))

int dist(const PII &p1, const PII &p2){ return abs(p1.first-p2.first)+abs(p1.second-p2.second); }

lli hungarian(const VVI &costs){ // costs[courier][bottle] == costs[row][col]
    const int nx = costs.size(), ny = costs[0].size();
    VI xy(nx, -1), yx(ny, -1), lx(nx), ly(ny, 0), augmenting(ny);
    vector<bool> s(nx); vector<PII> slack(ny, PII(0, 0));
    FOR(x,0,nx) lx[x] = *max_element(ALL(costs[x]));
    FOR(root, 0, nx){
        fill(ALL(augmenting), -1); fill(ALL(s), false); s[root] = true;
        FOR(y,0,ny) slack[y] = PII(lx[root] + ly[y] - costs[root][y], root);
        int y = -1;
        while(true){
            lli delta = INT_MAX; int x = -1;
            FOR(yy,0,ny)
                if (augmenting[yy] == -1)
                    if (slack[yy].first < delta) {
                        delta = slack[yy].first;
                        x = slack[yy].second;
                        y = yy;
                    }
            assert(s[x]);
            if (delta > 0) {
                FOR(x,0,nx) if(s[x]) lx[x] -= delta;
                FOR(y,0,ny) if(augmenting[y] > -1) ly[y] += delta; else slack[y].first -= delta;
            }
            assert(lx[x] + ly[y] == costs[x][y]);
            augmenting[y] = x; x = yx[y];
            if (x == -1) break;
            s[x] = true;
            FOR(y,0,ny)
                if (augmenting[y] == -1) {
                    PII alt(lx[x] + ly[y] - costs[x][y], x);
                    if (slack[y].first > alt.first) slack[y] = alt;
                }
        }
        while (y > -1) {
            int x = augmenting[y], prec = xy[x];
            yx[y] = x; xy[x] = y; y = prec;
        }
    }
    return accumulate(ALL(lx), 0) + accumulate(ALL(ly), 0);
}

int main() {
    ///INPUT
    size_t M;
    size_t N;
    cin >> N >> M;
    vector<PII> bottles(N);
    for(PII &p:bottles ) cin >> p.first >> p.second;
    vector<PII> couriers(M);
    for(PII &p:couriers) cin >> p.first >> p.second;
    PII restaurant;
    cin >> restaurant.first >> restaurant.second;
    ///PROCESSING
    // preparation

    int nx = bottles.size();
    int ny = bottles.size()+couriers.size()-1;
    FOR(c,couriers.size(), ny) couriers.push_back(restaurant);
    VVI costs(nx, VI(ny));
    FOR(x,0,nx){
        FOR(y,0,ny){
            int cost = dist(couriers[y], bottles[x]) + dist(bottles[x], restaurant);
            costs[x][y] = -cost;
        }
    }
    cout << -hungarian(costs) << endl;
}
