#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
const int N=1010;
int t,n;
vector<pii>g[N];
int dist[N];
bool st[N];
void dijkstra() {
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	priority_queue<pii,vector<pii>,greater<pii> >q;
	q.push(mp(0,1));
	while(q.size()) {
		int u=q.top().se;
		q.pop();
		if(st[u]) continue;
		st[u]=true;
		for(int i=0;i<g[u].size();i++) {
			int v=g[u][i].fi,w=g[u][i].se;
			if(st[v]) continue;
			if(dist[u]+w<dist[v]) {
				dist[v]=dist[u]+w;
				q.push(mp(dist[v],v));
			}
		}
	}
	cout<<dist[n]<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t>>n;
    for(int i=1;i<=t;i++) {
    	int u,v,w;
    	cin>>u>>v>>w;
    	g[u].pb(mp(v,w));
    	g[v].pb(mp(u,w));
    }
    dijkstra();
    return 0;
}