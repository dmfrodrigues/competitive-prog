#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef long double ldouble;
const ldouble pi = acos(-1.0L);


const ldouble tol_poss = 1e-3;
bool is_possible(ldouble F, const ldouble& m, const vector<ldouble>& volume){
    for(const auto& v:volume){
        F -= floor(v/m);
        if(F <= tol_poss) return true;
    }
    return false;
}

const ldouble tol_bs = 1e-6;
ldouble solve(const lli& F, const vector<ldouble>& volume){
    ldouble v = 0L;
    ldouble V = *max_element(volume.begin(), volume.end());
    ldouble m;
    for(int i = 0; i < 100; ++i){
    //while((V-v) > tol_bs){
        m = (V+v)/(2.0L);
        if(is_possible(F, m, volume))
            v = m;
        else
            V = m;
    }
    return m;
}

int main(){

/*
1
3 3
4 3 3
=>25.1327

1
1 24
5
=>3.1416

1
10 5
1 4 2 3 4 5 6 5 4 2
=>50.2655

3
3 3
4 3 3
1 24
5
10 5
1 4 2 3 4 5 6 5 4 2
=>25.1327
=>3.1416
=>50.2655
*/

    lli T; cin >> T;
    vector<ldouble> solutions(T);
    lli N, F;
    vector<ldouble> volume;
    for(lli t = 0; t < T; ++t){
        cin >> N >> F;
        volume = vector<ldouble>(N);
        for(auto& v:volume){
            cin >> v;
            v = pi*v*v;
        }
        solutions[t] = solve(F+1, volume);
    }
    for(const auto& s:solutions)
        cout << fixed << setprecision(4) << s << endl;

    return 0;
}
