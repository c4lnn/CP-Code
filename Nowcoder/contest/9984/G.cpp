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
const int N=2e3+5;
const int M=3e3+5;
int n,m,x[M],y[M],k[M],a[N],ls[N<<2],rs[N<<2],w[N][N<<2];
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    if(l==r) {a[l]=p;return;}
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void pushdown(int p,int pre,int id) {
    w[id][p]=max(pre,w[id][p]);
    if(ls[p]==rs[p]) return;
    pushdown(p<<1,w[id][p],id);
    pushdown(p<<1|1,w[id][p],id);
}
void update(int p,int l,int r,int v,int id) {
    if(ls[p]>=l&&rs[p]<=r) {
        if(!w[id][p]) w[id][p]=v;
        return;
    }
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid&&!w[id][p<<1]) update(p<<1,l,r,v,id);
    if(r>mid&&!w[id][p<<1|1]) update(p<<1|1,l,r,v,id);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>x[i]>>y[i]>>k[i];
    build(1,1,n);
    for(int i=m;i>=1;i--)
        for(int j=0;j<k[i];j++)
            update(1,y[i],y[i]+k[i]-1,i,x[i]+j);
    for(int i=1;i<=n;i++) pushdown(1,0,i);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int t=w[i][a[j]];
            if(!t) cout<<0<<" \n"[j==n];
            else {
                int r=i-x[t]+1,c=j-y[t]+1;
                cout<<(r&1?(r-1)*k[t]+c:(r-1)*k[t]+k[t]-c+1)<<" \n"[j==n];
            }
        }
    }
    return 0;
}