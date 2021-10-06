#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define contain(Set,i)          ( (Set) & (1Lu<<(i)) )
#define mk(a,b)                 make_pair((a), (b))
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
//#define REP(i, b, e)            for(auto i =(b); (i) != (e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
typedef pair< lli, lli>         PII;
typedef pair<ulli,ulli>         PUU;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second
const lli INF = 1000000000;

struct edge {
    lli fr, to, c;
    bool operator<(const edge& e)const{
        if(c  != e.c ) return (c  < e.c );
        if(fr != e.fr) return (fr < e.fr);
        return (to < e.to);
    }
    bool operator==(const edge& e)const{ return !(*this < e || e <  *this); }
    bool operator> (const edge& e)const{ return !(*this < e || *this == e); }
};

class alGraph:public vector< deque<edge> >{ // Adjency List
public:
    alGraph(lli s):vector< deque<edge> >(s){}
    void addEdge(lli src, lli dst, lli c = 0) {
        (*this)[src].push_back({src, dst, c});
    }
};

alGraph al(26);

void solve(const deque<string> &v){
    //cout << "ARRIVING AT SOLVE WITH STRINGS:" << endl;
    //for(const string &s:v) cout << s << endl;

    if(v.size() <= 1) return;
    deque<string> send;
    char c = v[0][0];
    FOR(i,0,v.size()){
        //cout << "i=" << i << endl;
        const string &curr_s = v[i].substr(1);
        const char   &curr_c = v[i][0];
        //cout << "L51" << endl;
        if(curr_c == c){
            if(!curr_s.empty()){
                //cout << "ADDED " << curr_s << " TO SEND" << endl;
                send.push_back(curr_s);
            }
        }else{
            al.addEdge(c-'a', curr_c-'a');
            //cout << "ADDED EDGE " << c << "->" << curr_c << endl;
            solve(send);
            send = deque<string>();
            c = curr_c; if(!curr_s.empty()) send.push_back(curr_s);
        }
    }
    solve(send);
}



bool topsort(const alGraph& g, VI& top_order){
    if(top_order.size() != g.size()) return false;
    const lli &N = g.size();
    vector<bool> visited(N);
    stack<pair<bool,int> > dfs;
    stack<int> postOrder;
    deque<edge> newVec;
    FOR(i,0,N){
        if(visited[i]==false){
            dfs.push(make_pair(false,i));
        }
        while(!dfs.empty()){
            pair<bool,int> node=dfs.top(); dfs.pop();
            if(node.first){
                postOrder.push(node.second);
                continue;
            }
            visited[node.second]=true;
            dfs.push(make_pair(true, node.second));
            newVec=al[node.second]; //vector of neighboors
            for(auto it=newVec.begin();it!=newVec.end();it++){
                int son=it->to;
                if(visited[son]==false){
                    dfs.push(make_pair(false, son));
                }
            }
        }
    }
    top_order = VI();
    while(!postOrder.empty()){
        top_order.push_back(postOrder.top());
        postOrder.pop();
    }
    return true;
}

int main(){
    lli N; cin >> N;
    deque<string> v(N);
    for(string &s:v) cin >> s;
    solve(v);
    VI sorted(26);
    if(topsort(al, sorted)){
        for(const auto &i:sorted) cout << char('a'+i);
        cout << endl;
    }else{
        cout << "Impossible" << endl;
    }
    return 0;
}
