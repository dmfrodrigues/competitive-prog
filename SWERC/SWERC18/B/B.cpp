#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<lli> VI;

int main(){
    lli N; cin >> N;
    VI a(N), b(N);
    for(lli i = 0; i < N; ++i) cin >> a[i] >> b[i];
    lli ret = 1;
    multiset<lli> a_, b_;
    lli n = 0, s = 0; a_.insert(a[s]); b_.insert(b[s]);
    while(s < N){
        lli e = *(--a_.end()), w = *(b_.begin());
        if(w-e >= s-n){
            ret = max(ret, s-n+1);
            ++s; if(s<N){ a_.insert(a[s]); b_.insert(b[s]); }
        } else {
            a_.erase(a_.find(a[n])); b_.erase(b_.find(b[n])); ++n;
            ++s; if(s<N){ a_.insert(a[s]); b_.insert(b[s]); }
        }
    }
    cout << ret << endl;
    return 0;
}
