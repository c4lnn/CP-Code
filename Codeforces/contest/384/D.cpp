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
const int N=1e5+5;
unordered_map<int,int> mp;
int id[N],cnt;
VI b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    VPII a(m),c,t;
    for(int i=0;i<m;i++) cin>>a[i].FI>>a[i].SE;
    sort(ALL(a));
    for(int i=0;i<SZ(a);i++) {
        if(!mp.count(a[i].FI)) mp[a[i].FI]=++cnt,id[cnt]=a[i].FI;
        b[mp[a[i].FI]].PB(a[i].SE);
    }
    if(id[1]==1&&SZ(b[1])) c.EB(1,b[1][0]-1);
    else c.EB(1,n);
    int pre=1;
    for(int i=1;i<=cnt;i++) if(id[i]!=1) {
        if(id[i]-pre>1) {
            int l=c[0].FI;
            c.clear();
            c.EB(l,n);
        }
        b[i].EB(n+1);
        for(int j=0,pos=0,l=1;j<SZ(b[i]);j++) {
            while(pos<SZ(c)&&c[pos].SE<l) ++pos;
            if(pos==SZ(c)) break;
            if(max(l,c[pos].FI)<=b[i][j]-1) t.EB(max(l,c[pos].FI),b[i][j]-1);
            l=b[i][j]+1;
        }
        swap(c,t);
        t.clear();
        pre=id[i];
        if(!SZ(c)) return cout<<-1<<'\n',0;
    }
    if(id[cnt]<n||id[cnt]==n&&c[SZ(c)-1].SE==n) cout<<n+n-2<<'\n';
    else cout<<-1<<'\n';
    return 0;
}