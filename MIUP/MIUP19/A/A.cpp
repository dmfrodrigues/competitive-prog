#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
typedef vector<bool>            VB;
typedef vector<VB>              VVB;
typedef pair< lli, lli>         PII;
typedef pair<ulli,ulli>         PUU;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second
const lli INF = 1000000000;

size_t nDigits(int n){
    if(n < 10) return 1;
    size_t ret = 1;
    while(n >= 10){
        ++ret;
        n /= 10;
    }
    return ret;
}

int main(){
    int N1; cin >> N1;
    vector<int> v1(N1); FOR(i,0,N1) cin >> v1[i];

    int N2; cin >> N2;
    vector<int> v2(N2); FOR(i,0,N2) cin >> v2[i];

    map<int, multiset<int>> m1, m2;
    for(const int &n: v1){ m1[n/10]; m2[n/10]; }
    for(const int &n: v2){ m1[n/10]; m2[n/10]; }
    for(const int &n: v1){ m1[n/10].insert(n%10); }
    for(const int &n: v2){ m2[n/10].insert(n%10); }

    size_t maxLeft = 0;
    size_t maxTenths = 0;
    for(const auto &p: m2){
        maxLeft = max(maxLeft, p.second.size());
        maxTenths = max(maxTenths, nDigits(p.first));
    }

    for(const auto &p: m1){
        int tenth = p.first;
        const multiset<int> &u1 = m1.at(tenth);
        const multiset<int> &u2 = m2.at(tenth);

        cout << string(maxLeft-u2.size(), '.');
        for(auto it = u2.rbegin(); it != u2.rend(); ++it) cout << *it;
        cout << ".|" << string(maxTenths-nDigits(tenth), '.') << tenth << "|.";
        for(auto it = u1.begin(); it != u1.end(); ++it) cout << *it;
        cout << endl;
    }

    return 0;
}
