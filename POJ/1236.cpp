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
const int N=105;
int n;
vector<int> G[N];
struct SCC {
	//强连通分量	
	int cnt,dfn[N],low[N],top,stack[N],cnt_scc,c[N];
	bool ins[N];
	vector<int> scc[N];
	void tarjan(int u) {
		dfn[u]=low[u]=++cnt;
		stack[++top]=u;
		ins[u]=true;
		for(int i=0;i<SZ(G[u]);i++) {
			int v=G[u][i];
			if(!dfn[v]) {
				tarjan(v);
				low[u]=min(low[u],low[v]);
			}
			else if(ins[v]) low[u]=min(low[u],dfn[v]);
			
		}
		if(dfn[u]==low[u]) {
			++cnt_scc;
			int x;
			do {
				x=stack[top--];
				ins[x]=false;
				c[x]=cnt_scc;
				scc[cnt_scc].push_back(x);
			} while(u!=x);
		}
	}
	void shrink() {
		for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	}
	//缩点建图
	vector<int> g[N];
	void build_scc_tree() {
		for(int i=1;i<=n;i++)
			for(int j=0;j<G[i].size();j++) {
				int u=c[i],v=c[G[i][j]];
				if(u==v) continue;
				g[u].push_back(v);
			}
	}
	//solve
	bool st[N];
	int p,q,in[N],out[N];
	void solve() {
		int res=cnt_scc;
		for(int i=1;i<=cnt_scc;i++)
			for(int j=0;j<g[i].size();j++) {
				in[i]++;
				out[g[i][j]]++;
				if(!st[g[i][j]]) {
					st[g[i][j]]=true;
					res--;
				}
			}
		printf("%d\n",res);
		for(int i=1;i<=cnt_scc;i++) {
			if(!in[i]) p++;
			if(!out[i]) q++;
		}
		printf("%d\n",cnt_scc==1?0:max(p,q));
	}
}scc;
int main() {
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int u=1;u<=n;u++) {
    	int v;
    	while(~scanf("%d",&v)&&v) G[u].PB(v);
    }
	scc.shrink();
	scc.build_scc_tree();
	scc.solve();
    return 0;
}