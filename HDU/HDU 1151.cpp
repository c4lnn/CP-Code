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
const int N=150;
int n,m,match[N];
bool f[N][N],st[N];
bool dfs(int u) {
    for(int v=1;v<=n;v++) {
        if(!f[u][v]||st[v]) continue;
        st[v]=true;
        if(match[v]==-1||dfs(match[v])) {
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=false;
        for(int i=1;i<=m;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            f[u][v]=true;
        }
        int res=n;
        for(int i=1;i<=n;i++) match[i]=-1;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) st[j]=false;
            res-=dfs(i);
        }
        printf("%d\n",res);
    }
  return 0;
}