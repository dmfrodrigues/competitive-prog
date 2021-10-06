#include <bits/stdc++.h>

using namespace std;

string reversepolish(string s){
    stack<char> q;
    string ret = "";
    for(const char &c:s){
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
            q.push(c);
        }else if(c == ')'){
            ret += q.top(); q.pop();
        }else if(c != '('){
            ret += c;
        }
    }
    return ret;
}

int main(){
    long t; cin >> t;
    for(long i = 0; i < t; ++i){
        string s; cin >> s;
        cout << reversepolish(s) << endl;
    }
    return 0;
}
