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
int cnt,a[N],tr[N*31][2],fa[N*31],id[N*31],mx[N*31];
void insert(int x,int t) {
    VI d;
    while(x) d.PB(x&1),x>>=1;
    while(SZ(d)<30) d.PB(0);
    int u=0;
    for(int i=SZ(d)-1;~i;i--) {
        int v=d[i];
        if(!tr[u][v]) {
            tr[u][v]=++cnt;
            fa[cnt]=u;
        }
        u=tr[u][v];
    }
    id[u]=t;
    while(u) {
        mx[fa[u]]=max(mx[fa[u]],t);
        u=fa[u];
    }
}
int query(int x,int k) {
    int ret=-1,u=0;
    cout<<x<<'\n';
    for(int i=30;~i;i--) {
        int v=(x>>i)&1;
        if(!tr[u][v^1]&&!tr[u][v]) return ret;
        if(tr[u][v^1]) ret=max(ret,mx[tr[u][v^1]]);
        if(tr[u][v]) u=tr[u][v];
    }
    ret=max(ret,id[u]);
    return ret;
}
int main() {
#ifdef DEBUG
    freopen("E:/IO/data.in","r",stdin);
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,k;cin>>n>>k;
        for(int i=1;i<=cnt;i++) tr[i][0]=tr[i][1]=0;
        cnt=0;
        for(int i=1;i<=n*30;i++) mx[i]=id[i]=0;
        insert(0,0);
        int sum=0;
        PII res={0,0x3f3f3f3f};
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            sum^=a[i];
            // cout<<sum<<' '<<(sum^k)<<'\n';
            int l=query(sum^k);
            if(l!=-1) {
                ++l;
                cout<<l<<' '<<i<<'\n';
                if(i-l<res.SE-res.FI) res={l,i};
            }
            insert(sum,i);
        }
        if(res.FI) cout<<res.FI<<' '<<res.SE<<'\n';
        else cout<<-1<<'\n';
    }
    return 0;
}