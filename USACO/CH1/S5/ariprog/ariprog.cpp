/*
ID: dmfrodr1
TASK: ariprog
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PNN;

int N, M;
vector<int> x;
unordered_set<int> m;

void fill_stuff(){
    set<int> s;
    for(int p = 0; p <= M; ++p)
        for(int q = 0; q <= M; ++q)
            s.insert(p*p+q*q);
    x = vector<int>(s.begin(), s.end());
    m = unordered_set<int>(x.begin(), x.end());
}

int main(){
    ///INPUT
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    fin >> N >> M;
    ///PROCESSING
    fill_stuff();
    deque<PNN> ans;
    for(int i = 0; i != x.size(); ++i){
        for(int j = i+1; j < x.size(); ++j){
            int k = x[j]-x[i];
            int b = x[i];
            if(b + (N-1)*k > 2*M*M) break;
            bool valid = true;
            for(int n = 0; n < N; ++n){
                if(m.find(b+n*k) == m.end()){
                    valid = false;
                    break;
                }
            }
            if(valid)
                ans.push_back({k, x[i]});
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.empty()){
        fout << "NONE" << endl;
    }else{
        for(auto it:ans) fout << it.second << " " << it.first << "\n";
        fout << flush;
    }
    return 0;
}
