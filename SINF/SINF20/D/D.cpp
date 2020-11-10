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

unordered_map<string, lli> id;
VVI adj;
vector<bool> visited;
lli get_node(const string &s){
    if(id.find(s) == id.end()){
        id[s] = id.size();
        adj.push_back(VI());
        visited.push_back(false);
    }
    return id.at(s);
}
void add_edge(lli u, lli v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(lli u){
    if(visited.at(u)) return;
    visited.at(u) = true;
    for(const lli &v: adj.at(u))
        dfs(v);
}

int main(){
    string dummy;
    lli N; cin >> N; getline(cin, dummy); 
    FOR(i,0,N){
        string su, sv; getline(cin, su); getline(cin, sv);
        lli u = get_node(su), v = get_node(sv);
        add_edge(u, v);
    }
    lli ret = 0;
    FOR(i,0,adj.size()){
        if(visited.at(i)) continue;
        ++ret;
        dfs(i);
    }
    cout << ret << endl;

    return 0;
}
