/*
ID: dmfrodr1
TASK: ride
LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int getnum(string s){
    int ans = 1;
    for(auto c:s){
        ans *= c-'A'+1;
    }
    return ans;
}

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    string s1, s2;
    fin >> s1 >> s2;
    if(getnum(s1)%47 == getnum(s2)%47){
        fout << "GO" << endl;
    }else{
        fout << "STAY" << endl;
    }
    return 0;
}
