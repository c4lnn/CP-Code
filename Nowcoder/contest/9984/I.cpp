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
int ls[N<<2],rs[N<<2];
LL a[N],s[N],dp[N][2],w[3][N<<2],add[3][N<<2];
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) return;
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void push_down(int p,int id) {
    if(add[id][p]) {
        w[id][p<<1]+=add[id][p];
        w[id][p<<1|1]+=add[id][p];
        add[id][p<<1]+=add[id][p],add[id][p<<1|1]+=add[id][p];
        add[id][p]=0;
    }
}
void update(int p,int l,int r,LL v,int id) {
    if(l<=ls[p]&&rs[p]<=r) {
        w[id][p]+=v;
        add[id][p]+=v;
        return;
    }
    int mid=ls[p]+rs[p]>>1;
    push_down(p,id);
    if(l<=mid) update(p<<1,l,r,v,id);
    if(r>mid) update(p<<1|1,l,r,v,id);
    w[id][p]=max(w[id][p<<1],w[id][p<<1|1]);
}
LL query(int p,int l,int r,int id) {
    if(ls[p]>=l&&rs[p]<=r) return w[id][p];
    push_down(p,id);
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query(p<<1,l,r,id);
    if(l>mid) return query(p<<1|1,l,r,id);
    return max(query(p<<1,l,r,id),query(p<<1|1,l,r,id));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
    build(1,0,n);
    for(int i=1;i<=n;i++) {
        dp[i][0]=query(1,max(0,i-k),i-1,0)+s[i];
        if(i-1>=k+1) dp[i][0]=max(dp[i][0],query(1,max(i-k,k+1),i-1,1)+2*s[i]);
        update(1,i,i,dp[i][0]-s[i],0);
        if(i-k-1<0) continue;
        dp[i][1]=max(query(1,0,i-k-1,0)+s[i],query(1,0,i-k-1,2)+s[i]);
        update(1,i,i,dp[i][1]-2*s[i],1);
        update(1,i,i,dp[i][1]-s[i],2);
    }
    cout<<max(dp[n][0],dp[n][1])<<'\n';
    return 0;
}