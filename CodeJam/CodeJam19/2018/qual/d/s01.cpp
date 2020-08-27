#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

struct PT{
    LD x, y, z;
};

void solve(LD s){
    LD x = sqrt(2.0L)/6.0L*s+sqrt(3.0L-s*s)/3.0L;
    PT v1({x, sqrt(0.5L-x*x), +sqrt(2.0L)/2.0L});
    PT v2({x, sqrt(0.5L-x*x), -sqrt(2.0L)/2.0L});
    PT v3({-sqrt(1.0L-2.0L*x*x), sqrt(2.0L)*x, 0.0L});
    cout << setprecision(15);
    cout << v1.x/2.0L << " " << v1.y/2.0L << " " << v1.z/2.0L << endl;
    cout << v2.x/2.0L << " " << v2.y/2.0L << " " << v2.z/2.0L << endl;
    cout << v3.x/2.0L << " " << v3.y/2.0L << " " << v3.z/2.0L << endl;
}

int main(){
    int T; cin >> T;
    for(int i = 0; i < T; ++i){
        LD A; cin >> A;
        cout << "Case #" << i+1 << ":" << endl;
        solve(A);
    }

    return 0;
}
