#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef long long int lli;

vector<lli> F(25);
void startF(){
    F[0] = 1;
    F[1] = 1;
    for(lli i = 2; i < (lli)F.size(); ++i){
        F[i] = F[i-2]+F[i-1];
    }
}

tuple<lli,lli,lli> solve(const lli& r, const lli& T){
    if(r == 2) return make_tuple(1, T-1, T-1);

    lli y, R;
    const lli a = F[r-1];
    const lli b = F[r]-1;
    const lli c = F[r-3];
    const lli d = F[r-2];
    for(lli x = 1; x <= T; ++x){
        y = (T-a*x)/b;
        if(a*x+b*y == T){
            R = c*x+d*y;
            return make_tuple(x,y,R);
        }
    }
    return make_tuple(-1,-1,-1);
}

int main(){
/*
4 3 500
5 3 10000
6 4 8000
8 5 12000
0
=>
=>
=>
=>
*/
    startF();
    lli r, k, T;
    while(true){
        cin >> r; if(r == 0) break;
        cin >> k >> T;
        auto ret = solve(r, T);
        cout << get<0>(ret) << " " << get<1>(ret) << " " << k*get<2>(ret) << endl;
    }
    return 0;
}
