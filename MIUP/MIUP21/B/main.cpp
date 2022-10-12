/**
 * Complexity: O(M*N*K)
 */

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

int M, N;

int dist(int a, int b){
    a = a-1;
    b = b-1;
    int xa = a % N;
    int ya = a / N;
    int xb = b % N;
    int yb = b / N;
    return abs(xa-xb) + abs(ya-yb);
}

int main(){
    int K; cin >> M >> N >> K;
    vector<int> friends(K);
    FOR(k,0,K) cin >> friends[k];
    
    FOR(i,1,M*N+1){
        bool good = true;
        int d = dist(i, friends[0]);
        FOR(k,1,K){
            if(dist(i, friends[k]) != d){
                good = false;
                break;
            }
        }
        if(d == 0) good = false;
        if(good){
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}
