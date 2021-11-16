/*
ID: dmfrodr1
TASK: combo
LANG: C++11
*/
#include <bits/stdc++.h>
#define FOR(i, b, e)    for(int (i) = (b) ; (i) != (e) ; ++(i) )
using namespace std;

int N;
int John[3];
int Mast[3];

bool isgood(int i, int j, int k){
    //cout << "(i,j,k)=" << i << " " << j << " " << k << endl;
    int d; bool b;
    b = true;
    d = abs(i-John[0]); d = min(d, N-d); if(d > 2) b = false;
    d = abs(j-John[1]); d = min(d, N-d); if(d > 2) b = false;
    d = abs(k-John[2]); d = min(d, N-d); if(d > 2) b = false;
    if(b) return true;
    b = true;
    d = abs(i-Mast[0]); d = min(d, N-d); if(d > 2) b = false;
    d = abs(j-Mast[1]); d = min(d, N-d); if(d > 2) b = false;
    d = abs(k-Mast[2]); d = min(d, N-d); if(d > 2) b = false;
    if(b) return true;
    return false;
}

int main(){
    ifstream fin("combo.in");
    ofstream fout("combo.out");

    fin >> N;
    fin >> John[0] >> John[1] >> John[2];
    fin >> Mast[0] >> Mast[1] >> Mast[2];

    int c = 0;
    FOR(i, 1, N+1) FOR(j, 1, N+1) FOR(k, 1, N+1){
        if(isgood(i,j,k)){
            //cout << "IS GOOD" << endl;
            ++c;
        }
    }

    fout << c << endl;

    return 0;
}
