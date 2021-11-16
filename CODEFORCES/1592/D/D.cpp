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

struct edge_t {
    lli u, v;
};

vector<edge_t> edges;
vector<set<edge_t*>> adj;

lli query(const set<edge_t*> &s){
    set<lli> nodes;
    for(const edge_t* e: s){
        nodes.insert(e->u);
        nodes.insert(e->v);
    }

    cout << "? " << nodes.size();
    for(const lli &u: nodes) cout << " " << u+1;
    cout << endl;

    lli res;
    cin >> res;
    return res;
}

set<edge_t*> dfs(set<edge_t*> s, const lli &N){
    /*
    cerr << "Called dfs with args:" << endl;
    cerr << "s=" << endl;
    for(const edge_t *e: s) cerr << e->u << " - " << e->v << endl;
    cerr << "N=" << N << endl;
    */

    set<edge_t*> t;
    
    stack<pair<edge_t*, lli>> st;
    vector<bool> visited(adj.size(), false);

    for(const edge_t *edge: s){
        if(!visited[edge->u] && !visited[edge->v]){
            //cerr << "edge=" << edge->u << " - " << edge->v << endl;
            st.push(make_pair(nullptr, (*s.begin())->u));

            while(!st.empty()){
                auto p = st.top(); st.pop();
                edge_t *prev = p.first;
                lli u = p.second;

                //cerr << "Popped " << u << endl;

                if(visited[u]) continue;
                visited[u] = true;

                //cerr << u << " had not yet been visited" << endl;
                
                if(prev != nullptr){
                    t.insert(prev);
                    //cerr << "INSERTED INTO T" << endl;
                }
                if(t.size() >= N) break;

                //cerr << "Adding adjacents to " << u << endl;

                for(edge_t *e: adj.at(u)){
                    lli v = (e->u == u ? e->v : e->u);
                    if(!visited.at(v)){
                        //cerr << "Adding " << v << ", adjacent to " << u << endl;
                        st.push(make_pair(e, v));
                    }
                }
            }
        }

        if(t.size() >= N) break;
    }

    assert(t.size() == N);
    return t;
}

int main(){
    try {
        // INPUT
        lli n; cin >> n;
        edges = vector<edge_t>(n-1);
        adj = vector<set<edge_t*>>(n);
        FOR(i,0,n-1){
            cin >> edges.at(i).u >> edges.at(i).v;
            --edges.at(i).u; --edges.at(i).v;
            adj[edges.at(i).u].insert(&edges.at(i));
            adj[edges.at(i).v].insert(&edges.at(i));
        }

        // PROCESSING
        set<edge_t*> s; FOR(i,0,n-1) s.insert(&edges.at(i));
        const lli m = query(s);

        while(s.size() > 1){
            //cerr << "L113" << endl;
            lli N = s.size()/2;
            set<edge_t*> s1 = dfs(s, N);
            lli m1 = query(s1);
            if(m1 == m){
                for(edge_t *e: s){
                    if(!s1.count(e)){
                        adj.at(e->u).erase(e);
                        adj.at(e->v).erase(e);
                    }
                }
                s = s1;
            } else { //cerr << "L125" << endl;
                for(edge_t *e: s1){
                    adj.at(e->u).erase(e);
                    adj.at(e->v).erase(e);
                } //cerr << "L129" << endl;
                for(edge_t *e: s1) s.erase(e); //cerr << "L131" << endl;
            }
            //cerr << "L132, s.size=" << s.size() << endl;
        }

        //cout << "s.size=" << s.size() << endl;
        assert(s.size() == 1);

        edge_t *e = *s.begin();
        cout << "! " << e->u+1 << " " << e->v+1 << endl;

        return 0;
    } catch(const exception &ex){
        cout << ex.what() << endl;
        return -1;
    }
}
