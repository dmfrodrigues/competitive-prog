#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
typedef vector<bool>            VB;
typedef vector<VB>              VVB;
typedef pair< lli, lli>         PII;
typedef pair<ulli,ulli>         PUU;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second
const lli INF = 1000000000;

struct node_t {
    string p;
    list<string> children;
    bool played;
    bool marked = false;
};

unordered_map<string, node_t> nodes;

bool mark(const string &id){
    if(nodes.at(id).played){
        nodes.at(id).marked = true;
        return true;
    }
    return false;
}

bool markChildren(const string &id){
    bool ret = false;
    const list<string> &children = nodes.at(id).children;
    for(const string &child: children) ret = ret || mark(child);
    return ret;
}

bool markGrandchildren(const string &id){
    bool ret = false;
    const list<string> &sons = nodes.at(id).children;
    for(const string &son: sons) ret = ret || markChildren(son);
    return ret;
}

bool markFather(const string &id){
    string father = nodes.at(id).p; if(father == "") return false;
    return mark(father);
}

bool markGrandfather(const string &id){
    string father = nodes.at(id).p; if(father == "") return false;
    return markFather(father);
}

bool markUncles(const string &id){
    bool ret = false;
    string father = nodes.at(id).p; if(father == "") return false;
    string grandfather = nodes.at(father).p; if(grandfather == "") return false;
    const list<string> uncles = nodes.at(grandfather).children;
    for(const string &uncle: uncles){
        if(uncle != father){
            ret = ret || mark(uncle);
        }
    }
    return ret;
}

bool markCousins(const string &id){
    bool ret = false;
    string father = nodes.at(id).p; if(father == "") return false;
    string grandfather = nodes.at(father).p; if(grandfather == "") return false;
    const list<string> uncles = nodes.at(grandfather).children;
    for(const string &uncle: uncles) if(uncle != father) ret = ret || mark(uncle);
    return ret;
}

bool markFirstCousinsOnceRemoved(const string &id){
    bool ret = false;
    string father = nodes.at(id).p; if(father == "") return false;
    string grandfather = nodes.at(father).p; if(grandfather == "") return false;
    const list<string> uncles = nodes.at(grandfather).children;
    for(const string &uncle: uncles) if(uncle != father) ret = ret || markGrandchildren(uncle);
    return ret;
}

bool markGreatgrandchildren(const string &id){
    bool ret = false;
    const list<string> &sons = nodes.at(id).children;
    for(const string &son: sons) ret = ret || markGrandchildren(son);
    return ret;
}

bool markBrothers(const string &id){
    bool ret = false;
    string father = nodes.at(id).p; if(father == "") return false;
    const list<string> &brothers = nodes.at(father).children;
    for(const string &brother: brothers) if(brother != id) ret = ret || mark(brother);
    return ret;
}

int main(){
    int N; cin >> N;
    string name, str;
    bool first = true;
    FOR(i,0,N){
        cin >> name;

        if(first) nodes[name].played = true;
        first = false;
        
        getline(cin, str);
        stringstream ss(str);
        string childName;
        bool hasPlayed;
        while(ss >> childName >> hasPlayed){
            nodes[name].children.push_back(childName);
            nodes[childName].p = name;
            nodes[childName].played = hasPlayed;
        }
    }

    /*
    for(const auto &p: nodes){
        cout << p.first << ":" << p.second.played << ", son of " << p.second.p << ", father of";
        for(const string &s: p.second.children) cout << " " << s;
        cout << endl;
    }
    */

    for(auto &p: nodes){
        const string &id = p.first;
        node_t &u = p.second;
        if(u.played){
            if(markBrothers(id)) u.marked = true;
            if(markFather(id)) u.marked = true;
            if(markUncles(id)) u.marked = true;
            if(markCousins(id)) u.marked = true;
            if(markFirstCousinsOnceRemoved(id)) u.marked = true;
            if(markGrandfather(id)) u.marked = true;
        }
    }

    size_t sol = 0;
    for(const auto &p: nodes)
        if(p.second.marked)
            ++sol;
    cout << sol << endl;

    return 0;
}
