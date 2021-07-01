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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const LL MOD=1023694381;
const int N=505;
int n,m,k,a[N],cnt[N];
LL dist[N][N];
void floyd() {
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(dist[i][j]==dist[i][k]+dist[k][j])
                    ++cnt[k];
}
LL qpow(LL a,LL b) {
    LL ret=1;
    while(b) {
        if(b&1) ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dist,0x3f,sizeof dist);
    for(int i=1;i<=n;i++) dist[i][i]=0;
    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=dist[v][u]=w;
    }
    floyd();
    LL res=0;
    LL C2=qpow(n*(n-1)/2,MOD-2);
    for(int i=1;i<=n;i++) {
        if(a[i]==1) ++res;
        else res=(res+(1+MOD-qpow((1+MOD-cnt[i]*C2%MOD)%MOD,k))%MOD)%MOD;
    }
    cout<<res<<'\n';
    return 0;
}