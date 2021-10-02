/*
ID: dmfrodr1
TASK: fence
LANG: C++11
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

VI euler_circuit(vector<multiset<lli>> &adj, lli u){
    while(!adj[u].empty()){
        lli v = *adj[u].begin();
        adj[u].erase(adj[u].find(v));
        adj[v].erase(adj[v].find(u));
        euler_circuit(adj, v);
    }
    
}

int main(){
    ifstream fin("fence.in");
    ofstream fout("fence.out");
    
    ///INPUT
    

    ///PROCESSING
    
    
    ///OUTPUT
    

    return 0;
}
