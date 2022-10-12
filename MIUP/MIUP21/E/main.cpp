#include <bits/stdc++.h>
using namespace std;
typedef long long int           lli;
typedef unsigned long long int  ulli;
#define ALL(v)                  (v).begin() , (v).end()
#define FOR(i, b, e)            for(lli i =(b); (i)  < (lli)(e); ++(i))
typedef vector<lli>             VI;
typedef vector<VI>              VVI;
typedef vector<bool>            VB;
typedef vector<VB>              VVB;
typedef pair< lli, lli>         PII;
typedef pair<ulli,ulli>         PUU;
typedef pair<PII,PII>           PPP;
#define X first
#define Y second
const lli INF = 100000000;

const vector<pair<string,string>> original = {
    {"H", "Hydrogen"},
    {"He", "Helium"},
    {"Li", "Lithium"},
    {"Be", "Beryllium"},
    {"B", "Boron"},
    {"C", "Carbon"},
    {"N", "Nitrogen"},
    {"O", "Oxygen"},
    {"F", "Fluorine"},
    {"Ne", "Neon"},
    {"Na", "Sodium"},
    {"Mg", "Magnesium"},
    {"Al", "Aluminium"},
    {"Si", "Silicon"},
    {"P", "Phosphorus"},
    {"S", "Sulfur"},
    {"Cl", "Chlorine"},
    {"Ar", "Argon"},
    {"K", "Potassium"},
    {"Ca", "Calcium"},
    {"Sc", "Scandium"},
    {"Ti", "Titanium"},
    {"V", "Vanadium"},
    {"Cr", "Chromium"},
    {"Mn", "Manganese"},
    {"Fe", "Iron"},
    {"Co", "Cobalt"},
    {"Ni", "Nickel"},
    {"Cu", "Copper"},
    {"Zn", "Zinc"},
    {"Ga", "Gallium"},
    {"Ge", "Germanium"},
    {"As", "Arsenic"},
    {"Se", "Selenium"},
    {"Br", "Bromine"},
    {"Kr", "Krypton"},
    {"Rb", "Rubidium"},
    {"Sr", "Strontium"},
    {"Y", "Yttrium"},
    {"Zr", "Zirconium"},
    {"Nb", "Niobium"},
    {"Mo", "Molybdenum"},
    {"Tc", "Technetium"},
    {"Ru", "Ruthenium"},
    {"Rh", "Rhodium"},
    {"Pd", "Palladium"},
    {"Ag", "Silver"},
    {"Cd", "Cadmium"},
    {"In", "Indium"},
    {"Sn", "Tin"},
    {"Sb", "Antimony"},
    {"Te", "Tellurium"},
    {"I", "Iodine"},
    {"Xe", "Xenon"},
    {"Cs", "Caesium"},
    {"Ba", "Barium"},
    {"La", "Lanthanum"},
    {"Ce", "Cerium"},
    {"Pr", "Praseodymium"},
    {"Nd", "Neodymium"},
    {"Pm", "Promethium"},
    {"Sm", "Samarium"},
    {"Eu", "Europium"},
    {"Gd", "Gadolinium"},
    {"Tb", "Terbium"},
    {"Dy", "Dysprosium"},
    {"Ho", "Holmium"},
    {"Er", "Erbium"},
    {"Tm", "Thulium"},
    {"Yb", "Ytterbium"},
    {"Lu", "Lutetium"},
    {"Hf", "Hafnium"},
    {"Ta", "Tantalum"},
    {"W", "Tungsten"},
    {"Re", "Rhenium"},
    {"Os", "Osmium"},
    {"Ir", "Iridium"},
    {"Pt", "Platinum"},
    {"Au", "Gold"},
    {"Hg", "Mercury"},
    {"Tl", "Thallium"},
    {"Pb", "Lead"},
    {"Bi", "Bismuth"},
    {"Po", "Polonium"},
    {"At", "Astatine"},
    {"Rn", "Radon"},
    {"Fr", "Francium"},
    {"Ra", "Radium"},
    {"Ac", "Actinium"},
    {"Th", "Thorium"},
    {"Pa", "Protactinium"},
    {"U", "Uranium"},
    {"Np", "Neptunium"},
    {"Pu", "Plutonium"},
    {"Am", "Americium"},
    {"Cm", "Curium"},
    {"Bk", "Berkelium"},
    {"Cf", "Californium"},
    {"Es", "Einsteinium"},
    {"Fm", "Fermium"},
    {"Md", "Mendelevium"},
    {"No", "Nobelium"},
    {"Lr", "Lawrencium"},
    {"Rf", "Rutherfordium"},
    {"Db", "Dubnium"},
    {"Sg", "Seaborgium"},
    {"Bh", "Bohrium"},
    {"Hs", "Hassium"},
    {"Mt", "Meitnerium"},
    {"Ds", "Darmstadtium"},
    {"Rg", "Roentgenium"},
    {"Cn", "Copernicium"},
    {"Nh", "Nihonium"},
    {"Fl", "Flerovium"},
    {"Mc", "Moscovium"},
    {"Lv", "Livermorium"},
    {"Ts", "Tennessine"},
    {"Og", "Oganesson"},
};

unordered_map<string,int> getEl2Num(){
    unordered_map<string,int> ret;
    FOR(i,0,original.size()){
        string el = original[i].first;
        transform(el.begin(), el.end(), el.begin(), [](unsigned char c){ return tolower(c); });
        ret[el] = i;
    }
    return ret;
}

unordered_map<int, string> getNum2El(){
    unordered_map<int, string> ret;
    FOR(i,0,original.size()){
        string el = original[i].first;
        transform(el.begin(), el.end(), el.begin(), [](unsigned char c){ return tolower(c); });
        ret[i] = el;
    }
    return ret;
}

unordered_map<int,string> getNum2Element(){
    unordered_map<int,string> ret;
    FOR(i,0,original.size()){
        ret[i] = original[i].second;
    }
    return ret;
}

const unordered_map<string, int> el2num = getEl2Num();
const unordered_map<int, string> num2el = getNum2El();
const unordered_map<int, string> num2element = getNum2Element();

void solve(deque<int>& prev, const string &name, int l, int r){
    if(r-l <= 0){
        bool first = true;
        for(const int &el: prev){
            cout << (first ? "" : " ") << num2element.at(el);
            first = false;
        }
        cout << "\n";
        return;
    }

    vector<int> els;
    els.reserve(2);
    if(r-l >= 1){
        string smallStr = name.substr(l, 1);
        auto it = el2num.find(smallStr);
        if(it != el2num.end()){
            els.push_back(it->second);
        }
    }
    if(r-l >= 2){
        string largeStr = name.substr(l, 2);
        auto it = el2num.find(largeStr);
        if(it != el2num.end()){
            els.push_back(it->second);
        }
    }
    sort(ALL(els));
    for(const int &el: els){
        size_t sz = num2el.at(el).size();
        prev.push_back(el);
        solve(prev, name, l+sz, r);
        prev.pop_back();
    }
}

int main(){
    int N; cin >> N;
    FOR(n,0,N){
        string name; cin >> name;
        cout << name << "\n";
        deque<int> prev;
        solve(prev, name, 0, name.size());
    }

    return 0;
}
