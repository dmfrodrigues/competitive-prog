#include<bits/stdc++.h>
#define NUMT long
#define MAXN 100005
using namespace std;
typedef pair<NUMT,NUMT> PNN;

const NUMT TRIALS = 20;

NUMT N;
char Dir[MAXN];
set<string> Tag[MAXN];

struct vert{
    NUMT ph1;
    NUMT ph2;
    NUMT sz;
    bool operator<(const vert& obj)const{
        return (this->sz < obj.sz);
    }
};

NUMT get_intersection(const set<string>& s1, const set<string>& s2){
    NUMT ret = 0;
    for(const auto& it:s1)
        if(s2.find(it) != s2.end()) ++ret;
    return ret;
}

vector<vert> pair_vertical(deque<NUMT> V){
    deque<vert> ret(V.size()/2);
    set<vert> S;
    for(NUMT i = 0; i < V.size(); ++i){
        //cerr << "i=" << i << endl;
        for(NUMT j = i+1; j < V.size(); j++){
            S.insert({i, j, get_intersection(Tag[V[i]], Tag[V[j]])});
        }
    }

    vector<bool> valid(V.size(), true);
    for(const auto& it:S){
        if(valid[it.ph1] && valid[it.ph2]){
            NUMT value = Tag[V[it.ph1]].size() + Tag[V[it.ph2]].size() - it.sz;
            ret.push_back({V[it.ph1], V[it.ph2], value});
            valid[it.ph1] = false;
            valid[it.ph2] = false;
        }
    }

    return vector<vert>(ret.begin(), ret.end());
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

    sort(V.rbegin(), V.rend(), cmp);

    //cerr << "L61" << endl;


    vector<vert> VERT = pair_vertical(V);



        //cerr << "L71" << endl;
    deque<vert> evry(VERT.begin(), VERT.end());
    for(const auto& it:H)
        evry.push_back({it, -1, (NUMT)Tag[it].size()});
    sort(evry.begin(), evry.end());

    const NUMT RNG = 100; const NUMT STEP = 50;
    //cerr << "L55" << endl;
    for(NUMT i = 0; i <= evry.size()-RNG; i += STEP){ //cerr << "L56, i=" << i << ", " << evry.size() << endl;
        shuffle(evry.begin()+i, evry.begin()+i+RNG, default_random_engine(rand()));
    }
    //cerr << "L59" << endl;
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
