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
//head
const int N=1e5+5;
int n,k,tot[N];
bool st[N];
VPII o;
int main() {
    #ifdef DEBUG
        freopen("E:/OneDrive/IO/in.txt","r",stdin);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        o.EB(a,i);
        o.EB(b,i+n);
        o.EB(c,i+n);
        o.EB(d,i+n);
        o.EB(e,i+n);
    }
    sort(ALL(o));
    o.resize(unique(ALL(o))-o.begin());
    int l=0,r=-1,res=0x3f3f3f3f,sz=0,cnt=0;
    while(r<SZ(o)) {
        if(sz<n) {
            ++r;
            if(++tot[o[r].SE%n]==1) ++sz;
            if(o[r].SE<n) {
                st[o[r].SE]=true;
                if(tot[o[r].SE]==1) ++cnt;
            }
            else if(st[o[r].SE-n]&&tot[o[r].SE-n]==2) --cnt;
        }
        else {
            if(sz==n&&cnt<=k) res=min(res,o[r].FI-o[l].FI);
            if(--tot[o[l].SE%n]==0) --sz;
            if(o[l].SE<n) {
                st[o[l].SE]=false;
                if(tot[o[l].SE]==0) --cnt;
            }
            else if(st[o[l].SE-n]&&tot[o[l].SE-n]==1) ++cnt;
            ++l;
        }
    }
    cout<<res<<'\n';
    return 0;
}