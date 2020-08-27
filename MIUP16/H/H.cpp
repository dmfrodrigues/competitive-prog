#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i)=(b); (i) < lli(e); (i)++)

struct MEMBER {
    lli s, e, n;
};

int main(){
    lli N; cin >> N;
    vector<MEMBER> v(N);
    for(MEMBER &m:v){
        cin >> m.n >> m.s >> m.e;
    }
    map<lli, set<lli> > starts;
    map<lli, set<lli> > ends;
    FOR(i,0,v.size()){
        starts[v[i].s].insert(i);
        ends  [v[i].e].insert(i);
    }
    set<lli> ret;
    while(!ends.empty()){
        const pair<lli, set<lli> > &curr = *ends.begin();
        const lli &pos = curr.first;
        const set<lli> &curr_set = curr.second;

        lli n = v[*curr_set.begin()].n;
        for(const lli &i:curr_set) n = max(n, v[i].n);

        lli insert_pos = pos;
        while(n){
            if(ret.find(insert_pos) != ret.end()){
                --insert_pos;
            }else{
                const auto &lim = starts.upper_bound(insert_pos);
                auto it1 = starts.begin();
                while(it1 != lim){

                    auto it2 = it1->second.begin();
                    while(it2 != it1->second.end()){

                        v[*it2].n -= n;
                        if(v[*it2].n <= 0){
                                  ends  [v[*it2].e].erase(  ends[v[*it2].e].find(*it2));
                            if(ends[v[*it2].e].empty()) ends.erase(v[*it2].e);
                            it2 = starts[v[*it2].s].erase(starts[v[*it2].s].find(*it2));
                        }else{
                            ++it2;
                        }
                    }
                    if(it1->second.empty()){
                        it1 = starts.erase(starts.find(it1->first));
                    }else{
                        ++it1;
                    }
                }
                ret.insert(insert_pos);
                --n;
            }
        }
    }
    cout << ret.size() << endl;
    return 0;
}
