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
struct R{
    LL cnt;
    string l,r;
    R() {}
    R(LL cnt,string l,string r):cnt(cnt),l(l),r(r) {}
};
unordered_map<string,R> mp;
int check(const string &s) {
    int ret=0;
    for(int i=3;i<SZ(s);i++) if(s.substr(i-3,4)=="haha") ++ret;
    return ret;
}
R merge(R &a,R &b) {
    R ret;
    ret.cnt=a.cnt+b.cnt;
    string s=a.r+b.l;
    for(int i=3;i<SZ(s);i++) if(s.substr(i-3,4)=="haha") ++ret.cnt;
    ret.l=a.l,ret.r=b.r;
    int t=0;
    while(t<SZ(b.l)&&SZ(ret.l)<3) ret.l+=b.l[t++];
    t=SZ(a.r)-1;
    while(t>=0&&SZ(ret.r)<3) ret.r=a.r[t--]+ret.r;
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        mp.clear();
        int n;cin>>n;
        for(int i=1;i<=n;i++) {
            string s,o;cin>>s>>o;
            if(o[0]==':') {
                string ss;cin>>ss;
                mp[s]=R(check(ss),ss.substr(0,min(SZ(ss),3)),ss.substr(max(0,SZ(ss)-3),min(SZ(ss),3)));
            }
            else {
                string a,b,c;cin>>a>>b>>c;
                mp[s]=merge(mp[a],mp[c]);
            }
            if(i==n) cout<<mp[s].cnt<<'\n';
        }
    }
    return 0;
}