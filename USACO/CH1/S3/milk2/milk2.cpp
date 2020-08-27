/*
ID: dmfrodr1
TASK: milk2
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

struct STATUS{
    int x;
    bool f;
    bool operator<(const STATUS& obj)const{
        if(this->x != obj.x) return (this->x < obj.x);
        else                 return (this->f > obj.f);
    }
};

multiset<STATUS> s;

void reduce(){
    int counter = 0;
    auto it = s.begin();
    while(it != s.end()){
        if(it->f){
            if(counter != 0) it = s.erase(it);
            else             ++it;
            ++counter;
        }else{
            if(counter != 1) it = s.erase(it);
            else             ++it;
            --counter;
        }
    }

    it = s.begin();
    auto it_ = it; ++it_;
    while(it_ != s.end()){
        if(it->x == it_->x && it->f != it_->f){
            s.erase(it_);
            it = s.erase(it);
            --it;
            it_ = it; ++it_;
        }else{
            ++it; ++it_;
        }
    }
}

int main(){
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");
    int N; fin >> N;
    int l, r;
    for(int i = 0; i < N; ++i){
        fin >> l >> r;
        s.insert({l, true});
        s.insert({r, false});
    }

    cout << "s: "; for(const auto& i:s) cout << "(" << i.x << "," << i.f << ") "; cout << endl;

    reduce();

    cout << "s: "; for(const auto& i:s) cout << "(" << i.x << "," << i.f << ") "; cout << endl;
    vector<STATUS> v(s.begin(), s.end());
    int yes = 0;
    int no = 0;
    for(int i = 0; i < v.size()-1; ++i){
        if(v[i].f) yes = max(yes, v[i+1].x-v[i].x);
        else       no  = max(no , v[i+1].x-v[i].x);
    }
    fout << yes << " " << no << endl;


    return 0;
}
