#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli solve(string str){

    lli ret = 0;

    deque<char> str_changed;
    for(const auto& c:str){
        if(c == '{'){
            str_changed.push_back('{');
        }else{
            if(!str_changed.empty() && str_changed.back() == '{') str_changed.pop_back();
            else                                                  str_changed.push_back('}');
        }
//        for(const auto& c:str_changed) cout << c; cout << endl;
    }

    lli L = count(str_changed.begin(), str_changed.end(), '}');
    lli R = count(str_changed.begin(), str_changed.end(), '{');
    lli l = L/2; L -= 2*l; ret += l;
    lli r = R/2; R -= 2*r; ret += r;

    if(L == 1 && R == 1){
        R -= 1; L -= 1;
        ret += 2;
    }

    return ret;

}

int main(){

/*
{}}{}{}{{{}}{}
=>}{

*/

    string str = "";
    deque<char> dqe;
    lli ans = 0;
    for(int i = 1; true; ++i){
        cin >> str;
        dqe.clear();

        if(str[0] == '-') break;

        ans = solve(str);

        cout << i << ". " << ans << endl;
    }

    return 0;
}
