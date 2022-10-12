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
};
struct Army {
    Position initialPosition;
    int size;
};

int main(){
    int W, H; cin >> W >> H;
    vector<vector<Army>> armies(H, vector<Army>(W));
    FOR(h,0,H){
        FOR(w,0,W){
            int s; cin >> s;
            armies[h][w] = Army{Position{(int)h, (int)w}, s};
        }
    }

    while(true){
        // Get largest army
        Army largestArmy{Position{0,0}, 0};
        Position largestArmyPos;
        int numberArmies = 0;
        FOR(h,0,H){
            FOR(w,0,W){
                if(armies[h][w].size > 0)
                    ++numberArmies;

                if(armies[h][w].size > largestArmy.size){
                    largestArmy = armies[h][w];
                    largestArmyPos = Position{(int)h, (int)w};
                }
            }
        }
        if(largestArmy.size == 0){
            cout << "none wins" << endl;
            return 0;
        }
        if(numberArmies == 1){
            cout
                << largestArmy.initialPosition.h << " "
                << largestArmy.initialPosition.w << " "
                << largestArmy.size
                << endl;
            return 0;
        }

        // Get weakest neighbor
        Army weakestNeighbor{Position{0,0}, INF};
        Position weakestNeighborPos;
        if(largestArmyPos.h-1 >= 0 && armies[largestArmyPos.h-1][largestArmyPos.w  ].size > 0 && armies[largestArmyPos.h-1][largestArmyPos.w  ].size < weakestNeighbor.size){ weakestNeighbor = armies[largestArmyPos.h-1][largestArmyPos.w  ]; weakestNeighborPos = Position{largestArmyPos.h-1, largestArmyPos.w  }; }
        if(largestArmyPos.w-1 >= 0 && armies[largestArmyPos.h  ][largestArmyPos.w-1].size > 0 && armies[largestArmyPos.h  ][largestArmyPos.w-1].size < weakestNeighbor.size){ weakestNeighbor = armies[largestArmyPos.h  ][largestArmyPos.w-1]; weakestNeighborPos = Position{largestArmyPos.h  , largestArmyPos.w-1}; }
        if(largestArmyPos.w+1 <  W && armies[largestArmyPos.h  ][largestArmyPos.w+1].size > 0 && armies[largestArmyPos.h  ][largestArmyPos.w+1].size < weakestNeighbor.size){ weakestNeighbor = armies[largestArmyPos.h  ][largestArmyPos.w+1]; weakestNeighborPos = Position{largestArmyPos.h  , largestArmyPos.w+1}; }
        if(largestArmyPos.h+1 <  H && armies[largestArmyPos.h+1][largestArmyPos.w  ].size > 0 && armies[largestArmyPos.h+1][largestArmyPos.w  ].size < weakestNeighbor.size){ weakestNeighbor = armies[largestArmyPos.h+1][largestArmyPos.w  ]; weakestNeighborPos = Position{largestArmyPos.h+1, largestArmyPos.w  }; }

        if(weakestNeighbor.size == INF){
            // Deserts due to boredom
            armies[largestArmyPos.h][largestArmyPos.w].size = 0;
        } else {
            // Attack!
            largestArmy.size -= weakestNeighbor.size;
            armies[weakestNeighborPos.h][weakestNeighborPos.w] = largestArmy;
            armies[largestArmyPos.h][largestArmyPos.w] = Army{Position{0,0},0};
        }
    }
}
