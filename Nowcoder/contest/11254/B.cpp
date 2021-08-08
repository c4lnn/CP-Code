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
int fa[10005];
VPII e[100005];
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,a,b,c,d,p;cin>>n>>m>>a>>b>>c>>d>>p;
    for(int i=1,pre=0,now=a;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            int x=m*(i-1)+j;
            pre=now;
            now=(1ll*pre*pre*b%p+1ll*pre*c%p+d)%p;
            e[now].EB(i,n+j);
        }
    }
    for(int i=1;i<=n+m;i++) fa[i]=i;
    int res=0,cnt=n+m-1;
    for(int i=0;i<p;i++) {
        for(auto x:e[i]) {
            int fu=find(x.FI),fv=find(x.SE);
            if(fu==fv) continue;
            fa[fu]=fv;
            res+=i;
            --cnt;
            if(!cnt) break;
        }
    }
    cout<<res<<'\n';
    return 0;
}