#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
const int N=100010;
int n,m,s;
vector<pii>edge[N];
ll f[N];
void dfs(int u,int fa,ll w) {
	ll tot=0;
	for(auto x:edge[u]) {
		if(x.fi==fa) continue;
		dfs(x.fi,u,x.se);
		tot+=f[x.fi];
	}
	if(tot) f[u]=min(w,tot);
	else f[u]=w;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++) {
    	int u,v,w;
    	cin>>u>>v>>w;
    	edge[u].pb({v,w});
    	edge[v].pb({u,w});
    }
    memset(f,0x3f,sizeof f);
    dfs(s,0,1e18);
    cout<<f[s]<<endl;
    return 0;
}