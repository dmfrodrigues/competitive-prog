#include <bits/stdc++.h>
using namespace std;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(int i =(b); (i)  < (int)(e); ++(i))
typedef vector<int>             VI;
typedef vector<VI>              VVI;
typedef pair< int, int>         PII;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second

auto compy = [](PII lhs, PII rhs){ //LAMBDA FUNCTION
	if(lhs.Y != rhs.Y) return (lhs.Y < rhs.Y);
	return (lhs.X < rhs.X);
};

double dist(PII a, const PII &b){ //DISTANCE FUNCTIONS [Default: Euclidian squared (DxÂ²+DyÂ²)]
	a.X -= b.X; a.Y -= b.Y;
	return sqrt(a.X*a.X + a.Y*a.Y);
}

PPP closestpair(vector<PII> pt){
	sort(ALL(pt));
	PPP p; double dmin = 1e20;
	set<PII, decltype(compy)> box(compy);
	box.insert(pt[0]); size_t l = 0;
	FOR(i,1,pt.size()){
		while(l < i && pt[i].X-pt[l].X > dmin) box.erase(pt[l++]);
		auto it = box.lower_bound(PII(pt[i].X-dmin, pt[i].Y-dmin));
		while(it != box.end() && pt[i].Y+dmin > it->Y){
			auto d = dist(pt[i], *it);
			if(d < dmin){ dmin = d; p = PPP(*it, pt[i]); } it++;
		}
		box.insert(pt[i]);
	}
	return p;
}

int main(){
	int N; cin >> N;
	vector<PII> pt(N);
	FOR(i,0,N) cin >> pt[i].X >> pt[i].Y;
	PPP ans = closestpair(pt);
	int a = find(pt.begin(), pt.end(), ans.first) - pt.begin();
	int b = find(pt.begin(), pt.end(), ans.second) - pt.begin();
	if(a > b) swap(a,b);
	cout << a << " " << b << " ";
	cout << fixed << setprecision(6) << dist(ans.first, ans.second);
}
