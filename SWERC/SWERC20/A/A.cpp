#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
#define FOR(i, b, e)            for(int32_t i =(b); (i)  < (int32_t)(e); ++(i))

int main(){
    ios_base::sync_with_stdio(0);
    // INPUT
    size_t N, K; scanf("%lu %lu\n", &N, &K);
    N *= 3;
    unordered_map<string, pair<int32_t, int32_t> > m;
    char *s = new char[60]; size_t n;
    FOR(i,0,N){
        getline(&s, &n, stdin);
        auto it = m.find(s);
        if(it == m.end()){
            m[s] = make_pair(1, i);
        } else {
            ++it->second.first;
            it->second.second = i;
        }
    }

    // PROCESS
    map<pair<int32_t, int32_t>, string> w;
    int32_t i = 0;
    for(auto it = m.begin(); it != m.end(); ++it, ++i){
        w[it->second] = it->first;
    }
    size_t L = min(K, w.size());
    auto it = w.rbegin();
    FOR(i,0,L){
        cout << it->second;
        ++it;
    }

    return 0;
}
