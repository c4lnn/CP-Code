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
int n,a[N],cnt,tr[N*400][2],tot[N*400],pre[N],rt[N],res[N];
struct R {
    int l,a,b,id;;
    R() {}
    R(int l,int a,int b,int id):l(l),a(a),b(b),id(id) {}
};
vector<R> q[N];
void insert(int u,int d,int w) {
    for(int i=17;~i;i--) {
        int v=(d>>i)&1;
        if(!tr[u][v]) tr[u][v]=++cnt;
        u=tr[u][v];
        tot[u]+=w;
    }
}
void update(int x,int d,int w) {
    for(int i=x;i<=n;i+=i&-i) insert(rt[i],d,w);
}
int ask(int u,int a,int b) {
    int ret=0;
    for(int i=17;~i;i--) {
        int t1=(a>>i)&1,t2=(b>>i)&1;
        if(t1==0&&t2==0) u=tr[u][0];
        else if(t1==0&&t2==1) ret+=tot[tr[u][0]],u=tr[u][1];
        else if(t1==1&&t2==0) u=tr[u][1];
        else ret+=tot[tr[u][1]],u=tr[u][0];
        if(!u) break;
    }
    return ret+=tot[u];
}
int query(int l,int r,int a,int b) {
    int ret=0;
    for(int i=r;i;i-=i&-i) ret+=ask(rt[i],a,b);
    int t=ret;
    for(int i=l-1;i;i-=i&-i) ret-=ask(rt[i],a,b);
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        q[i].clear();
        rt[i]=++cnt;
    }
    int m;cin>>m;
    for(int i=1;i<=m;i++) {
        int l,r,a,b;cin>>l>>r>>a>>b;
        q[r].EB(l,a,b,i);
    }
    for(int i=1;i<=n;i++) {
        if(pre[a[i]]) update(pre[a[i]],a[i],-1);
        update(i,a[i],1);
        pre[a[i]]=i;
        for(auto x:q[i]) res[x.id]=query(x.l,i,x.a,x.b);
    }
    for(int i=1;i<=m;i++) cout<<res[i]<<'\n';
    return 0;
}