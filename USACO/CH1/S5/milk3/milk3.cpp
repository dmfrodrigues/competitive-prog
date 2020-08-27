/*
ID: dmfrodr1
TASK: milk3
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

struct TRI{
    int a, b, c;
    bool operator<(const TRI& obj)const{
        if     (this->a != obj.a) return (this->a < obj.a);
        else if(this->b != obj.b) return (this->b < obj.b);
        else                      return (this->c < obj.c);
    }
};

int A, B, C;
set<TRI> s;

void update_s(){
    int pour;
    TRI t;
    for(auto it = s.begin(); it != s.end(); ++it){
        //a->b
        pour = min(it->a, B-it->b); t = *it; t.a -= pour; t.b += pour; s.insert(t);
        //a->c
        pour = min(it->a, C-it->c); t = *it; t.a -= pour; t.c += pour; s.insert(t);
        //b->a
        pour = min(it->b, A-it->a); t = *it; t.b -= pour; t.a += pour; s.insert(t);
        //b->c
        pour = min(it->b, C-it->c); t = *it; t.b -= pour; t.c += pour; s.insert(t);
        //c->a
        pour = min(it->c, A-it->a); t = *it; t.c -= pour; t.a += pour; s.insert(t);
        //c->b
        pour = min(it->c, B-it->b); t = *it; t.c -= pour; t.b += pour; s.insert(t);
    }
}

int main(){
    ///INPUT
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");

    fin >> A >> B >> C;

    int prev = 0;
    s.insert({0, 0, C});
    do{
        prev = s.size();
        update_s();
    }while(prev != s.size());

    set<int> ans;
    for(const auto& it:s){
        if(it.a == 0) ans.insert(it.c);
    }
    bool first = true;
    for(const auto& it:ans){
        if(first){ fout << it; first = false; }
        else     { fout << " " << it;         }
    }fout << endl;

    return 0;
}
