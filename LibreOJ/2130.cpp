#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
const int N=100010;
int n,q;
vi g[N];
int depth[N],sz[N],fa[N],son[N],top[N],id[N];
int cnt;
struct seg {
    int l,r;
    int w;
    int add;
}tr[N*4];
void spread(int p) {
    if(tr[p].add>-1) {
        tr[p*2].w=(tr[p*2].r-tr[p].l+1)*tr[p].add;
        tr[p*2+1].w=(tr[p*2+1].r-tr[p*2+1].l+1)*tr[p].add;
        tr[p*2].add=tr[p].add,tr[p*2+1].add=tr[p].add;
        tr[p].add=-1;
    }
}
void build(int p,int l,int r) {
    tr[p].l=l,tr[p].r=r;
    if(l==r) {
        tr[p].w=0;
        tr[p].add=-1;
        return;
    }
    int mid=l+r>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    tr[p].w=0;
}
void update(int p,int l,int r,int v) {
    if(tr[p].l>=l&&tr[p].r<=r) {
        tr[p].w=(tr[p].r-tr[p].l+1)*v;
        tr[p].add=v;
        return;
    }
    spread(p);
    int mid=tr[p].l+tr[p].r>>1;
    if(l<=mid) update(p*2,l,r,v);
    if(r>mid) update(p*2+1,l,r,v);
    tr[p].w=tr[p*2].w+tr[p*2+1].w;
}
int query(int p,int l,int r) {
    if(tr[p].l>=l&&tr[p].r<=r) return tr[p].w;
    spread(p);
    int mid=tr[p].l+tr[p].r>>1;
    if(r<=mid) return query(p*2,l,r);
    if(l>mid) return query(p*2+1,l,r);
    return query(p*2,l,r)+query(p*2+1,l,r);
}
void dfs1(int u,int d) {
    depth[u]=d;
    sz[u]=1;
    for(auto v:g[u]) {
        if(v==fa[u]) continue;
        fa[v]=u;
        dfs1(v,d+1);
        sz[u]+=sz[v];
        if(sz[v]>sz[son[u]]) son[u]=v;
    }
}
void dfs2(int u,int t) {
    id[u]=++cnt;
    top[u]=t;
    if(!son[u]) return;
    dfs2(son[u],t);
    for(auto v:g[u]) {
        if(v==fa[u]||v==son[u]) continue;
        dfs2(v,v);
    }
}
int install(int x) {
    int res=0;
    while(top[x]!=1) {
        res+=id[x]-id[top[x]]+1-query(1,id[top[x]],id[x]);
        update(1,id[top[x]],id[x],1);
        x=fa[top[x]];
    }
    res+=id[x]-id[1]+1-query(1,id[1],id[x]);
    update(1,id[1],id[x],1);
    return res;
}
int uninstall(int x) {
    int res=query(1,id[x],id[x]+sz[x]-1);
    update(1,id[x],id[x]+sz[x]-1,0);
    return res;
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=2;i<=n;i++) {
        int a;
        cin>>a;
        g[a+1].pb(i);
    }
    dfs1(1,1);
    dfs2(1,1);
    build(1,1,n);
    cin>>q;
    for(int i=1;i<=q;i++) {
        string s;
        int x;
        cin>>s>>x;
        x++;
        if(s[0]=='i') cout<<install(x)<<endl;
        else cout<<uninstall(x)<<endl;
    }
    return 0;
}