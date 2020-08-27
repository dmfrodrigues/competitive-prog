#include <iostream>
#include <set>
#include <map>
#include <limits>

using namespace std;

typedef   long long int lli;
typedef             lli  ID;
typedef pair<char,char> pcc;

const lli LLI_MIN = numeric_limits<lli>::min();
const lli LLI_MAX = numeric_limits<lli>::max();

int main(){
    lli N; cin >> N;
    set< pair<pcc, lli> > Edges;{
        char c1, c2; lli F;
        for(lli i = 0; i < N; ++i){
            cin >> c1 >> c2 >> F;
            if(c1 == c2) continue;
            if(c2  < c1) swap(c1,c2);
            Edges.insert(pair<pcc,lli>(pcc(c1,c2), F));
            Edges.insert(pair<pcc,lli>(pcc(c2,c1), F));
        }
    }

    auto it2 = Edges.begin();
    auto it1 = it2;
    while(true){
        it1 = it2++; if(it1 == Edges.end() || it2 == Edges.end()) break;
        if(it1->first == it2->first){
            pair<pcc,lli> e1 = *it1;
            pair<pcc,lli> e2 = *it2;
            char c1 = e1.first.first;
            char c2 = e1.first.second;

            Edges.erase(Edges.find(pair<pcc,lli>(pcc(c1,c2), e1.second)));
            Edges.erase(Edges.find(pair<pcc,lli>(pcc(c1,c2), e2.second)));
            Edges.erase(Edges.find(pair<pcc,lli>(pcc(c2,c1), e1.second)));
            Edges.erase(Edges.find(pair<pcc,lli>(pcc(c2,c1), e2.second)));

            lli F = max(e1.second, e2.second);
            Edges.insert(pair<pcc,lli>(pcc(c1,c2), F));
            Edges.insert(pair<pcc,lli>(pcc(c2,c1), F));

            it2 = Edges.begin();
            continue;
        }
        auto it_left  = (  Edges.lower_bound(pair<pcc,lli>(it1->first, LLI_MIN)));
        auto it_right = (--Edges.lower_bound(pair<pcc,lli>(it1->first, LLI_MAX)));
        if(it1 == it_left && it2 == it_right){
            pair<pcc,lli> e1 = *it1;
            pair<pcc,lli> e2 = *it2;
            char c0 = e1.first.first;
            char c1 = e1.first.second;
            char c2 = e2.first.second;
            if(c0 == 'A' || c0 == 'Z') continue;
            Edges.erase(Edges.find(pair<pcc,lli>(pcc(c0,c1), e1.second)));
            Edges.erase(Edges.find(pair<pcc,lli>(pcc(c1,c0), e1.second)));
            Edges.erase(Edges.find(pair<pcc,lli>(pcc(c0,c2), e2.second)));
            Edges.erase(Edges.find(pair<pcc,lli>(pcc(c2,c0), e2.second)));
            lli F = min(e1.second, e2.second);
            Edges.insert(pair<pcc,lli>(pcc(c1,c2), F));
            Edges.insert(pair<pcc,lli>(pcc(c2,c1), F));

            it2 = Edges.begin();
            continue;
        }
    }

    if(!Edges.empty()){
        cout << Edges.begin()->second << endl;
    }else{
        cout << 0 << endl;
    }

    return 0;
}
