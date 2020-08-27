#include <bits/stdc++.h>

using namespace std;

string smallestpalindrome(string s_in){
    string s = s_in.substr(0, s_in.size()/2 + s_in.size()%2);
    string rig_s;
    if(s_in.size()%2 == 0) rig_s = s;
    else                   rig_s = s.substr(0, s.size()-1);
    reverse(rig_s.begin(), rig_s.end());
    string ret = s+rig_s;
    if(ret.size() > s_in.size() || ret > s_in) return ret;


    for(int i = s.size()-1; i >= 0; --i){
        if(s[i] == '9'){ s[i] = '0'; }
        else           { s[i] += 1; break; }
    }
    if(s[0] == '0'){
        return "1"+string(s_in.size()-1, '0')+"1";
    }
    if(s_in.size()%2 == 0) rig_s = s;
    else                   rig_s = s.substr(0, s.size()-1);
    reverse(rig_s.begin(), rig_s.end());
    return s+rig_s;
}

int main(){
    long t; cin >> t;
    for(long i = 0; i < t; ++i){
        string s; cin >> s;
        cout << smallestpalindrome(s) << endl;
    }
    return 0;
}
