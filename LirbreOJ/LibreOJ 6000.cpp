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
const int N=105;
int n,m,match[N];
bool f[N][N],st[N];
bool dfs(int u) {
    for(int v=1;v<=m;v++) {
        if(!f[v][u]||st[v]) continue;
        st[v]=true;
        if(match[v]==-1||dfs(match[v])) {
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int u,v;
    while(~scanf("%d%d",&u,&v)) f[u][v]=true;
    for(int i=1;i<=m;i++) match[i]=-1;
    int res=0;
    for(int i=m+1;i<=n;i++) {
        for(int j=1;j<=m;j++) st[j]=false;
        if(dfs(i)) res++;
    }
    printf("%d\n",res);
    return 0;
}