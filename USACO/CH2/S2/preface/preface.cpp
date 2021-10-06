/*
ID: dmfrodr1
TASK: preface
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,b,e) for(int (i) = (b); (i) < (e); ++(i))

string arab2roman(int i){
    string ret = "";
    if(i){//unidades
        switch(i%10){
            case 1: ret = "I"   +ret; break;
            case 2: ret = "II"  +ret; break;
            case 3: ret = "III" +ret; break;
            case 4: ret = "IV"  +ret; break;
            case 5: ret = "V"   +ret; break;
            case 6: ret = "VI"  +ret; break;
            case 7: ret = "VII" +ret; break;
            case 8: ret = "VIII"+ret; break;
            case 9: ret = "IX"  +ret; break;
            default:                  break;
        }
        i /= 10;
    }else return ret;
    if(i){//dezenas
        switch(i%10){
            case 1: ret = "X"   +ret; break;
            case 2: ret = "XX"  +ret; break;
            case 3: ret = "XXX" +ret; break;
            case 4: ret = "XL"  +ret; break;
            case 5: ret = "L"   +ret; break;
            case 6: ret = "LX"  +ret; break;
            case 7: ret = "LXX" +ret; break;
            case 8: ret = "LXXX"+ret; break;
            case 9: ret = "XC"  +ret; break;
            default:                  break;
        }
        i /= 10;
    }
    if(i){//centenas
        switch(i%10){
            case 1: ret = "C"   +ret; break;
            case 2: ret = "CC"  +ret; break;
            case 3: ret = "CCC" +ret; break;
            case 4: ret = "CD"  +ret; break;
            case 5: ret = "D"   +ret; break;
            case 6: ret = "DC"  +ret; break;
            case 7: ret = "DCC" +ret; break;
            case 8: ret = "DCCC"+ret; break;
            case 9: ret = "CM"  +ret; break;
            default:                  break;
        }
        i /= 10;
    }
    if(i){//milhares
        switch(i%10){
            case 1: ret = "M"   +ret; break;
            case 2: ret = "MM"  +ret; break;
            case 3: ret = "MMM" +ret; break;
            default:                  break;
        }
        i /= 10;
    }
    return ret;
}

int main(){
    ///INPUT
    ifstream fin("preface.in");
    ofstream fout("preface.out");
    int N; fin >> N;
    deque<string> d;
    FOR(i,1,N+1) d.push_back(arab2roman(i));
    map<char,int> m;
    m['I'] = 0; m['V'] = 0; m['X'] = 0;
    m['L'] = 0; m['C'] = 0; m['D'] = 0;
    m['M'] = 0;
    for(const string &s:d)
        for(const char &c:s)
            ++m[c];
    if(m['I']) fout << "I " << m['I'] << endl;
    if(m['V']) fout << "V " << m['V'] << endl;
    if(m['X']) fout << "X " << m['X'] << endl;
    if(m['L']) fout << "L " << m['L'] << endl;
    if(m['C']) fout << "C " << m['C'] << endl;
    if(m['D']) fout << "D " << m['D'] << endl;
    if(m['M']) fout << "M " << m['M'] << endl;

    return 0;
}
