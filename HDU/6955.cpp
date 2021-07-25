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
int cnt,tr[N*31][2],mx[N*31];
void insert(int x,int id) {
    VI d;
    for(int i=0;i<30;i++) d.PB(x&1),x/=2;
    int u=0;
    for(int i=29;~i;i--) {
        int v=d[i];
        if(!tr[u][v]) tr[u][v]=++cnt;
        u=tr[u][v];
        mx[u]=max(mx[u],id);
    }
}
int query(int x,int k) {
    int u=0,res=-1;
    for(int i=29;~i;i--) {
        int v=(x>>i)&1;
        if(!((k>>i)&1)) {
            if(tr[u][v^1]) res=max(res,mx[tr[u][v^1]]);
            if(tr[u][v]) u=tr[u][v];
        }
        else if(tr[u][v^1]) u=tr[u][v^1];
        else break;
        if(!i) res=max(res,mx[u]);
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,k;cin>>n>>k;
        insert(0,0);
        PII res=MP(-1,0x3f3f3f3f);
        for(int i=1,sum=0;i<=n;i++) {
            int x;cin>>x;
            sum^=x;
            int ret=query(sum,k);
            if(ret!=-1&&i-ret<res.SE-res.FI) res=MP(ret,i);
            insert(sum,i);
        }
        if(res.FI!=-1) cout<<res.FI+1<<' '<<res.SE<<'\n';
        else cout<<-1<<'\n';
        for(int i=0;i<=cnt;i++) tr[i][0]=tr[i][1]=0,mx[i]=-1;
        cnt=0;
    }
    return 0;
}