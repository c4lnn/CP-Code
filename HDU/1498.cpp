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
int n,m,w[N][N],match[N];
bool st[N],f[N][N];
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
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        if(!n&&!m) break;
        int mx=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) {
                scanf("%d",&w[i][j]);
                mx=max(mx,w[i][j]);
            }
        VI ans;
        for(int k=1;k<=mx;k++) {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    f[i][j]=false;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(w[i][j]==k) f[i][j]=true;
            int res=0;
            for(int i=1;i<=n;i++) match[i]=-1;
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) st[j]=false;
                if(dfs(i)) res++;
            }
            if(res>m) ans.PB(k);
        }
        if(!SZ(ans)) puts("-1");
        else {
            sort(ALL(ans));
            for(int i=0;i<SZ(ans);i++) {
                if(i) putchar(' ');
                printf("%d",ans[i]);
            }
            puts("");
        }
    }
    return 0;
}