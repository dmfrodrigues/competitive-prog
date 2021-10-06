/*
ID: dmfrodr1
TASK: milk
LANG: C++11
*/
#include <bits/stdc++.h>
#define MAXM 5005
using namespace std;

struct FARM{
    int p;
    int q;
    bool operator<(const FARM& obj)const{
        if(this->p != obj.p) return (this->p < obj.p);
        else                 return (this->q > obj.q);
    }
};
int N, M;
FARM m[MAXM];

int main(){
    ifstream fin("milk.in");
    ofstream fout("milk.out");

    fin >> N >> M;
    for(int i = 0; i < M; ++i)
        fin >> m[i].p >> m[i].q;

    sort(m, m+M);

    int c = 0;
    int i = 0;
    while(N){
        int reduce = min(N, m[i].q);
        N -= reduce;
        c += reduce*m[i].p;
        ++i;
    }
    fout << c << endl;

    return 0;
}
