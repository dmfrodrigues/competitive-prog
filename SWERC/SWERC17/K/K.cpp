#include <bits/stdc++.h>
using namespace std;
#define ALL(v)          (v).begin() , (v).end()
#define two(n)          ( 1 << (n) )
#define contain(Set,i)  ( (Set) & two(i) )
#define FOR(i,n)        for (lli i = 0; i < lli(n); i++)
#define REP(i, b, e)    for (lli i=b; i < lli(e); ++i)
typedef long long int lli;
typedef long double ld;
typedef pair<ld,ld> PLL;

typedef long long INT;
typedef pair<INT, INT> Point;

ld ld_abs(ld n){
    return (n >= 0.0L? n : -n);
}

typedef pair<lli, lli> point;
bool left_turn(point a, point b, point c) {
    return (a.first - c.first) * (b.second - c.second) -
           (a.second - c.second) * (b.first - c.first) > 0;
}
vector<point> convex_hull(vector<point> S) {
    sort(S.begin(), S.end());
    vector<point> top, bot;
    int t = 0, b = 0;
    for (point p : S) {
        while (t >= 2 && !left_turn(p, top[t-1], top[t-2])) {
            top.pop_back(); t--;
        } top.push_back(p); t++;
        while (b >= 2 && !left_turn(bot[b-2], bot[b-1], p)) {
            bot.pop_back(); b--;
        } bot.push_back(p); b++;
    }
	S.clear();
    for(int i = 0; i < lli(top.size()-1); ++i) S.push_back(top[i]);
    for(int i = bot.size()-1;      i > 0; --i) S.push_back(bot[i]);
    return S;
}


ld dist2(Point P, Point Q, Point R){
    Point A(R.first - P.first, R.second - P.second);
    Point B_(Q.first - P.first, Q.second - P.second);
    Point B(B_.second, -B_.first);
    ld a = A.first*B.first + A.second*B.second;
    ld b = B.first*B.first + B.second*B.second;
    return a*a/b;
}

ld solve(vector<Point> pts, lli initW){
    pts = convex_hull(pts);
    lli N = pts.size();
    if(N <= 2) return 0;
    ld bestW2 = ld(initW*initW)+lli(1);
    Point P, Q; lli r_, r = 2;
    ld W2, W2_;
    for(lli i = 0; i < N; ++i){ P = pts[i]; Q = pts[(i+1)%N];
        r_ = (r+1)%N;
        W2 = dist2(P, Q, pts[r]);
        W2_ = dist2(P, Q, pts[r_]);
        while(W2 < W2_){
            r = r_; r_ = (r+1)%N;
            W2 = W2_;
            W2_ = dist2(P, Q, pts[r_]);
        }
        if(i == 0 || W2 < bestW2) bestW2 = W2;
    }
    return sqrt(bestW2);
}

int main(){
    lli N; cin >> N;
    ld  R; cin >> R;
    vector<Point> pts(N);
    for(auto& p:pts)
        cin >> p.first >> p.second;
    ld ans = solve(pts, R);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
