#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n)        for (int i = 0; i < (n); i++)
typedef long long int lli;

int main(){
    lli W; cin >> W;
    lli N; cin >> N;
    lli A = 0;
    lli w, h;
    FOR(i, N){
        cin >> w >> h;
        A += w*h;
    }
    cout << A/W << endl;
    return 0;
}
