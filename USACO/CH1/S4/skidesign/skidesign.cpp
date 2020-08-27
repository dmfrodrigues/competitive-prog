/*
ID: dmfrodr1
TASK: skidesign
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> h;

int main(){
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");

    int N; fin >> N;
    h = vector<int>(N);
    for(auto& i:h) fin >> i;

    int best = 100000000, c, d;
    for(int lo = 0, hi = 17; hi <= 100; ++lo, ++hi){
        c = 0;
        for(auto i:h){
            if(i < lo){
                d = lo-i;
                c += d*d;
            }else if(hi < i){
                d = i-hi;
                c += d*d;
            }
        }
        best = min(best, c);
    }

    fout << best << endl;

    return 0;
}
