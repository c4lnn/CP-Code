#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<functional>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
using namespace std;
const int N=1e5+5;
int n,m;
struct E_DCC {//无向连通图
	vector<int> G[N];
	void init() {
		for(int i=1;i<=n;i++) G[i].clear();
	}
	//桥
	int cnt,dfn[N],low[N],fa[N];
	bool isb[N];
	vector<int> b;
	void tarjan(int u) {
		dfn[u]=low[u]=++cnt;
		for(int i=0;i<G[u].size();i++) {
			int v=G[u][i];
			if(!dfn[v]) {
				fa[v]=u;
				tarjan(v);
				low[u]=min(low[u],low[v]);
				if(dfn[u]<low[v]) isb[v]=true,b.push_back(v);
			}
			else if(v!=fa[u]) low[u]=min(low[u],dfn[v]);
		}
	}
	void get_bridge() {
		cnt=0;
		b.clear();
		for(int i=1;i<=n;i++) dfn[i]=low[i]=0;
		for(int i=1;i<=n;i++) isb[i]=false;
		tarjan(1);
	}
	//边双连通分量
	int dcc,c[N];
	void dfs(int u) {
		c[u]=dcc;
		for(int i=0;i<G[u].size();i++) {
			int v=G[u][i];
			if(c[v]||isb[v]) continue;
			dfs(v);
		}
	}
	void shrink() {
		dcc=0;
		for(int i=1;i<=n;i++) c[i]=0;
		for(int i=1;i<=n;i++) if(!c[i]) ++dcc,dfs(i);
	}
	//缩点
	vector<int> g[N];
	int d[N],pre[N];
	void build_dcc_tree() {
		for(int i=1;i<=dcc;i++) g[i].clear(),d[i]=0,pre[i]=0;
		for(int i=0;i<b.size();i++) {
			int u=c[b[i]],v=c[fa[b[i]]];
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs_dcc_tree(1);
	}
	void dfs_dcc_tree(int u) {
		d[u]=d[pre[u]]+1;
		for(int i=0;i<g[u].size();i++) {
			int v=g[u][i];
			if(v==pre[u]) continue;
			pre[v]=u;
			dfs_dcc_tree(v);
		}
	}
	//solve
	int f[N];
	int find(int x) {
		return f[x]==x?x:f[x]=find(f[x]);
	}
	int lca(int u,int v) {
		int tot=0;
		while(d[u]<d[v]) {
			int tx=find(v),ty=find(pre[v]);
			if(tx!=ty) {
				tot++;
				f[tx]=ty;
			}
			v=ty;
		}
		while(d[v]<d[u]) {
			int tx=find(u),ty=find(pre[u]);
			if(tx!=ty) {
				tot++;
				f[tx]=ty;
			}
			u=ty;
		}
		while(u!=v) {
			int tx=find(v),ty=find(pre[v]);
			if(tx!=ty) {
				tot++;
				f[tx]=ty;
			}
			v=ty;
            tx=find(u),ty=find(pre[u]);
			if(tx!=ty) {
				tot++;
				f[tx]=ty;
			}
			u=ty;
		}
		return tot;
	}
	void solve() {
		for(int i=1;i<=dcc;i++) f[i]=i;
		pre[1]=1;
		int q,tot=b.size();
		scanf("%d",&q);
		for(int i=1;i<=q;i++) {
			int u,v;
			scanf("%d%d",&u,&v);
			if(c[u]!=c[v]&&find(c[u])!=find(c[v])) tot-=lca(c[u],c[v]);
			printf("%d\n",tot);
		}
	}
}e_dcc;
int main() {
	for(int T=1;;T++) {
		scanf("%d%d",&n,&m);
		if(n==0&&m==0) break;
		if(T>1) puts("");
		printf("Case %d:\n",T);
	    e_dcc.init();
	    for(int i=1;i<=m;i++) {
	    	int u,v;
	    	scanf("%d%d",&u,&v);
	    	e_dcc.G[u].push_back(v);
	    	e_dcc.G[v].push_back(u);
	    }
	    e_dcc.get_bridge();
	    e_dcc.shrink();
	    e_dcc.build_dcc_tree();
	    e_dcc.solve();
	}  
    return 0;
}