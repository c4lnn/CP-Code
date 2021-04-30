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
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=305;
int n,m,b[N*2];
bool st[N];
LL dist[N][N];
LL check() {
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) cin>>b[i];
    for(int i=1;i<=n;i++) st[i]=false;
    LL sum=0;
    int cnt=0;
    for(int i=1;i<=t;i++) {
        if(!st[b[i]]) st[b[i]]=true,++cnt;
        else return -1;
        if(dist[b[i-1]][b[i]]==0x3f3f3f3f3f3f3f3f) return -1;
        sum+=dist[b[i-1]][b[i]];
        if(i==t) {
            if(dist[b[i]][0]==0x3f3f3f3f3f3f3f3f) return -1;
            sum+=dist[b[i]][0];
        }
    }
    if(cnt<n) return -1;
    return sum;
}
int main() {
    #ifdef DEBUG
        freopen("E:/OneDrive/IO/in.txt","r",stdin);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    memset(dist,0x3f,sizeof dist);
    for(int i=1;i<=m;i++) {
        int u,v;
        LL w;
        cin>>u>>v>>w;
        dist[u][v]=dist[v][u]=w;
    }
    int k;
    cin>>k;
    LL res=LLONG_MAX;
    for(int i=1;i<=k;i++) {
        LL ret=check();
        if(ret!=-1) res=min(res,ret);
    }
    cout<<(res==LLONG_MAX?-1:res)<<'\n';
    return 0;
}