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

VI euler_circuit(vector<multiset<lli>> adj, lli source){
    stack<lli> call_stack;
    VI circuit;
    call_stack.push(source);
    while(!call_stack.empty()){
        lli u = call_stack.top();
        if(!adj[u].empty()){
            lli v = *adj[u].begin();
            adj[u].erase(adj[u].find(v));
            adj[v].erase(adj[v].find(u));
            call_stack.push(v);
        } else {
            circuit.push_back(u);
            call_stack.pop();
        }
    }
    reverse(ALL(circuit));
    return circuit;
}

/*
class euler_circuit{
    vector<multiset<lli>> adj;
    stack<lli> call_stack;
    VI circuit;
public:
    euler_circuit(vector<multiset<lli>> adj_):adj(adj_){}
    VI compute(lli u){
        call_stack.push(u);
        while(!call_stack.empty()){
            u = call_stack.top();
            if(!adj[u].empty()){
                lli v = *adj[u].begin();
                adj[u].erase(adj[u].find(v));
                adj[v].erase(adj[v].find(u));
                call_stack.push(v);
            } else {
                circuit.push_back(u);
                call_stack.pop();
            }
        }
        reverse(ALL(circuit));
        return circuit;
    }
};
*/

int main(){
    ifstream fin("fence.in");
    ofstream fout("fence.out");
    
    ///INPUT
    int F; fin >> F;
    vector<multiset<lli>> adj(500);
    int u, v;
    FOR(i,0,F){
        fin >> u >> v;
        adj[u-1].insert(v-1);
        adj[v-1].insert(u-1);
    }

    ///PROCESSING
    lli source = 0;
    FOR(i,0,adj.size()) if(adj[i].size() % 2 == 1){
        source = i;
        break;
    }

    VI ret = euler_circuit(adj, source);
    
    ///OUTPUT
    for(const int &u: ret) fout << u+1 << endl;

    return 0;
}
