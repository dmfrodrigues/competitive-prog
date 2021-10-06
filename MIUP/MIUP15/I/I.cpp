#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

map<lli,lli> ans;

lli f(lli N){
    if(ans.find(N) != ans.end()) return ans[N];
    if(N == 1) return ans[N] = 0;
    lli N1 = N/2;
    lli N2 = N-N1;
    return ans[N] = f(N1)+f(N2) + N2 + N1;
}

int main(){
    lli T; cin >> T;
    while(T--){
        lli N; cin >> N; N += 1;
        cout << f(N) << endl;
    }
    return 0;
}
