#include <bits/stdc++.h>
using namespace std;
#define ALL(v)          (v).begin() , (v).end()
#define two(n)          ( 1 << (n) )
#define contain(Set,i)  ( (Set) & two(i) )
#define FOR(i,n)        for(int (i) = 0; (i) < (n); ++(i))
#define REP(i, b, e)    for(auto (i)=(b); (i)!=(e); ++(i))
typedef long long int lli;
typedef vector<int> VI;
typedef pair<int,int> PII;
const int& INF = numeric_limits<int>::max();

struct POINT3{
    int x, y, z;
    bool operator<(const POINT3& obj)const{
        if     (this->x != obj.x) return (this->x < obj.x);
        else if(this->y != obj.y) return (this->y < obj.y);
        else                      return (this->z < obj.z);
    }
    bool operator!=(const POINT3& obj)const{
        return (x!=obj.x || y!=obj.y || z!=obj.z);
    }
};
map<POINT3, int> POINT3_int;
struct POINT2{ int x, y;
    POINT2(){}
    POINT2(const POINT3& obj){ this->x = obj.x; this->y = obj.y; }
    bool operator<(const POINT2& obj)const{
        if(this->x != obj.x) return (this->x < obj.x);
        else                 return (this->y < obj.y);
    }
    bool operator!=(const POINT2& obj)const{
        return (x!=obj.x || y!=obj.y);
    }
};
map<POINT2, int> POINT2_int;

bool hascycle(const vector< set<int> > &g, int source) {
	vector<int> dist(g.size(), INF);
	queue<int> q;
	dist[source] = 0; q.push(source);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		for (int e : g[cur]){
            if(dist[e] != INF && dist[e]+1 != dist[cur]) return true;
			if (dist[e] == INF){
				dist[e] = dist[cur] + 1;
				q.push(e);
			}
        }
	}
    return false;
}


int main(){
    ///INPUT
    int K; cin >> K;
    vector< set<int> > gPOINT3(2*K);
    vector< set<int> > gPOINT2(2*K);
    POINT3 pt3_1, pt3_2;
    POINT2 pt2_1, pt2_2;
    FOR(i, K){
        cin >> pt3_1.x >> pt3_1.y >> pt3_1.z;
        cin >> pt3_2.x >> pt3_2.y >> pt3_2.z;
        pt2_1 = POINT2(pt3_1);
        pt2_2 = POINT2(pt3_2);

        {auto it3_1 = POINT3_int.find(pt3_1);
        if(it3_1 == POINT3_int.end()) POINT3_int[pt3_1] = POINT3_int.size();}
        {auto it3_2 = POINT3_int.find(pt3_2);
        if(it3_2 == POINT3_int.end()) POINT3_int[pt3_2] = POINT3_int.size();}
        {auto it2_1 = POINT2_int.find(pt2_1);
        if(it2_1 == POINT2_int.end()) POINT2_int[pt2_1] = POINT2_int.size();}
        {auto it2_2 = POINT2_int.find(pt2_2);
        if(it2_2 == POINT2_int.end()) POINT2_int[pt2_2] = POINT2_int.size();}

        if(pt3_1 != pt3_2){
            gPOINT3[POINT3_int[pt3_1]].insert(POINT3_int[pt3_2]);
            gPOINT3[POINT3_int[pt3_2]].insert(POINT3_int[pt3_1]);
        }
        if(pt2_1 != pt2_2){
            gPOINT2[POINT2_int[pt2_1]].insert(POINT2_int[pt2_2]);
            gPOINT2[POINT2_int[pt2_2]].insert(POINT2_int[pt2_1]);
        }
    }

    /*
    for(const auto& p:POINT3_int){
        cout << "(" << p.first.x << "," << p.first.y << "," << p.first.z
             << ") -> " << p.second << endl;
    }
    for(const auto& p:POINT2_int){
        cout << "(" << p.first.x << "," << p.first.y
             << ") -> " << p.second << endl;
    }
    */
    /*
    cout << endl << "gPOINT3:" << endl;
    FOR(i, int(gPOINT3.size())){
        cout << i << ": ";
        for(const auto& j:gPOINT3[i]) cout << j << ", ";
        cout << endl;
    }
    cout << endl;
    */


    ///PROCESSING
    bool truecc = hascycle(gPOINT3, 0);
    bool floorcc = hascycle(gPOINT2, 0);
    ///OUTPUT
    if(truecc)  cout << "True closed chains"    << endl;
    else        cout << "No true closed chains" << endl;
    if(floorcc) cout << "Floor closed chains"   << endl;
    else        cout << "No floor closed chains" << endl;
    return 0;
}
