#include <bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(), (v).end()
typedef long long int lli;

int main(){
    lli N, k; cin >> N >> k;
    vector<bool> v(N, true);
    lli ret = 0;
    lli cnt = 0;
    while(k--){
        lli i; cin >> i;
        for(lli j = i-1; j < N; j += i){
            v[j] = !v[j];
            cnt += (v[j] ? -1 : 1);
        }
        ret = max(ret, cnt);
    }
    cout << ret << endl;
    return 0;
}
