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
const int N=1005;
int n,m,W,fa[N],w[N],b[N],sum_w[N],sum_b[N],dp[N];
VI p[N];
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y) {
    int fx=find(x),fy=find(y);
    if(fx==fy) return;
    fa[fx]=fy;
    sum_w[fy]+=sum_w[fx];
    sum_b[fy]+=sum_b[fx];
    for(auto x:p[fx]) p[fy].PB(x);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>W;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) {
        fa[i]=i;
        sum_w[i]=w[i];
        sum_b[i]=b[i];
        p[i].PB(i);
    }
    for(int i=1;i<=m;i++) {
        int x,y;cin>>x>>y;
        merge(x,y);
    }
    int t=0;
    for(int i=1;i<=n;i++) if(fa[i]==i) {
        for(int j=W;j>=0;j--) {
            for(auto x:p[i]) if(j-w[x]>=0) dp[j]=max(dp[j],dp[j-w[x]]+b[x]);
            if(j-sum_w[i]>=0) dp[j]=max(dp[j],dp[j-sum_w[i]]+sum_b[i]);
        }
    }
    int res=0;
    for(int i=0;i<=W;i++) res=max(res,dp[i]);
    cout<<res<<'\n';
    return 0;
}