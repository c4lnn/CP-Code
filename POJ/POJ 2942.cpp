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
//head
const int N=1e3+5;
int n,m;
bool st[N][N];
vector<int> G[N];
struct V_DCC {
	int root,cnt,cnt_dcc,top,dfn[N],low[N],stack[N];
	bool cut[N];
	vector<int> dcc[N];
	void tarjan(int u) {
		dfn[u]=low[u]=++cnt;
		stack[++top]=u;
		if(u==root&&!G[u].size()) {//孤立点
			dcc[++cnt_dcc].push_back(u);
			return;
		}
		int flag=0;
		for(int i=0;i<G[u].size();i++) {
			int v=G[u][i];
			if(!dfn[v]) {
				tarjan(v);
				low[u]=min(low[u],low[v]);
				if(dfn[u]<=low[v]) {
					flag++;
					if(u!=1||flag>1) cut[u]=true;
					++cnt_dcc;
					int x;
					do {
						x=stack[top--];
						dcc[cnt_dcc].push_back(x);
					} while(x!=v);
					dcc[cnt_dcc].push_back(u);
				}
			}
			else low[u]=min(low[u],dfn[v]);
		}
	}
	//solve
	vector<int> g[N];
	int col[N];
	bool dfs(int u,int t) {
		col[u]=t;
		for(int i=0;i<g[u].size();i++) {
			int v=g[u][i];
			if(col[v]==t) return false;
			if(!col[v]&&!dfs(v,3-t)) return false;
		}
		return true;
	}
	bool vis[N];
	void solve() {
		for(int i=1;i<=cnt_dcc;i++) dcc[i].clear();
		cnt=cnt_dcc=top=0;
		for(int i=1;i<=n;i++) dfn[i]=low[i]=0;
		for(int i=1;i<=n;i++) cut[i]=vis[i]=false;
		for(int i=1;i<=n;i++) if(!dfn[i]) root=i,tarjan(i);
		for(int i=1;i<=cnt_dcc;i++) {
			if(dcc[i].size()==1) continue;
			for(int j=0;j<dcc[i].size();j++) g[dcc[i][j]].clear(),col[dcc[i][j]]=0;
			for(int j=0;j<dcc[i].size();j++)
				for(int k=0;k<j;k++) { 
					int u=dcc[i][j],v=dcc[i][k];
					if(st[u][v]) continue;
					g[u].push_back(v);
					g[v].push_back(u);
				}
			if(!dfs(dcc[i][0],1)) {
				for(int j=0;j<dcc[i].size();j++)
					vis[dcc[i][j]]=true;
			}
		}
		int res=0;
		for(int i=1;i<=n;i++) if(!vis[i]) ++res;
		printf("%d\n",res);
	}
}v_dcc;
int main() {
	//freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
    	if(n==0&&m==0) break;
    	for(int i=1;i<=n;i++)
    		for(int j=1;j<i;j++)
    			st[i][j]=st[j][i]=0;
    	for(int i=1;i<=n;i++) G[i].clear();
	    for(int i=1;i<=m;i++)  {
	    	int u,v;
	    	scanf("%d%d",&u,&v);
	    	st[u][v]=st[v][u]=true;
	    }
	   	for(int i=1;i<=n;i++)
	   		for(int j=1;j<i;j++) {
	   			if(st[i][j]) continue;
   				G[i].push_back(j);
   				G[j].push_back(i);
	   		}
	   	v_dcc.solve();
    }
    return 0;
}