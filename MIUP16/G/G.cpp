#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e)  for(lli (i) = (b); (i) < lli(e); ++(i))
#define ALL(v)      (v).begin(), (v).end()
typedef vector<lli> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;

void drop(VVVI &w, lli h, lli x, lli y){
    if(h <= 0) return;
    lli m = max(w[h-1][x][y], max(w[h-1][x+1][y], w[h-1][x][y+1]));
    w[h][x][y] = m;
    if     (m == w[h-1][x  ][y  ]){ w[h-1][x  ][y  ] = 0; drop(w, h-1, x  , y  ); }
    else if(m == w[h-1][x+1][y  ]){ w[h-1][x+1][y  ] = 0; drop(w, h-1, x+1, y  ); }
    else                          { w[h-1][x  ][y+1] = 0; drop(w, h-1, x  , y+1); }
}

int main(){
    lli N; cin >> N;
    VVVI w(N);
    for(lli h = N-1; h >= 0; --h){
        w[h] = VVI(N-h);
        for(lli x = N-h-1; x >= 0; --x){
            w[h][x] = VI(N-h-x);
            for(lli y = N-h-x-1; y >= 0; --y)
                cin >> w[h][x][y];
        }
    }
    //cout << w[N-1][0][0] << endl;
    while(w[N-1][0][0]){
        cout << w[N-1][0][0] << endl;
        w[N-1][0][0] = 0;
        drop(w, N-1, 0, 0);
    }
    return 0;
}
