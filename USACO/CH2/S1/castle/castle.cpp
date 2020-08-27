/*
ID: dmfrodr1
TASK: castle
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,b,e) for(int (i) = (b); (i) < (e); ++(i))
#define X first
#define Y second

typedef vector<int> VI;
typedef vector<VI>  VVI;
typedef pair<int,int> PII;


VVI get_rooms(const VVI &map){
    const int W = map.size();
    const int H = map[0].size();
    VVI rooms(W, VI(H, 0));
    int id = 1;
    FOR(w,0,W) FOR(h,0,H){
        if(rooms[w][h] == 0){
            queue<PII> q; q.push(PII(w,h));
            while(!q.empty()){
                PII pt = q.front(); q.pop();
                if(rooms[pt.X][pt.Y] != 0) continue;
                rooms[pt.X][pt.Y] = id;
                if(~map[pt.X][pt.Y] & (1<<0)){q.push(PII(pt.X-1,pt.Y  ));} /** WEST  */
                if(~map[pt.X][pt.Y] & (1<<1)){q.push(PII(pt.X  ,pt.Y-1));} /** NORTH */
                if(~map[pt.X][pt.Y] & (1<<2)){q.push(PII(pt.X+1,pt.Y  ));} /** EAST  */
                if(~map[pt.X][pt.Y] & (1<<3)){q.push(PII(pt.X  ,pt.Y+1));} /** SOUTH */
            }
            ++id;
        }
    }
    return rooms;
}
VI get_room_areas(const VVI &rooms){
    int max_id = 0;
    for(const VI &v:rooms) max_id = max(max_id, *max_element(v.begin(), v.end()));
    VI ret(max_id+1, 0);
    for(const VI &v:rooms) for(const int &n:v) ++ret[n];
    return ret;
}

struct Wall{
    int gain;
    int w, h;
    char dir;
    Wall(int gain, int w, int h, int dir):gain(gain),w(w),h(h),dir(dir){}
    bool operator<(const Wall& obj) const{
        if     (gain != obj.gain) return (this->gain > obj.gain);
        else if(w    != obj.w   ) return (this->w    < obj.w   );
        else if(h    != obj.h   ) return (this->h    > obj.h   );
        else return (dir == 'N');
    }
};

Wall get_best_wall(const VVI &rooms, const VI &room_areas){
    const int W = rooms.size();
    const int H = rooms[0].size();

    Wall ret(-1, -1, -1, 'E');
    FOR(w,0,W) FOR(h,1,H){
        if(rooms[w][h] != rooms[w][h-1]){ //N
            Wall v(room_areas[rooms[w][h]] + room_areas[rooms[w][h-1]], w, h, 'N');
            ret = min(ret, v);
        }
    }
    FOR(w,0,W-1) FOR(h,0,H){
        if(rooms[w][h] != rooms[w+1][h]){ //E
            Wall v(room_areas[rooms[w][h]] + room_areas[rooms[w+1][h]], w, h, 'E');
            ret = min(ret, v);
        }
    }
    return ret;
}

int main(){
    ///INPUT
    ifstream fin("castle.in");
    ofstream fout("castle.out");
    int W, H; fin >> W >> H;
    VVI map(W, VI(H));
    FOR(h,0,H) FOR(w,0,W) fin >> map[w][h];
    ///PROCESSING
    VVI rooms = get_rooms(map);
    //FOR(h,0,H){ FOR(w,0,W) cout << rooms[w][h] << " "; cout << endl; }
    VI room_areas = get_room_areas(rooms);
    fout << room_areas.size()-1 << endl;
    fout << *max_element(room_areas.begin(), room_areas.end()) << endl;
    Wall w = get_best_wall(rooms, room_areas);
    fout << w.gain << endl;
    fout << w.h+1 << " " << w.w+1 << " " << w.dir << endl;
    return 0;
}
