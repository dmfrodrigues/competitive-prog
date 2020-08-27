/*
ID: dmfrodr1
TASK: palsquare
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

int B;

string digit = "0123456789ABCDEFGHIJ";

string repr(int n){
    deque<char> s;
    while(n){
        s.push_back(digit[n%B]);
        n /= B;
    }
    return string(s.rbegin(), s.rend());
}

bool ispal(int n){
    string s1 = repr(n);
    string s2 = s1; reverse(s2.begin(), s2.end());
    return (s1 == s2);
}

int main(){
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");

    fin >> B;
    for(int i = 1; i <= 300; ++i){
        if(ispal(i*i)){
            fout << repr(i) << " " << repr(i*i) << endl;
        }
    }


    return 0;
}
