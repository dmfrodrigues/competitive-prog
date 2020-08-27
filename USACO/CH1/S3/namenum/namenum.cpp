/*
ID: dmfrodr1
TASK: namenum
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;

unordered_set<string> dict;
void getdict(){
    ifstream din("dict.txt");
    string s;
    while(din >> s) dict.insert(s);
}

const vector< vector<char> > keys = {{},
                                     {},
                                     {'A','B','C'},
                                     {'D','E','F'},
                                     {'G','H','I'},
                                     {'J','K','L'},
                                     {'M','N','O'},
                                     {'P','R','S'},
                                     {'T','U','V'},
                                     {'W','X','Y'}};
vector<int> v;
queue<string> q;

void makequeue(string s){
    int i = s.size();
    if(i == v.size()){
        if(dict.find(s) != dict.end())
            q.push(s);
    }else{
        string s1 = s+keys[v[i]][0],
               s2 = s+keys[v[i]][1],
               s3 = s+keys[v[i]][2];
        makequeue(s1);
        makequeue(s2);
        makequeue(s3);
    }
}

void processqueue(){
    int N = q.size();
    for(int i = 0; i < N; ++i){
        string s = q.front(); q.pop();
        if(dict.find(s) != dict.end()) q.push(s);
    }
}

int main(){
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    getdict();

    string s; fin >> s;
    v = vector<int>(s.size());
    for(int i = 0; i < v.size(); ++i)
        v[i] = s[i] - '0';

    makequeue("");

    if(q.empty()){
        fout << "NONE" << endl;
    }else{
        while(!q.empty()){
            fout << q.front() << endl;
            q.pop();
        }
    }

    return 0;
}
