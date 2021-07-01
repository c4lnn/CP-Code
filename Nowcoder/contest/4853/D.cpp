#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
//head
const int N=100010;
ll a,b,c,k,dist[N],tot[N][2];
vector<pair<int,ll>>g[N];
bool st[N];
void dijkstra() {
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
    memset(dist,0x3f,sizeof dist);
    q.push({0,0});
    dist[0]=0;
    while(q.size()) {
        int u=q.top().se;
        q.pop();
        if(st[u]) continue;
        st[u]=true;
        for(auto x:g[u]) {
            int v=x.fi;
            ll w=x.se;
            if(st[v]) continue;
            if(dist[v]>dist[u]+w) dist[v]=dist[u]+w,tot[v][w!=b]=tot[u][w!=b]+1,tot[v][w==b]=tot[u][w==b],q.push({dist[v],v});
        }
    }
}
int main() {
    scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
    for(int i=0;i<a;i++) g[i].pb({(i+b)%a,b}),g[i].pb({(i+c)%a,c});
    dijkstra();
    printf("%lld %lld %lld\n",(k-dist[k%a])/a,tot[k%a][0],tot[k%a][1]);
    return 0;
}