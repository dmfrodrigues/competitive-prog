/*
ID: dmfrodr1
TASK: dualpal
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

string digit = "0123456789";

string repr(int n, int b){
    deque<char> s;
    while(n){
        s.push_back(digit[n%b]);
        n /= b;
    }
    return string(s.rbegin(), s.rend());
}

bool ispal(int n, int b){
    string s1 = repr(n, b);
    string s2 = s1; reverse(s2.begin(), s2.end());
    return (s1 == s2);
}

int main(){
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");

    int N, S;
    fin >> N >> S;
    while(N > 0){
        ++S;
        int counter = 0;
        for(int b = 2; b <= 10; ++b)
            if(ispal(S, b)) ++counter;
        if(counter >= 2){
            fout << S << endl;
            --N;
        }
    }



    return 0;
}
