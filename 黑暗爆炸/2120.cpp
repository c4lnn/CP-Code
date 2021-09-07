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
int n,m,unit,t=1,ans,a[10005],cnt[1000005],pre[10005],res[10005];
struct R {
    int x,v,pre;
    R() {}
    R(int x,int v,int pre):x(x),v(v),pre(pre) {}
} b[1005];
struct Q {
    int l,r,t,id;
    Q() {}
    Q(int l,int r,int t,int id):l(l),r(r),t(t),id(id) {}
    bool operator < (const Q &T) const {
        if(l/unit!=T.l/unit) return l<T.l;
        if(r/unit!=T.l/unit) return r<T.r;
        return t<T.t;
    }
};
vector<Q> q;
void update_t(int t,int l,int r,int v) {
    if(v==1) {
        if(b[t].x>=l&&b[t].x<=r) {
            if(--cnt[b[t].pre]==0) --ans;
            if(++cnt[b[t].v]==1) ++ans;
        }
        a[b[t].x]=b[t].v;
    }
    else {
        if(b[t].x>=l&&b[t].x<=r) {
            if(--cnt[b[t].v]==0) --ans;
            if(++cnt[b[t].pre]==1) ++ans;
        }
        a[b[t].x]=b[t].pre;
    }
}
void update(int x,int v) {
    if(v==-1&&--cnt[a[x]]==0) --ans;
    if(v==1&&++cnt[a[x]]==1) ++ans;
}
void mo() {
    unit=int(ceil(pow(n*t,1.0/3)));
    sort(ALL(q));
    int t=1,l=0,r=-1;
    for(auto x:q) {
        while(t<x.t) update_t(++t,l,r,1);
        while(t>x.t) update_t(t--,l,r,-1);
        while(l>x.l) update(--l,1);
        while(r<x.r) update(++r,1);
        while(l<x.l) update(l++,-1);
        while(r>x.r) update(r--,-1);
        res[x.id]=ans;
    }
    for(int i=0;i<SZ(q);i++) cout<<res[i]<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        pre[i]=a[i];
    }
    int cnt_q=0;
    for(int i=0;i<m;i++) {
        char o;cin>>o;
        if(o=='R') {
            int x,v;cin>>x>>v;
            --x;
            b[++t]=R(x,v,pre[x]);
            pre[x]=v;
        }
        else {
            int l,r;cin>>l>>r;
            --l,--r;
            q.EB(l,r,t,cnt_q++);
        }
    }
    mo();
    return 0;
}