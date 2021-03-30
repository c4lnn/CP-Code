#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;

const int N=1e5+5;

int n,m;
int cnt,to[N*2],nxt[N*2],head[N];
int depth[N],f[N][20];
int d[N],s[N];
bool st[N];
int t;
int ans;

void addedge(int u,int v) {
	cnt++;
	to[cnt]=v;
	nxt[cnt]=head[u];
	head[u]=cnt;
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
			for(int i=1;i<=t;i++) f[v][i]=f[f[v][i-1]][i-1];
			q.push(v);
		}
	}
}
int lca(int a,int b) {
	if(depth[a]>depth[b]) swap(a,b);
	for(int i=t;i>=0;i--) if(depth[f[b][i]]>=depth[a]) b=f[b][i];
	if(a==b) return a;
	for(int i=t;i>=0;i--) if(f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
	return f[a][0];
}
void dfs(int u) {
	st[u]=true;
	for(int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if(st[v]) continue;
		dfs(v);
		s[u]+=s[v];
	}
	s[u]+=d[u];
}
int main() {
	scanf("%d%d",&n,&m);
	t=(int)log(n)/log(2)+1;
	for(int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	bfs();
	for(int i=1;i<=m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		d[a]++,d[b]++;
		d[lca(a,b)]-=2;
	}
	dfs(1);
	for(int i=2;i<=n;i++) {
		if(s[i]==0) ans+=m;
		else if(s[i]==1) ans++;
	}
	printf("%d\n",ans);
 	return 0;
}