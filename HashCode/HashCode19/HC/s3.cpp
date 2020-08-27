#include<bits/stdc++.h>
#define NUMT long
#define MAXN 100005
using namespace std;
typedef pair<NUMT,NUMT> PNN;

const NUMT TRIALS = 10;

NUMT N;
char Dir[MAXN];
set<string> Tag[MAXN];

struct vert{
    NUMT ph1;
    NUMT ph2;
    NUMT sz;
    bool operator<(const vert& obj) const{
        return (this->sz > obj.sz);
    }
};

set<string> union_tags(NUMT i1, NUMT i2){
    set<string> ret = Tag[i1];
    if(i2 != -1) ret.insert(Tag[i2].begin(), Tag[i2].end());
    return ret;
}

NUMT get_intersection(const set<string>& s1, const set<string>& s2){
    NUMT ret = 0;
    for(const auto& it:s1)
        if(s2.find(it) != s2.end()) ++ret;
    return ret;
}

vector<vert> pair_vertical(deque<NUMT> H){
    //shuffle(H.begin(), H.end(), default_random_engine(rand()));
    vector<vert> ret(H.size()/2);
    //cerr << "L25" << endl;
    //cerr << ret.size() << endl;
    for(NUMT i = 0; i < ret.size(); ++i){
        //cerr << i << " " << 2*i+1 << " " << H.size() << endl;
        NUMT l = H[2*i], r = H[2*i+1];
        ret[i] = {l, r, NUMT(Tag[l].size()+Tag[r].size())};
    }
    //cerr << "L30" << endl;
    return ret;
}

bool cmp(const NUMT& lhs, const NUMT& rhs){
    return (Tag[lhs].size() > Tag[rhs].size());
}

vector<PNN> make_trial(){
    deque<NUMT> H, V;
    for(NUMT i = 0; i < N; ++i){
        if(Dir[i] == 'H') H.push_back(i);
        else              V.push_back(i);
    }

    sort(V.begin(), V.end(), cmp);
    vector<vert> VERT = pair_vertical(V);
    deque<vert> evry(VERT.begin(), VERT.end());
    for(const auto& it:H)
        evry.push_back({it, -1, (NUMT)Tag[it].size()});




    //cerr << "L69" << endl;
    set<vert> stuff;
    for(NUMT i = 0; i < evry.size(); ++i){
        //cerr << "L72, i=" << i << endl;
        for(NUMT j = i+1; j < evry.size(); ++j){
            //cerr << "i=" << i <<", j=" << j << ", evry.size=" << evry.size() << endl;
            set<string> lTag = union_tags(evry[i].ph1, evry[i].ph2);
            //cerr << "L75" << endl;
            set<string> rTag = union_tags(evry[j].ph1, evry[j].ph2);
            //cerr << "L77" << endl;
            NUMT intersect = get_intersection(lTag, rTag);
            //cerr << "L79" << endl;
            NUMT score = min((NUMT)intersect,
                         min((NUMT)lTag.size()-intersect,
                             (NUMT)rTag.size()-intersect));
            //cerr << "L83" << endl;
            stuff.insert({i, j, score});
            //cerr << "L85" << endl;
        }
    }

    stuff

    //cerr << "L83" << endl;



    vector<PNN> ans(evry.size());
    for(NUMT i = 0; i < ans.size(); ++i){
        ans[i] = {evry[i].ph1, evry[i].ph2};
    }
    //cerr << "L64" << endl;
    /*
    while(!H.empty() || !V.empty()){
        NUMT r = rand()%(H.size()+V.size());
        if(r < H.size()){
            ans.push_back({H.front(), -1});
            H.pop_front();
        }else{
            auto tmp = V.front(); V.pop_front();
            ans.push_back({tmp, V.front()});
            V.pop_front();
        }
    }
    */
    return ans;
}

NUMT get_points(const vector<PNN>& s){
    NUMT ret = 0;
    for(NUMT i = 0; i < s.size()-1; ++i){ ///COMPARAR i COM i+1
        set<string> l = Tag[s[i  ].first];{
            if(s[i].second != -1)
                for(const auto& it:Tag[s[i].second])
                    l.insert(it);
        }
        set<string> r = Tag[s[i+1].first];{
        if(s[i+1].second != -1)
            for(const auto& it:Tag[s[i+1].second])
                r.insert(it);
        }
        NUMT intersect = 0;
        for(const auto& it:l)
            if(r.find(it) != r.end())
                ++intersect;
        NUMT score = min((NUMT)intersect,
                     min((NUMT)l.size()-intersect,
                         (NUMT)r.size()-intersect));
        ret += score;
    }
    return ret;
}

int main(){
    cin >> N;
    for(NUMT i = 0; i < N; ++i){
        cin >> Dir[i];
        NUMT sz; cin >> sz;
        for(NUMT j = 0; j < sz; ++j){
            string s; cin >> s;
            Tag[i].insert(s);
        }
    }
    NUMT bestp = 0; vector<PNN> bests;
    NUMT     p = 0; vector<PNN>     s;
    for(NUMT i = 0; i < TRIALS; ++i){
        //cerr << "trial " << i << endl;
        s = make_trial();
        p = get_points(s);
        if(p > bestp){
            cerr << "NEW BEST: " << p << endl;
            bestp = p;
            bests = s;
        }
    }
    ///OUTPUT
    cout << bests.size() << endl;
    for(const auto& it:bests){
        cout << it.first;
        if(it.second != -1) cout << " " << it.second;
        cout << endl;
    }

    return 0;
}
