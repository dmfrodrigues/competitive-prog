/*
ID: dmfrodr1
TASK: friday
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;


bool isleap(int y){
    return !(y%4 != 0 || (y%100==0 && y%400 != 0));
}

int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int howmanydays(int y, int m){
    if(m != 1) return month[m];
    else{
        if(isleap(y)) return month[m]+1;
        else          return month[m];
    }
}

int main(){
    ifstream fin("friday.in");
    ofstream fout("friday.out");

    int N; fin >> N;
    int ndays = 0;
    vector<int> countdays(7,0); ///countdays[0] é segunda-feira
    for(int y = 1900; y <= 1900+N-1; ++y){
        //cerr << "y=" << y << endl;
        for(int m = 0; m < 12; ++m){
            //cerr << "m=" << m << endl;
            ++countdays[(ndays+13-1)%7];
            ndays += howmanydays(y, m);
        }
    }
    fout << countdays[5] << " " << countdays[6];
    for(int i = 0; i < 5; ++i) fout << " " << countdays[i];
    fout << endl;

    return 0;
}
