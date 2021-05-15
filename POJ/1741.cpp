#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=10010;
const int M=20010;

int n,k;
int cnt,to[M],val[M],nxt[M],head[N];
bool st[N];
int dist[N],sze[N],all_node;
int a[N];
int cnt_dist;
int pos;
int res;
int ans;

void addedge(int u,int v,int w) {
	cnt++;
	to[cnt]=v;
	val[cnt]=w;
	nxt[cnt]=head[u];
	head[u]=cnt;
}
void get_root(int u,int pre) {
	sze[u]=1;
	int max_part=1;
	for(int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if(v==pre||st[v]) continue;
		get_root(v,u);	
		sze[u]+=sze[v];
		max_part=max(max_part,sze[v]);
	}
	max_part=max(max_part,all_node-sze[u]);
	if(max_part<res) {
		res=max_part;
		pos=u;
	}
}
void get_dist(int u,int pre) {
	a[++cnt_dist]=dist[u];
	for(int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if(v==pre||st[v]) continue;
		dist[v]=dist[u]+val[i];
		get_dist(v,u);
	}
}
int calc(int u,int t) {
	int sum=0;
	dist[u]=t;
	cnt_dist=0;
	get_dist(u,0);
	sort(a+1,a+1+cnt_dist);
	int l=1,r=cnt_dist;
	while(l<r) {
		if(a[l]+a[r]<=k) sum+=r-l,l++;
		else r--;
	}
	return sum;
}
void solve(int u) {
	st[u]=true;
	ans+=calc(u,0);
	for(int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if(st[v]) continue;
		ans-=calc(v,val[i]);
		res=n;
		all_node=sze[v];
		get_root(v,0);
		solve(pos);
	}
}
int main() {
 	ios::sync_with_stdio(false);
 	cin.tie(0);
	while(cin>>n>>k&&n) {
		cnt=0;
		memset(head,0,sizeof head);
		memset(st,false,sizeof st);
		ans=0;
		for(int i=1;i<n;i++) {
			int u,v,w;
			cin>>u>>v>>w;
			addedge(u,v,w);
			addedge(v,u,w);
		}
		res=n;
		all_node=n;
		get_root(1,0);
		solve(pos);
		cout<<ans<<endl;
	} 
 	return 0;
}