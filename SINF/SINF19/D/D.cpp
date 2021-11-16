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

class alGraph:public vector< deque<lli> >{ // Adjency List
public:
    alGraph(lli s):vector< deque<lli> >(s){}
    void addEdge(lli src, lli dst) {
        assert(0 <= min(src,dst) && max(src,dst) < 26);
        (*this)[src].push_back(dst);
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
            if(!curr_s.empty()) send.push_back(curr_s);
        }else{
            al.addEdge(c-'a', curr_c-'a');
            //cout << "ADDED EDGE " << c << "->" << curr_c << endl;
            solve(send);
            send = deque<string>();
            c = curr_c;
            if(!curr_s.empty()) send.push_back(curr_s);
        }
    }
    solve(send);
}

VI indegrees(const alGraph& g) {
    VI in(g.size(), 0);
    for(auto n:g) for(auto c:n) ++in[c];
    return in;
}
bool topsort(const alGraph& g, VI& top_order){
    if(top_order.size() != g.size()) return false;

    //FOR(i,0,g.size()) if(bfs(g,i)) return false;

    VI in_degree = indegrees(g);
    vector<bool> visited(g.size(), false);
    priority_queue<lli, vector<lli>, greater<lli> > q;
    FOR(i,0,g.size()) if(in_degree[i] == 0) q.push(i);
    ulli n = 0;
    while(!q.empty()){
        const ulli &cur = q.top(); q.pop();
        if(visited[cur]) return false;
        visited[cur] = true;
        top_order[n++] = cur;
        for(const auto& itr:g[cur])
            if(--in_degree[itr] == 0)
                q.push(itr);
    }
    return (n == g.size() &&
            set<lli>(top_order.begin(), top_order.end()).size() == n);
}

VI sorted(26);

struct comp{
public:
    bool operator()(const string &s1, const string &s2){
        FOR(i,0,min(s1.size(), s2.size())){
            lli i1 = find(ALL(sorted), s1[i]-'a')-sorted.begin();
            lli i2 = find(ALL(sorted), s2[i]-'a')-sorted.begin();
            if(i1 != i2) return (i1 < i2);
        }
        return (s1.size() < s2.size());
    }
} mycomp;

int main(){
    lli N; cin >> N;
    deque<string> v(N);
    for(string &s:v) cin >> s;
    solve(v);

    FOR(i,0,al.size()) for(const lli &j:al[i]) assert(i != j);
    if(topsort(al, sorted)){
        deque<string> new_v = v;
        sort(ALL(new_v), mycomp);
        if(new_v != v){
            cout << "Impossible" << endl;
            return 0;
        }
        for(const auto &i:sorted) cout << char('a'+i);
        cout << endl;
    }else{
        cout << "Impossible" << endl;
    }
    return 0;
}
