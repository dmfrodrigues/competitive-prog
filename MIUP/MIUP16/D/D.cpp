#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i)=(b); (i) < lli(e); (i)++)
typedef vector<lli>   VI;
#define X first
#define Y second
#define ALL(v) (v).begin(), (v).end()
#define INF 2000000005L

struct PII{
    lli X;
    lli Y;
    int F;
    bool operator<(const PII &obj)const{
        if(X != obj.X) return (X < obj.X);
        else           return (Y < obj.Y);
    }
};

auto compy = [](PII lhs, PII rhs){ //LAMBDA FUNCTION
	swap(lhs.X, lhs.Y); swap(rhs.X, rhs.Y); return (lhs < rhs);
};
lli dist(PII a, PII b){ //DISTANCE FUNCTIONS [Default: Euclidian squared (Dx²+Dy²)]
	return abs(a.X-b.X)+abs(a.Y-b.Y);
}

lli closestpair(vector<PII> pt){
	sort(ALL(pt));
	lli d = INF;
	set<PII,decltype(compy)> sy(compy); queue<PII> sx;
	FOR(i,1,pt.size()){
		sy.insert(pt[i-1]); sx.push(pt[i-1]);
		while(!sx.empty() && sx.front().X < pt[i].X - d){
			sy.erase(sx.front()); sx.pop();
		}
		auto it = sy.lower_bound({pt[i].X-d, pt[i].Y-d});
		while(it != sy.end() && it->Y <= pt[i].Y+d){
			lli newd = dist(pt[i], *it);
			if(newd < d && pt[i].F != it->F){ d = newd; } ++it;
		}
	} return d;
}

int main(){
    lli N; cin >> N;
    vector<PII> pt(N);
    for(PII &p:pt){
        cin >> p.X >> p.Y >> p.F;
    }
    lli distance = closestpair(pt);
    cout << distance << endl;
    return 0;
}
