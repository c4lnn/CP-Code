#include <iostream>
#include <algorithm>
#include <vector>
#define SZ(x) (int)(x).size()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
// head
const int N=5e4+5;
int fa[N],mn[N],mx[N],up[N],down[N],a[N],b[N],res[N],st[N];
int cnt1,head1[N],nxt1[N<<1],to1[N<<1];
int cnt2,head2[N],nxt2[N<<1],to2[N<<1],id1[N<<1];
int cnt3,head3[N],nxt3[N],id2[N];
void add_edge1(int u,int v) {
    nxt1[++cnt1]=head1[u];
    to1[cnt1]=v;
    head1[u]=cnt1;
}
void add_edge2(int u,int v,int x) {
    nxt2[++cnt2]=head2[u];
    to2[cnt2]=v;
    id1[cnt2]=x;
    head2[u]=cnt2;
}
void add_edge3(int u,int x) {
    nxt3[++cnt3]=head3[u];
    id2[cnt3]=x;
    head3[u]=cnt3;
}
int find(int x) {
    if(x==fa[x]) return x;
    int rt=find(fa[x]);
    up[x]=max(max(up[x],up[fa[x]]),mx[fa[x]]-mn[x]);
    down[x]=max(max(down[x],down[fa[x]]),mx[x]-mn[fa[x]]);
    mx[x]=max(mx[fa[x]],mx[x]);
    mn[x]=min(mn[fa[x]],mn[x]);
    return fa[x]=rt;
}
void tarjan(int u) {
    st[u]=1;
    for(int i=head1[u];i;i=nxt1[i]) {
        int v=to1[i];
        if(st[v]) continue;
        tarjan(v);
        fa[v]=u;
        st[v]=2;
    }
    for(int i=head2[u];i;i=nxt2[i]) if(st[to2[i]]==2) {
        add_edge3(find(to2[i]),id1[i]);
    }
    for(int i=head3[u];i;i=nxt3[i]) {
        int x=id2[i];
        find(a[x]),find(b[x]);
        res[x]=max(max(max(up[a[x]],down[b[x]]),mx[b[x]]-mn[a[x]]),0);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>mx[i];
        fa[i]=i;
        mn[i]=mx[i];
    }
    for(int i=1;i<n;i++) {
        int u,v;cin>>u>>v;
        add_edge1(u,v);
        add_edge1(v,u);
    }
    int m;cin>>m;
    for(int i=1;i<=m;i++) {
        cin>>a[i]>>b[i];
        add_edge2(a[i],b[i],i);
        add_edge2(b[i],a[i],i);
    }
    tarjan(1);
    for(int i=1;i<=m;i++) cout<<res[i]<<'\n';
    return 0;
}