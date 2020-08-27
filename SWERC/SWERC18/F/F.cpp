#include <bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(), (v).end()
typedef long long int lli;
#define INF 1000000000000000000

template<class F> lli tersearch(lli l, lli r, F f){
    lli l_, r_;
    while(l < r-1){
        l_ = l +   (r-l)/3;
        r_ = l + 2*(r-l)/3;
        if(f(l_) < f(r_)) l = l_+1;
        else              r = r_;
    } return l;
}

struct PT{
    lli X, Y, G;
    PT operator-()const{ return PT({-X, -Y, G}); }
    PT& operator-=(const PT &pt){ X-=pt.X; Y-=pt.Y; return *this; }
};
bool turns_counterclockwise(const PT &a, PT b, PT c){
    b -= a; c -= a;
    return (b.X*c.Y >= b.Y*c.X);
}
bool turns_clockwise(const PT &a, PT b, PT c){
    b -= a; c -= a;
    return (b.X*c.Y <= b.Y*c.X);
}

typedef vector<PT> VP;
VP v;

struct comp{
    const PT pt;
    comp(const PT &pt):pt(pt){}
    bool operator()(PT a, PT b) const{
        a -= pt; b -= pt;
        if(a.Y < 0) a = -a;
        if(b.Y < 0) b = -b;
        return a.X*b.Y > a.Y*b.X;
    }
};

struct func{
    const VP &w;
    const PT pt;
    func(const VP &w, lli i):w(w), pt(v[i]){}
    lli operator()(lli j){
        const PT &p = w[j];
        lli ret = 0;
        for(size_t i = 0; i < w.size(); ++i){
            if(turns_counterclockwise(pt, p, w[i])) ret += w[i].G;
            if(turns_clockwise       (pt, p, w[i])) ret -= w[i].G;
        }
        return -abs(ret);
    }
};

int main(){
    lli N; cin >> N;
    v = VP(N);
    for(PT &p:v) cin >> p.X >> p.Y >> p.G;
    lli ret = INF;
    for(lli i = 0; i < N; ++i){
        VP w;{
            w.insert(w.end(), v.begin(), v.begin()+i);
            w.insert(w.end(), v.begin()+i+1, v.end());
        }
        comp cmp(v[i]);
        sort(ALL(w), cmp);

        func f(w, i);

        //for(lli j = 0; j < w.size(); ++j) cout << "(" << w[j].X << "," << w[j].Y << ")[" << f(j) << "]\t";
        //cout << endl;

        lli sol = tersearch(0, N-1, f);
        ret = min(ret, -f(sol));
    }
    cout << ret << endl;
    return 0;
}
