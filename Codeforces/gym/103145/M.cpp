#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
unordered_map<string,string>mp;
void init(){
    mp["q"]="q";
    mp["iu"]="q";
    mp["w"]="w";
    mp["ei"]="w";
    mp["e"]="e";
    mp["r"]="r";
    mp["uan"]="r";
    mp["t"]=mp["ue"]="t";
    mp["y"]=mp["un"]="y";
    mp["u"]=mp["sh"]="u";
    mp["i"]=mp["ch"]="i";
    mp["o"]=mp["uo"]="o";
    mp["p"]=mp["ie"]="p";
    mp["a"]="a";
    mp["s"]=mp["ong"]=mp["iong"]="s";
    mp["d"]=mp["ai"]="d";
    mp["f"]="f";
    mp["g"]="g";
    mp["h"]="h";
    mp["j"]="j";
    mp["k"]="k";
    mp["l"]="l";
    mp["z"]="z";
    mp["x"]="x";
    mp["c"]="c";
    mp["v"]="v";
    mp["b"]="b";
    mp["n"]="n";
    mp["m"]="m";
    mp["en"] = "f";
    mp["eng"] = "g";
    mp["ang"] = "h";
    mp["an"] = "j";
    mp["uai"] = "k";
    mp["ing"] = "k";
    mp["uang"] = "l";
    mp["iang"] = "l";
    mp["ou"] = "z";
    mp["ia"] = "x";
    mp["ua"] = "x";
    mp["ao"] = "c";
    mp["zh"] = "v";
    mp["ui"] = "v";
    mp["in"] = "b";
    mp["iao"] = "n";
    mp["ian"] = "m";
}
int main(){
    init();
    string s;
    while(getline(cin,s)){
        string t;
        bool f=0;
        for(int i=0;i<=SZ(s);i++) {
            if(i==SZ(s)||s[i]==' ') {
                if(f) cout<<' ';
                f=true;
                if(SZ(t)==1) cout<<t<<t;
                else if(SZ(t)==2) cout<<t;
                else {
                    for(int j=0;j<SZ(t);j++) {
                        string t1=t.substr(0,j);
                        string t2=t.substr(j,SZ(t));
                        if(t1[SZ(t1)-1]=='n'&&t2[0]=='g') continue;
                        if((SZ(t1)==0||mp.count(t1))&&mp.count(t2)) {
                            cout<<mp[t1];
                            if(SZ(t1)==0&&(t2=="ang"||t2=="eng"||t2=="ing"||t2=="ong")) cout<<t2[0]<<mp[t2];
                            else cout<<mp[t2];
                            break;
                        }
                    }
                }
                t.clear();
            }
            else t+=s[i];
        }
        cout<<'\n';
    }
    return 0;
}