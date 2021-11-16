#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template<class T> T myabs(const T& n){return (n < 0L? -n:n);}
typedef long long int lli;
typedef pair<lli,lli> pii;

vector< vector<lli> > create_height(const lli& N, const lli& A, const lli& B, const lli& C){
    vector< vector<lli> > ret(N, vector<lli>(N));
    for(lli i = 0; i < N; ++i){
        auto& ret_i = ret[i];
        for(lli j = 0; j < N; ++j){
            ret_i[j] = ((i*N+j)*A+B)%C;
        }
    }
    return ret;
}

bool is_possible(const vector< vector<lli> >& height, const pii& A, const pii& B, const lli& h){
    const lli& N = height.size();
    const lli hA = height[A.first][A.second];
    const lli hB = height[B.first][B.second];

    vector< vector<bool> > visited(N, vector<bool>(N, false));
    deque<pii> dqe;
    pii curr;
    dqe.push_back(A);
    while(!dqe.empty()){
        curr = dqe.front(); dqe.pop_front();
        if(visited[curr.first][curr.second]) continue;
        visited[curr.first][curr.second] = true;

        if(0 <= curr.first-1  && h <= height[curr.first-1][curr.second] && !visited[curr.first-1][curr.second])
            dqe.push_back(pii(curr.first-1, curr.second));
        if(curr.first+1 < N   && h <= height[curr.first+1][curr.second] && !visited[curr.first+1][curr.second])
            dqe.push_back(pii(curr.first+1, curr.second));
        if(0 <= curr.second-1 && h <= height[curr.first][curr.second-1] && !visited[curr.first][curr.second-1])
            dqe.push_back(pii(curr.first, curr.second-1));
        if(curr.second+1 < N  && h <= height[curr.first][curr.second+1] && !visited[curr.first][curr.second+1])
            dqe.push_back(pii(curr.first, curr.second+1));

        if(visited[B.first][B.second]) return true;
    }
    return false;
}

lli solve(const vector< vector<lli> >& height, const pii& A, const pii& B){
    const lli hA = height[A.first][A.second];
    const lli hB = height[B.first][B.second];

    lli V = min(hA, hB);
    lli v = 0;
    lli m;
    while(V != v){
        m = (V+v)/2+1;
        if(is_possible(height, A, B, m))
            v = m;
        else
            V = m-1;
    }

    lli ret = myabs(m-hA) + myabs(m-hB);
    return ret;
}

int main(){

/*
4
1 1 3 3
617 253 486
*/

    lli N; cin >> N;
    pii Asky; cin >> Asky.first >> Asky.second; --Asky.first; --Asky.second;
    pii Bsky; cin >> Bsky.first >> Bsky.second; --Bsky.first; --Bsky.second;
    lli A,B,C; cin >> A >> B >> C;
    vector< vector<lli> > height = create_height(N, A,B,C);

//    for(int j = 0; j < N; ++j){
//        cout << "j=" << j << " ";
//        for(int i = 0; i < N; ++i)
//            cout << height[i][j] << "   ";
//        cout << endl;
//    }

    lli ans = solve(height, Asky, Bsky);
    cout << ans << endl;

    return 0;
}
