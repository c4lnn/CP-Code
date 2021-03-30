#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int N=505;
struct E {
	int u,v,w;
	E() {}
	E(int u,int v,int w):u(u),v(v),w(w) {}
	bool operator < (const E &a) const {
		return w<a.w;
	}
}mn[N],mx[N];
int n,m,k,dist[N][N],fa[N],id[N],vis[N];
bool st[N][N];
vector<E> e;
map<string,int> mp;
int find(int x) {
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int kruskal() {
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e.begin(),e.end());
	int res=0;
	for(int i=0;i<e.size();i++)
		if(id[e[i].u]==id[e[i].v]) {
			int tx=find(e[i].u),ty=find(e[i].v);
			if(tx==ty) continue;
			fa[tx]=ty;
			res+=e[i].w;
			st[e[i].u][e[i].v]=st[e[i].v][e[i].u]=true;
		}
	return res;
}
void dfs1(int u,int t) {
	id[u]=t;
	for(int i=2;i<=n;i++) if(dist[u][i]&&!id[i]) dfs1(i,t);
}
void dp(int u,int fa) {
	for(int i=2;i<=n;i++) {
		if(i==fa||!st[u][i]) continue;
		if(u!=1) {
			if(mx[u].w>dist[u][i]) mx[i]=mx[u];
			else mx[i]=E(u,i,dist[u][i]);
		}
		dp(i,u);
	}
}
int solve() {
	int t=0;
	for(int i=2;i<=n;i++) if(!id[i]) dfs1(i,++t);
	int res=kruskal();
	for(int i=1;i<=t;i++) mn[i].w=0x3f3f3f3f;
	for(int i=2;i<=n;i++) if(dist[1][i]&&dist[1][i]<mn[id[i]].w) mn[id[i]]=E(1,i,dist[1][i]);
	for(int i=2;i<=n;i++) {
		if(vis[id[i]]) continue;
		st[1][mn[id[i]].v]=st[mn[id[i]].v][1]=true;
		res+=mn[id[i]].w;
		vis[id[i]]=true;
		k--;
	}
	while(k) {
		mx[1].w=0xc0c0c0c0;
		for(int i=2;i<=n;i++) {
			if(st[1][i]) mx[i].w=0xc0c0c0c0;
			else mx[i].w=0;
		}
		dp(1,0);
		int temp=1;
		for(int i=2;i<=n;i++) {
			if(st[1][i]||!dist[1][i]) continue;
			if(dist[1][i]-mx[i].w<dist[1][temp]-mx[temp].w) temp=i;
		}
		st[1][temp]=st[temp][1]=true;
		st[mx[temp].u][mx[temp].v]=st[mx[temp].v][mx[temp].u]=false;
		if(dist[1][temp]-mx[temp].w>0) break;
		res+=dist[1][temp]-mx[temp].w;
		k--;
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	mp["Park"]=++n;
    cin>>m;
    for(int i=1;i<=m;i++) {
    	string a,b;
    	int w;
    	cin>>a>>b>>w;
    	if(!mp.count(a)) mp[a]=++n;
    	if(!mp.count(b)) mp[b]=++n;
    	dist[mp[a]][mp[b]]=dist[mp[b]][mp[a]]=w;
    	e.push_back(E(mp[a],mp[b],w));
    }
    cin>>k;
    cout<<"Total miles driven: "<<solve()<<'\n';
    return 0;
}