#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
const lli LLI_INF = numeric_limits<lli>::max();

lli Dijkstra(const vector< vector<lli> >& weight, const int& a, const int& b){
    const int& N = weight.size();
    multimap<lli,int> myqueue;
    vector<bool> visited(N,false);
    vector<lli>  dist(N,LLI_INF);
    dist[a] = 0; myqueue.insert(pair<lli,int>(0,a));
    int n; int c; lli new_dist;
    while(!myqueue.empty()){
        n = myqueue.begin()->second; myqueue.erase(myqueue.begin());
        if(visited[n]) continue;
        visited[n] = true;
        for(int c = 0; c < N; ++c){
            if(c == n) continue;
            new_dist = dist[n] + weight[n][c];
            if(new_dist < dist[c]){
                dist[c] = new_dist;
                myqueue.insert(pair<lli,int>(dist[c], c));
            }
        }
    }
    return dist[b];
}

lli solve(const vector< vector<lli> >& dist, const vector<pii>& orders){
    const int& R = orders.size();

    lli ret = 0;

    lli ans;
    for(int r = 0; r < R; ++r){
        ans = Dijkstra(dist, orders[r].first, orders[r].second);
        ret += ans;
    }
    return ret;
}

int main(){

/*
1
3
0 1 1
1 0 1
1 9 0
2
2 1
3 2
*/

    int T; cin >> T; vector<lli> solutions(T);
    int N; vector< vector<lli> > dist;
    int R; vector<pii> orders;
    for(int t = 0; t < T; ++t){
        cin >> N;
        dist = vector< vector<lli> >(N, vector<lli>(N));{
            for(int a = 0; a < N; ++a){
                auto& dist_a = dist[a];
                for(int b = 0; b < N; ++b)
                    cin >> dist_a[b];
            }
        }
        cin >> R;
        orders = vector<pii>(R);{
            for(int i = 0; i < R; ++i){
                cin >> orders[i].first >> orders[i].second;
                --orders[i].first; --orders[i].second;
            }
        }
        solutions[t] = solve(dist, orders);
    }
    for(int t = 0; t < T; ++t)
        cout << "Case #" << t+1 << ": " << solutions[t] << endl;

    return 0;
}
