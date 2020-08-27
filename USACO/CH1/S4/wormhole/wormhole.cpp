/*
ID: dmfrodr1
TASK: wormhole
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

struct PT{
    int x, y;
    bool operator<(const PT& obj)const{
        if(this->x != obj.x) return (this->x < obj.x);
        else                 return (this->y < obj.y);
    }
};

int N;
deque<PT> v;
deque<int> q;
int c = 0;

void checkloop(deque<int> d){
    //cout << endl;
    //for(auto i:d) cout << i << " "; cout << endl;
    map<PT, PT> m;{
        deque<PT> p = v;
        for(auto i:d){
            m[p[0]] = p[i];
            m[p[i]] = p[0];
            p.erase(p.begin()+i);
            p.erase(p.begin());
        }
    //for(auto i:m) cout << "(" << i.first.x << "," << i.first.y << ")->(" << i.second.x << "," << i.second.y << ")" << endl;
    }
    for(auto startfrom:v){
        //cout << "startfrom=" << startfrom.x << "," << startfrom.y << endl;
        map<PT, bool> visited;{
            for(auto i:v) visited[i] = false;
        }
        bool isloop;
        PT cur = startfrom;
        while(true){
            //cout << "cur1=" << cur.x << "," << cur.y << endl;
            if(visited[cur]){ ++c; /*cout << "++c" << endl;*/ return; }
            visited[cur] = true;
            cur = m[cur];
            //cout << "cur2=" << cur.x << "," << cur.y << endl;
            if(cur.x == q[cur.y]-1){ break;  }
            else                   { ++cur.x; }
        }
    }
}

void recursive(deque<int> d){
    if(d.size() == N/2){
        checkloop(d);
    }else{
        int n = N - 2*d.size();
        deque<int> t;
        for(int i = 1; i < n; ++i){
            t = d; t.push_back(i);
            recursive(t);
        }
    }
}

int main(){
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");

    fin >> N;
    {

        map< int, set<int> > m;
        for(int x, y, i = 0; i < N; ++i){
            fin >> x >> y;
            m[y].insert(x);
        }
        for(const auto& y:m){
            if(y.second.empty()) continue;
            q.push_back(y.second.size());
            for(int i = 0; i < y.second.size(); ++i){
                v.push_back({i, (int)q.size()-1});
            }
        }
    }
    //for(const auto& i:v) cout << "(" << i.x << "," << i.y << ") "; cout << endl;
    //for(int i = 0; i < q.size(); ++i) cout << "y=" << i << ", #=" << q[i] << endl;
    deque<int> d;

    recursive(d);

    fout << c << endl;

    return 0;
}
