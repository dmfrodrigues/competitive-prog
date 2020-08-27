#include <bits/stdc++.h>
#define FOR(i, n)       for(unsigned i = 0 ; (i)  < (n); ++(i))

#define NUMT long

using namespace std;

int eval(string s){
    int ans = 0;
    int pow = 1;
    for(auto c:s){
        if(c == 'C') pow *= 2;
        else         ans += pow;
    }
    return ans;
}

int solve(string s, NUMT d){
    int ans = 0;
    if(eval(s) <= d) return ans;
    set<int> charge;
    FOR(i, s.size()) if(s[i] == 'C') charge.insert(i);
    for(auto it = charge.rbegin(); it != charge.rend(); ++it){
        int i = *it;
        for(unsigned j = i+1; j < s.size(); ++j){
            swap(s[j-1], s[j]); ++ans;
            if(eval(s) <= d) return ans;
        }
        s = string(s.begin(), s.end()-1);
    }
    return -1;
}

int main(){
    unsigned T; cin >> T;
    NUMT D; string P;
    FOR(t,T){
        cin >> D >> P;
        int ans = solve(P, D);
        cout << "Case #" << t+1 << ": ";
        if(ans == -1) cout << "IMPOSSIBLE" << endl;
        else          cout << ans          << endl;
    }
    return 0;
}
