#include <bits/stdc++.h>
using namespace std;
typedef long unsigned uli;
typedef long long unsigned ulli;
typedef pair<ulli,ulli> PUU;
#define ALL(v) (v).begin(),(v).end()

template<class T>
class rope{
public:
    typedef T (*FCN)(const T&, const T&);
    typedef T (*FCN_MAP)(char c);
    static T NEUTRAL;
    static FCN f;
    static FCN_MAP f_map;
private:
    const rope *cl = NULL, *cr = NULL; bool del; char c;
    ulli s; T val = NEUTRAL;

    rope(const rope *cl, const rope *cr):cl(cl),cr(cr),del(true){
        s = cl->s+cr->s;
        val = f(cl->val, cr->val);
    }
    rope(char c):del(false),c(c),s(1){
        val = f_map(c);
    }
public:
    rope():cl(NULL),cr(NULL),del(false),s(0),val(NEUTRAL){}
    rope(string::const_iterator a, string::const_iterator b){
        if     (b-a <= 0) *this = rope();
        else if(b-a == 1) *this = rope(*a);
        else{
            cl = new rope(a, a+(b-a)/2); cr = new rope(a+(b-a)/2, b); del = true;
            s = cl->s + cr->s; val = f(cl->val, cr->val);
        }
    }
    ~rope(){ if(del){ delete cl; delete cr; } }
    ulli size() const{ return s; }
    T query(ulli l, ulli r){
        assert(l <= r); assert(r <= s);
        if(l == 0 && r == s) return val;
        return NEUTRAL;
    }
    rope* substr(ulli l, ulli r) const{
        assert(l <= r); assert(r <= s);
        if(l == r) return new rope();
        if(l == 0 && r == s){
            rope *ret = new rope(*this);
            ret->del = false;
            return ret;
        }
        if(r <= cl->s) return cl->substr(l      , r      );
        if(cl->s <= l) return cr->substr(l-cl->s, r-cl->s);
        rope *ncl = cl->substr(l, cl->s  );
        rope *ncr = cr->substr(0, r-cl->s);
        return new rope(ncl, ncr);
    }
    rope* concat(const rope *p) const{
        rope *ret = NULL;
        if     (   s == 0) ret = new rope(*p);
        else if(p->s == 0) ret = new rope(*this);
        else               ret = new rope(this, p);
        ret->del = false; return ret;
    }
};

struct COM{
    bool SUB;
    ulli x, y, lo, hi;
};

const ulli MOD = 1000000007;
template<>      ulli           rope<ulli>::NEUTRAL = 0;
template<> rope<ulli>::FCN     rope<ulli>::f       = [](const ulli &a, const ulli &b){ return (a+b)%MOD; };
template<> rope<ulli>::FCN_MAP rope<ulli>::f_map   = [](char c){ return ulli(c); };
    
int main(){
    int N; cin >> N;
    vector< rope<ulli>* > v(N,NULL);
    string s; cin >> s; v[0] = new rope<ulli>(ALL(s));
    uli x, y; ulli lo, hi; 
    for(int i = 1; i < N; ++i){
        cin >> s;
        if(s == "SUB"){
            cin >> x >> lo >> hi;
            v[i] = v[x]->substr(lo, hi);
        }else{
            cin >> x >> y;
            v[i] = v[x]->concat(v[y]);
        }
    }
    cout << v[N-1]->query(0, v[N-1]->size()) << endl;
    for(rope<ulli> *p:v) delete p;
    return 0;
}