#include <bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(), (v).end()
typedef vector<bool> VB;
typedef vector<VB> VVB;

int W, H;
VVB v;

void propagate_white(int h, int w){
    if(!(0 <= h && h < H && 0 <= w && w < W)) return;
    if(!v[h][w]) return;
    v[h][w] = false;
    propagate_white(h-1, w-1); propagate_white(h-1, w); propagate_white(h-1, w+1);
    propagate_white(h  , w-1);                          propagate_white(h  , w+1);
    propagate_white(h+1, w-1); propagate_white(h+1, w); propagate_white(h+1, w+1);
}

void filter_noise(){
    for(int h = 0; h < H; ++h){
        for(int w = 0; w < W; ++w){
            if(!v[h][w]) continue;
            if((!v[h-1][w-1] && !v[h-1][w] && !v[h-1][w+1] &&
                !v[h  ][w-1]               && !v[h  ][w+1] &&
                !v[h+1][w-1] && !v[h+1][w] && !v[h+1][w+1])) v[h][w] = false;
        }
    }
}

int A = 0, B = 0, C = 0;

void identify_shape(int h, int w){
    int i = w; while(v[h][i]) ++i; i -= w;
    int j = h; while(v[j][w]) ++j; j -= h;
    int x = 2*i-j;
    int y = 2*j-3*i;
    if(x <= 0 || y <= 0) return;
    if     (!v[h+  x    ][w+x+y]) ++C;
    else if( v[h+2*x+2*y][w+x  ]) ++B;
    else                          ++A;
}

int main(){
    cin >> W >> H;
    v = VVB(H, VB(W, false));{
        string s;
        for(int h = 0; h < H; ++h){
            cin >> s;
            for(int w = 0; w < W; ++w){
                v[h][w] = (s[w] == '#');
            }
        }
    }
    propagate_white(0,0);

    filter_noise();

    for(int h = 0; h < H; ++h){
        for(int w = 0; w < W; ++w){
            if(v[h][w]){
                identify_shape(h, w);
                propagate_white(h, w);
            }
        }
    }
    cout << A << " " << B << " " << C << endl;
    return 0;
}
