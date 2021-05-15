#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int N=205;
int n;
bool st[N];
double dist[N];
vector<pair<int,double> > G[N];
pair<double,double> a[N];
double dijkstra() {
	priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int > > > q;
	for(int i=1;i<=n;i++) dist[i]=2e9,st[i]=false;
	q.push(make_pair(0,1));
	dist[1]=0;
	while(!q.empty()) {
		int u=q.top().second;
		q.pop();
		if(u==2) break;
		if(st[u]) continue;
		st[u]=true;
		for(int i=0;i<G[u].size();i++) {
			int v=G[u][i].first;
			double w=G[u][i].second;
			if(st[v]) continue;
			if(dist[v]>max(dist[u],w)) {
				dist[v]=max(dist[u],w);
				q.push(make_pair(dist[v],v));
			}
		}
	}
	return dist[2];
}
int main() {
    for(int k=1;;k++) {
    	scanf("%d",&n);
    	if(!n) return 0;
    	for(int i=1;i<=n;i++) G[i].clear();
    	for(int i=1;i<=n;i++) {
    		scanf("%lf%lf",&a[i].first,&a[i].second);
    		for(int j=1;j<i;j++) {
    			double w=sqrt((a[i].first-a[j].first)*(a[i].first-a[j].first)+(a[i].second-a[j].second)*(a[i].second-a[j].second));
    			G[i].push_back(make_pair(j,w));
    			G[j].push_back(make_pair(i,w));
    		}
    	}
    	printf("Scenario #%d\n",k);
    	printf("Frog Distance = %.3f\n\n",dijkstra());
    }
    return 0;
}