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

int main(){
    int N; cin >> N;

    bool y = true;

    stack<int> s;

    int n;
    FOR(i,0,N){
        cin >> n;
        if(n > 0) s.push(n);
        else {
            if(s.empty()){
                y = false;
                break;
            }
            int m = s.top(); s.pop();
            if(m != -n){
                y = false;
                break;
            }
        }
    }

    y &= (s.empty());
    cout << (y ? "y" : "n") << endl;

    return 0;
}
