#include<bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=2e5+5;
struct E_DCC {
	int n,m;
	VPII e;
	VI G[N];
	void init() {
		e.clear();
		for(int i=1;i<=n;i++) G[i].clear();
	}
	void addedge(int u,int v) {
		e.PB(MP(u,v));
		e.PB(MP(v,u));
		G[u].PB(SZ(e)-2);
		G[v].PB(SZ(e)-1);
	}
	//割边
	int cnt,dfn[N],low[N];
	bool isb[N*10];
	vector<int> b;
	void tarjan(int u,int id) {
		dfn[u]=low[u]=++cnt;
		for(auto x:G[u]) {
			int &v=e[x].SE;
			if(!dfn[v]) {
				tarjan(v,x);
				low[u]=min(low[u],low[v]);
				if(dfn[u]<low[v]) isb[x]=isb[x^1]=true,b.push_back(x);
			}
			else if(id!=(x^1)) low[u]=min(low[u],dfn[v]);
		}
	}
	void get_bridge() {
		cnt=0;
		b.clear();
		for(int i=1;i<=n;i++) dfn[i]=low[i]=0;
		for(int i=0;i<SZ(e);i++) isb[i]=false;
		for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,-1);
	}
	//边双连通分量
	int dcc,c[N];
	void dfs(int u) {
		c[u]=dcc;
		for(auto x:G[u]) {
			int &v=e[x].SE;
			if(c[v]||isb[x]||isb[x^1]) continue;
			dfs(v);
		}
	}
	void shrink() {
		dcc=0;
		for(int i=1;i<=n;i++) c[i]=0;
		for(int i=1;i<=n;i++) if(!c[i]) ++dcc,dfs(i);
	}
	//缩点建图
	vector<int> g[N];
	void build() { //将边双连通分量缩点与桥形成一棵树,原图不连通则形成森林
		for(int i=1;i<=dcc;i++) g[i].clear();
		for(int i=0;i<b.size();i++) {
			int u=c[e[b[i]].FI],v=c[e[b[i]].SE];
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	//直径
	int dist[N],mx;
	void dfs1(int u,int fa) {
		for(auto v:g[u]) {
			if(v==fa) continue;
			dist[v]=dist[u]+1;
			if(dist[v]>dist[mx]) mx=v;
			dfs1(v,u);
		}
	}
	//solve
	void solve() {
		while(~scanf("%d%d",&n,&m)) {
			if(n==0&&m==0) break;
			init();
			for(int i=1;i<=m;i++) {
				int u,v;
				scanf("%d%d",&u,&v);
				addedge(u,v);
			}
			get_bridge();
			shrink();
			build();
			for(int i=1;i<=dcc;i++) dist[i]=0;
			mx=0;
			dfs1(1,0);
			for(int i=1;i<=dcc;i++) dist[i]=0;
			int u=mx;
			mx=0;
			dfs1(u,0);
			printf("%d\n",SZ(b)-dist[mx]);
		}
		
	}
}e_dcc;
int main() {
    //freopen("in.txt","r",stdin);
    e_dcc.solve();
    return 0;
}