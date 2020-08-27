#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

lli VAL(const char& c){
    switch(c){
        case 'H': return  1; break;
        case 'C': return 12; break;
        case 'O': return 16; break;
        default: return 0; break;
    }
}

lli solve(const string& str){
    deque<lli> dqe;
    dqe.push_back(0);

    lli ans;
    for(lli i = 0; i < str.size(); ++i){
        if(str[i] == 'H') dqe.back() += VAL('H');
        if(str[i] == 'C') dqe.back() += VAL('C');
        if(str[i] == 'O') dqe.back() += VAL('O');
        if('1' <= str[i] && str[i] <= '9'){
            ans = str[i]-'0';
            dqe.back() += (ans-1)*VAL(str[i-1]);
        }

        if(str[i] == '('){
            dqe.push_back(0);
        }
        if(str[i] == ')'){
            if(i+1 < str.size() && '1' <= str[i+1] && str[i+1] <= '9') dqe.back() *= (str[i+1]-'0');
            ans = dqe.back();
            dqe.pop_back();
            dqe.back() += ans;
        }
    }
    return dqe[0];

}

int main(){
    string str; cin >> str;
//    string str = "";
//    for(int i = 0; i < 5; ++i) str += "H(";
//    str += "H";
//    for(int i = 0; i < 5; ++i) str += ")";

    lli dummy;
    lli ans = solve(str);
    cout << ans << endl;
    return 0;
}
