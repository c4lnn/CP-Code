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
int a[N],pre[N],top1,top2,s1[N],s2[N],ls[N<<2],rs[N<<2],mn[N<<2],add[N<<2],cnt[N<<2];
map<int,int> pos;
void build(int p,int l,int r) {
    ls[p]=l,rs[p]=r;
    mn[p]=add[p]=0;
    cnt[p]=r-l+1;
    if(l==r) return;
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
void push_down(int p) {
    if(add[p]) {
        mn[p<<1]+=add[p],mn[p<<1|1]+=add[p];
        add[p<<1]+=add[p],add[p<<1|1]+=add[p];
        add[p]=0;
    }
}
void update(int p,int l,int r,int v) {
    if(ls[p]>=l&&rs[p]<=r) {
        mn[p]+=v;
        add[p]+=v;
        return;
    }
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(l<=mid) update(p<<1,l,r,v);
    if(r>mid) update(p<<1|1,l,r,v);
    mn[p]=min(mn[p<<1],mn[p<<1|1]);
    cnt[p]=0;
    if(mn[p<<1]==mn[p]) cnt[p]+=cnt[p<<1];
    if(mn[p<<1|1]==mn[p]) cnt[p]+=cnt[p<<1|1];
}
int query(int p,int l,int r) {
    if(ls[p]>=l&&rs[p]<=r) {
        return mn[p]==-1?cnt[p]:0;
    }
    push_down(p);
    int mid=ls[p]+rs[p]>>1;
    if(r<=mid) return query(p<<1,l,r);
    if(l>mid) return query(p<<1|1,l,r);
    return query(p<<1,l,r)+query(p<<1|1,l,r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    for(int cs=1;cs<=T;cs++) {
        int n;cin>>n;
        pos.clear();
        top1=top2=0;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            if(!pos.count(a[i])) pos[a[i]]=0;
            pre[i]=pos[a[i]];
            pos[a[i]]=i;
        }
        build(1,1,n);
        LL res=0;
        for(int i=1;i<=n;i++) {
            while(top1&&a[s1[top1]]<a[i]) {
                int t=s1[top1--];
                update(1,s1[top1]+1,t,a[i]-a[t]);
            }
            s1[++top1]=i;
            while(top2&&a[s2[top2]]>a[i]) {
                int t=s2[top2--];
                update(1,s2[top2]+1,t,a[t]-a[i]);
            }
            s2[++top2]=i;
            update(1,pre[i]+1,i,-1);
            res+=query(1,1,i);
        }
        cout<<"Case #"<<cs<<": "<<res<<'\n';
    }
    return 0;
}