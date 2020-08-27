#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli K;
bool M;

lli sol(lli N, lli l){
    lli d = (N-l)/K+1;
    if( M && N   < K  ) return 1;
    if(!M && N-d < K-1) return N;
    lli x_ = sol(N-d, (l-1+K*d)%N+1);
    lli c = (x_-l+K-1)/(K-1);
    return x_ + c;
}

int main(){
    lli N; cin >> N >> K >> M;
    cout << sol(N, K) << endl;
    return 0;
}
