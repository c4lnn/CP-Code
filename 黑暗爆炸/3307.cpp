#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int cnt,to[N*2],nxt[N*2],head[N];
int x[N],y[N],z[N];
int tot,mp[N],f[N][20],tt,depth[N],st[N],ans[N];
struct seg {
    int l=0,r=0;
    int mx=0;
    int id=0;
}tr[N*50];
int root[N],t;
void addedge(int a,int b) {
    cnt++;
    to[cnt]=b;
    nxt[cnt]=head[a];
    head[a]=cnt;
}
void pushup(int p) {
    int l=tr[p].l,r=tr[p].r;
    if(tr[l].mx>=tr[r].mx) tr[p].mx=tr[l].mx,tr[p].id=tr[l].id;
    else tr[p].mx=tr[r].mx,tr[p].id=tr[r].id;
}
void update(int &p,int l,int r,int x,int d) {
    if(!p) p=++t;
    if(l==r) {
        tr[p].mx+=d;
        tr[p].id=l;
        return;
    }
    int mid=l+r>>1;
    if(x<=mid) update(tr[p].l,l,mid,x,d);
    else update(tr[p].r,mid+1,r,x,d);
    pushup(p);
}
int merge(int p,int q,int l,int r) {
    if(!p) return q;
    if(!q) return p;
    if(l==r) {
        tr[p].mx+=tr[q].mx;
        tr[p].id=tr[p].mx?l:0;
        return p;
    }
    int mid=l+r>>1;
    tr[p].l=merge(tr[p].l,tr[q].l,l,mid);
    tr[p].r=merge(tr[p].r,tr[q].r,mid+1,r);
    pushup(p);
    return p;
}
void bfs() {
    queue<int>q;
    q.push(1);
    depth[1]=1;
    while(q.size()) {
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=nxt[i]) {
            int v=to[i];
            if(depth[v]) continue;
            depth[v]=depth[u]+1;
            f[v][0]=u;
            for(int i=1;i<=tt;i++) f[v][i]=f[f[v][i-1]][i-1];
            q.push(v);
        }
    }
}
int lca(int a,int b) {
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=tt;i>=0;i--) if(depth[f[b][i]]>=depth[a]) b=f[b][i];
    if(a==b) return a;
    for(int i=tt;i>=0;i--) if(f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
    return f[a][0];
}
void dfs(int u) {
    st[u]=-1;
    for(int i=head[u];i;i=nxt[i]) {
        int v=to[i];
        if(st[v]==-1) continue;
        dfs(v);
        root[u]=merge(root[u],root[v],1,tot);
    }
    ans[u]=mp[tr[root[u]].id];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    tt=(int)log(n)/log(2)+1;
    for(int i=1;i<=n;i++) root[i]=++t;
    for(int i=1;i<n;i++) {
        int a,b;
        cin>>a>>b;
        addedge(a,b);
        addedge(b,a);
    }
    bfs();
    for(int i=1;i<=m;i++) {
        cin>>x[i]>>y[i]>>z[i];
        mp[++tot]=z[i];
    }
    sort(mp+1,mp+1+tot);
    tot=unique(mp+1,mp+1+tot)-mp-1;
    for(int i=1;i<=m;i++) {
        int r=lca(x[i],y[i]);
        int w=lower_bound(mp+1,mp+1+tot,z[i])-mp;
        update(root[x[i]],1,tot,w,1);
        update(root[y[i]],1,tot,w,1);
        update(root[r],1,tot,w,-1);
        if(f[r][0]) update(root[f[r][0]],1,tot,w,-1);
    }
    dfs(1);
    for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
    return 0;
}