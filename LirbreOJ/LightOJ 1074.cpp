#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=205;
int n,m,w[N],cnt[N],dist[N];
bool st[N];
VI g[N];
void spfa() {
    for(int i=1;i<=n;i++) cnt[i]=0,dist[i]=0x3f3f3f3f,st[i]=false;
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        st[u]=false;
        for(auto v:g[u]) {
            if(dist[v]>dist[u]+(int)pow(w[v]-w[u],3)) {
                dist[v]=dist[u]+(int)pow(w[v]-w[u],3);
                cnt[v]++;
                if(!st[v]&&cnt[v]<n) st[v]=true,q.push(v);
            }
        }
    }
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    //freopen("E:/OneDrive/Practice/out.txt","w",stdout);
    int tt;
    scanf("%d",&tt);
    for(int cs=1;cs<=tt;cs++) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<=n;i++) scanf("%d",&w[i]);
        scanf("%d",&m);
        for(int i=1;i<=m;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            g[u].PB(v);
        }
        spfa();
        scanf("%d",&m);
        printf("Case %d:\n",cs);
        for(int i=1;i<=m;i++) {
            int x;
            scanf("%d",&x);
            if(cnt[x]>=n||dist[x]<3||dist[x]==0x3f3f3f3f) puts("?");
            else printf("%d\n",dist[x]);
        }
    }
    return 0;
}