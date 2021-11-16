#include<bits/stdc++.h>
#define NUMT long
#define MAXN 100005
using namespace std;
typedef pair<NUMT,NUMT> PNN;

const NUMT TRIALS = 10;

NUMT N;
char Dir[MAXN];
set<string> Tag[MAXN];



vector<PNN> make_trial(){
    deque<NUMT> H, V;
    for(NUMT i = 0; i < N; ++i){
        if(Dir[i] == 'H') H.push_back(i);
        else              V.push_back(i);
    }



    shuffle(H.begin(), H.end(), default_random_engine(rand()));
    shuffle(V.begin(), V.end(), default_random_engine(rand()));



    vector<PNN> ans;
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
