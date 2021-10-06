#include <bits/stdc++.h>
using namespace std;
typedef long long unsigned ulli;
typedef long long int lli;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(int i =(b); (i)  < (int)(e); ++(i))
typedef vector<int>             VI;
typedef vector<VI>              VVI;
typedef pair<lli,lli>         PII;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second

bool compy(const PII &lhs, const PII &rhs){
	if(lhs.Y != rhs.Y) return (lhs.Y < rhs.Y);
	return (lhs.X < rhs.X);
}
lli dist_eucl2(PII a, const PII &b){
	a.X -= b.X; a.Y -= b.Y;
	return a.X*a.X + a.Y*a.Y;
}
double dist_eucl(PII a, const PII &b){
	a.X -= b.X; a.Y -= b.Y;
	return sqrt(a.X*a.X + a.Y*a.Y);
}

PPP closestpairDC(vector<PII> &pt, ulli l, ulli r){
	if(r-l <= 1) return PPP(pt[0], pt[1]);
	if(r-l == 2) return PPP(pt[l], pt[l+1]);
	ulli m = l + (r-l)/2;
    PPP pmin = closestpairDC(pt, l, m); auto dmin = dist_eucl2(pmin.first, pmin.second);
	PPP p    = closestpairDC(pt, m, r); auto d    = dist_eucl2(p   .first, p   .second); if(d < dmin){ dmin = d; pmin = p; }
	const PII &mid = pt[m];
	ulli ls = m; while(ls > l && ((pt[ls].X - mid.X)*(pt[ls].X - mid.X) < dmin)) --ls;
	ulli rs = m; while(rs < r && ((pt[rs].X - mid.X)*(pt[rs].X - mid.X) < dmin)) ++rs;
	sort(pt.begin()+ls, pt.begin()+rs, compy);
	FOR(i, ls, rs) FOR(j, i+1, rs){
		const auto &pi = pt[i], &pj = pt[j];
		if((pj.Y - pi.Y)*(pj.Y - pi.Y) > dmin) break;
		auto d = dist_eucl2(pi, pj);
		if(d < dmin){ dmin = d; pmin = PPP(pi, pj); }
	}
	sort(pt.begin()+ls, pt.begin()+rs); return pmin;
}
PPP closestpairDC(vector<PII> pt){
	sort(ALL(pt));
	return closestpairDC(pt, 0, pt.size());
}


int main(){
	int N; cin >> N;
	vector<PII> pt(N);
	FOR(i,0,N) cin >> pt[i].X >> pt[i].Y;
	PPP ans = closestpairDC(pt);
	int a = find(pt.begin(), pt.end(), ans.first) - pt.begin();
	int b = find(pt.begin(), pt.end(), ans.second) - pt.begin();
	if(a > b) swap(a,b);
	cout << a << " " << b << " ";
	cout << fixed << setprecision(6) << dist_eucl(ans.first, ans.second) << endl;
}
