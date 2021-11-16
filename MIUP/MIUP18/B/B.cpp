#include <bits/stdc++.h>
using namespace std;
#define FOR(i,b,e) for(int (i) = (b) ; (i) < int (e) ; (i)++ )
typedef vector<int> VI;

#define	NEXT()	L = i; while (R<n && str[R-L] == str[R]) R++; Z[i] = R-L; R--
VI z_arr(const string& str){
	int n = str.length(), L = 0, R = 0, k; VI Z(n);
	FOR(i,1,n){
		if(i > R){ R = NEXT(); }
		else{ k = i-L;
			if(Z[k] < R-i+1) Z[i] = Z[k]; else{ NEXT(); }
		}
	} return Z;
}

bool zsearch(string text, string pattern) {
	string concat = pattern + "$" + text;
	VI Z = z_arr(concat); VI ret;
	FOR(i, 0, concat.size()) if (Z[i] == (int)pattern.size()) return true;
	return false;
}

int main(){
    deque<string> v;{
        string s;
        while(cin >> s)
            v.push_back(s);
    }
    queue<string> q;
    string s = v[0];
    for(int w = s.size(); w > 0; --w)
        FOR(l, 0, (int)s.size()-w)
            q.push(s.substr(l, w));

    while(!q.empty()){
        bool in_all = true;
        string s = q.front(); q.pop();
        FOR(i, 1, v.size()){
            if(!zsearch(v[i], s)){
                in_all = false;
                break;
            }
        }
        if(in_all){
            cout << s.size() << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
