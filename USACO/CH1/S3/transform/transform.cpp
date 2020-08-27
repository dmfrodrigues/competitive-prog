/*
ID: dmfrodr1
TASK: transform
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<char> VC;
typedef vector<VC> VVC;

int N;

void printme(VVC m){
    cout <<"printme" << endl;
    for(auto l:m){
        for(auto c:l) cout << c;
        cout << endl;
    }
}

void rotate90(VVC& ret){
    VVC m = ret;
    for(int l = 0; l < N; ++l)
        for(int c = 0; c < N; ++c)
            ret[c][N-1-l] = m[l][c];
}
void reflect(VVC& ret){
    for(int l = 0; l < N; ++l)
        for(int c = 0; c < N/2; ++c)
            swap(ret[l][c], ret[l][N-1-c]);
}

bool transform1(VVC m1, VVC m2){
    rotate90(m1);
    return (m1==m2);
}
bool transform2(VVC m1, VVC m2){
    rotate90(m1);
    rotate90(m1);
    return (m1==m2);
}
bool transform3(VVC m1, VVC m2){
    rotate90(m1);
    rotate90(m1);
    rotate90(m1);
    return (m1==m2);
}
bool transform4(VVC m1, VVC m2){
    reflect(m1);
    return (m1==m2);
}
bool transform5(VVC m1, VVC m2){
    reflect(m1);
    return (transform1(m1, m2) || transform2(m1, m2) || transform3(m1, m2));
}
bool transform6(VVC m1, VVC m2){
    return (m1 == m2);
}

int main(){
    ifstream fin("transform.in");
    ofstream fout("transform.out");
    fin >> N;
    VVC m1(N, VC(N));{
        for(int i = 0; i < N; ++i){
            string s; fin >> s;
            for(int j = 0; j < N; ++j)
                m1[i][j] = s[j];
        }
    }
    VVC m2(N, VC(N));{
        for(int i = 0; i < N; ++i){
            string s; fin >> s;
            for(int j = 0; j < N; ++j)
                m2[i][j] = s[j];
        }
    }
    if     (transform1(m1, m2)) fout << "1" << endl;
    else if(transform2(m1, m2)) fout << "2" << endl;
    else if(transform3(m1, m2)) fout << "3" << endl;
    else if(transform4(m1, m2)) fout << "4" << endl;
    else if(transform5(m1, m2)) fout << "5" << endl;
    else if(transform6(m1, m2)) fout << "6" << endl;
    else                        fout << "7" << endl;

    return 0;
}
