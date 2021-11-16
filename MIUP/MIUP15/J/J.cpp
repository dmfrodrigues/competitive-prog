#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define FOR(i,b,e) for(lli (i) = (b); (i) < lli(e); ++(i))
typedef vector<lli> VI;

class VEC{
public:
    lli x, y;
    VEC(lli x = 0, lli y = 0):x(x),y(y){}
    static int quad(lli x, lli y){
        if     (x >  0 && y == 0) return 0;
        else if(x >  0 && y >  0) return 1;
        else if(x == 0 && y >  0) return 2;
        else if(x <  0 && y >  0) return 3;
        else if(x <  0 && y == 0) return 4;
        else if(x <  0 && y <  0) return 5;
        else if(x == 0 && y <  0) return 6;
        else if(x >  0 && y <  0) return 7;
        return -1;
    }
    bool operator<(const VEC &a)const{
        int q1 = quad(  x,   y);
        int q2 = quad(a.x, a.y);
        if(q1 != q2) return (q1 < q2);
        else{
            if(q1%2 == 0) return true;
            else{
                if(q1 == 1 || q1 == 5) return (y*a.x < a.y*x);
                else                   return (y*a.x > a.y*x);
            }
        }
    }
};

bool tilt_same(const VEC &v1, const VEC &v2){
    return (v1.x*v2.x >= 0 && v1.y*v2.y >= 0 && v1.x*v2.y == v2.x*v1.y);
}

int main(){
    lli N; cin >> N;
    lli x, y, x_p, y_p;
    vector<VEC> p(N);
    vector<VEC> v(N-1);
    cin >> x >> y;
    p[0] = VEC(x,y);
    FOR(i,0,N-1){
        x_p = x; y_p = y;
        cin >> x >> y;
        v[i] = VEC(x-x_p, y-y_p);
        p[i+1] = VEC(x,y);
    }
    FOR(i,0,v.size()-1){
        vector<VEC> w(v.begin(), v.end()-i);
        stable_sort(w.begin(), w.end());
        deque<VEC> x; x.push_back(w[0]);
        FOR(j,1,w.size()){
            if(!tilt_same(x.back(), w[j])){
                x.push_back(w[j]);
            }
        }
        x.push_back(x.front());
        FOR(j, 0, x.size()-1){
            const VEC &v1 = x[j], &v2 = x[j+1];
            if(v1.x*v2.y-v1.y*v2.x <= 0){
                if(i == 0){
                    cout << v1.x << " " << v1.y << " " << v2.x << " " << v2.y << endl;
                }else{
                    cout << p[N-i].x << " " << p[N-1].y << endl;
                }
                return 0;
            }
        }
    }
    return 0;
}
