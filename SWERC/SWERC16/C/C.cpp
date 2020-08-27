#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

int main(){
    ///INPUT
    int D; cin >> D;
    int R, T; cin >> R >> T;
    ///PROCESSING
    int b = D+1;
    int c = ((D+1)*D)/2 -9-R-T;
    int Delta = b*b - 4*c;
    int sqrtDelta = ld(sqrt(ld(Delta)) + 0.5L);
    int t = (-b+sqrtDelta)/2;
    int R_real = ((t+D+1)*(t+D))/2 - 6;
    int ans = R-R_real;
    ///OUTPUT
    cout << ans << endl;
    return 0;
}
