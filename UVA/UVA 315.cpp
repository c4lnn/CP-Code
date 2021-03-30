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
const int N=105;
struct V_DCC {
	int n;
	vector<int> G[N];
	void init() {
		for(int i=1;i<=n;i++) G[i].clear();
	}
	// 点双连通分量
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
		for(auto v:G[u]) {
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
	void shrink() {
		for(int i=1;i<=cnt_dcc;i++) dcc[i].clear();
		cnt=cnt_dcc=top=0;
		for(int i=1;i<=n;i++) dfn[i]=low[i]=0,cut[i]=false;
		for(int i=1;i<=n;i++) if(!dfn[i]) root=i,tarjan(i);
	}
	void solve() {
		while(~scanf("%d",&n)&&n) {
			init();
			int u;
			while(~scanf("%d",&u)&&u) {
				while(1) {
					int v;
					char c;
					scanf("%d%c",&v,&c);
					G[u].PB(v);
					G[v].PB(u);
					if(c=='\n') break;
				}
			}
			shrink();
			int res=0;
			for(int i=1;i<=n;i++) if(cut[i]) res++;
			printf("%d\n",res);
		}
	}
}v_dcc;
int main() {
    v_dcc.solve();
    return 0;
}