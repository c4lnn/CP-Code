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
int n,m,k,match[N],oldmatch[N];
bool st[N],vis[N][N];
VI g[N];
bool dfs(int u) {
    for(int v=1;v<=m;v++) {
        if(!vis[u][v]||st[v]) continue;
        st[v]=true;
        if(match[v+n]==-1||dfs(match[v+n])) {
            match[u]=v+n;
            match[v+n]=u;
            return true;
        }
    }
    return false;
}
int hungary() {
    for(int i=1;i<=n+m;i++) match[i]=-1;
    int res=0;
    for(int i=1;i<=n;i++) {
        if(match[i]!=-1) continue;
        for(int j=1;j<=n+m;j++) st[j]=false;
        if(dfs(i)) res++;
    }
    return res;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    int cs=0;
    while(~scanf("%d%d%d",&n,&m,&k)) {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                vis[i][j]=false;
        for(int i=1;i<=k;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            vis[x][y]=true;
        }
        int mx=hungary(),res=0;
        for(int i=1;i<=n+m;i++) oldmatch[i]=match[i];
        for(int i=1;i<=n;i++) {
            vis[i][oldmatch[i]-n]=false;
            if(hungary()<mx) res++;
            vis[i][oldmatch[i]-n]=true;
        }
        printf("Board %d have %d important blanks for %d chessmen.\n",++cs,res,mx);
    }
    return 0;
}