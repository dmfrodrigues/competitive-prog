#include <bits/stdc++.h>
using namespace std;
typedef long double ld;

int main(){
    int n; cin >> n;
    while(n--){
        int y; ld B, r; cin >> y >> B >> r;
        r = r/ld(100.0L)+ld(1.0L);
        ld up = 1.0L;
        ld sum = 0.0L;
        for(int i = 0; i < y; ++i, up *= r){
            sum += up;
        }
        ld ans = up/sum;
        ans = B*ans;
        ans = y*ans;
        cout << setprecision(3) << fixed << ans << endl;
    }
}
