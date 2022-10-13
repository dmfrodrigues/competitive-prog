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

struct Position {
    int h, w;
    bool operator<(const Position &p) const {
        if(h != p.h) return h < p.h;
        else return w < p.w;
    }
    bool operator==(const Position &p) const {
        return h == p.h && w == p.w;
    }
};

struct Army {
    int size;
    Position pos;
    Position initialPos;
    bool operator<(const Army &a) const {
        if(size != a.size) return size > a.size;
        else return pos < a.pos;
    }
};

int main(){
    int W, H; cin >> W >> H;
    map<Position, Army> island;
    set<Army> armies;
    FOR(h,0,H){
        FOR(w,0,W){
            int s; cin >> s;
            Position p{(int)h, (int)w};
            Army a{s, p, p};
            island[p] = a;
            armies.insert(a);
        }
    }


    while(armies.size() > 1){
        // Get largest army
        Army largestArmy = *armies.begin();
        
        // Get weakest neighbor
        Army weakestNeighbor{INF, Position{0,0}, Position{0,0}};
        Position p_;
        p_ = Position{largestArmy.pos.h-1, largestArmy.pos.w  }; if(p_.h >= 0 && island[p_].size > 0 && island[p_].size < weakestNeighbor.size){ weakestNeighbor = island[p_]; }
        p_ = Position{largestArmy.pos.h  , largestArmy.pos.w-1}; if(p_.w >= 0 && island[p_].size > 0 && island[p_].size < weakestNeighbor.size){ weakestNeighbor = island[p_]; }
        p_ = Position{largestArmy.pos.h  , largestArmy.pos.w+1}; if(p_.w <  W && island[p_].size > 0 && island[p_].size < weakestNeighbor.size){ weakestNeighbor = island[p_]; }
        p_ = Position{largestArmy.pos.h+1, largestArmy.pos.w  }; if(p_.h <  H && island[p_].size > 0 && island[p_].size < weakestNeighbor.size){ weakestNeighbor = island[p_]; }

        if(weakestNeighbor.size == INF){
            // Deserts due to boredom
            armies.erase(largestArmy);
            largestArmy.size--;
            if(largestArmy.size > 0) armies.insert(largestArmy);
            island[largestArmy.pos] = largestArmy;
        } else {
            // Attack!
            armies.erase(largestArmy);
            armies.erase(weakestNeighbor);

            island[largestArmy.pos] = Army{
                0,
                largestArmy.pos,
                largestArmy.pos
            };

            largestArmy.size -= weakestNeighbor.size;
            largestArmy.pos = weakestNeighbor.pos;
            island[largestArmy.pos] = largestArmy;

            if(largestArmy.size > 0) armies.insert(largestArmy);
        }
    }
    if(armies.empty()) {
        cout << "none wins" << endl;
    } else {
        Army largestArmy = *armies.begin();
        cout << largestArmy.initialPos.h << " " << largestArmy.initialPos.w << " " << largestArmy.size << endl;
    }
    return 0;
}
