#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef vector<lli>             VI;

int main(){
    lli N; cin >> N;
    VI v(N); for(lli &i:v) cin >> i;
    lli ans = max_element(v.begin(), v.end()) - v.begin();
    cout << ans << endl;
    return 0;
}
