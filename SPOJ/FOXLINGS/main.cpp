#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

typedef int lli;
typedef pair<lli,lli> pii;

inline lli solve(const vector< deque<lli> >& Adj, const vector<lli>& have_friends){
    const lli& N = Adj.size();



//    for(int i = 0; i < N; ++i){
//        cout << "Adj[" << i << "]: ";
//        for(const auto& c:Adj[i])
//            cout << c << " ";
//        cout << endl;
//    }
//    cout << "have_friends: ";
//    for(const auto& i:have_friends)
//        cout << i << " ";
//    cout << endl;







    lli ret = 0;

    vector<bool> visited(N, false);
    deque<lli> dqe;
    lli curr;
    for(vector<lli>::const_iterator it = have_friends.begin(); it != have_friends.end(); ++it){
    	const lli& i = *it;
        if(visited[i]) continue;
        ++ret;
        dqe.push_back(i);
        while(!dqe.empty()){
            curr = dqe.front(); dqe.pop_front();
            if(visited[curr]){
                continue;
            }
            visited[curr] = true;
            const deque<lli>& Adj_curr = Adj[curr];
            for(deque<lli>::const_iterator it_ = Adj_curr.begin(); it_ != Adj_curr.end(); ++it_){
            	const lli& c = *it_;
                if(!visited[c]){
                    dqe.push_back(c);
                }
            }
        }
    }

    lli do_not_have_friends = N - have_friends.size();

    ret += do_not_have_friends;

    return ret;
}

int main(){
    lli N, M; cin >> N >> M;
    vector<pii> Edges(M);
    set<lli> have_friends;
    vector< deque<lli> > Adj(N);{
        for(auto& e:Edges){
            cin >> e.first >> e.second;
            --e.first; --e.second;

            have_friends.insert(e.first);
            have_friends.insert(e.second);

            Adj[e.first ].push_back(e.second);
            Adj[e.second].push_back(e.first );
        }
    }
    lli ans = solve(Adj, vector<lli>(have_friends.begin(),have_friends.end()));
    cout << ans << endl;
    return 0;
}
