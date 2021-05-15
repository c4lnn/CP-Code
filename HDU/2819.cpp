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
int n,match[N<<1];
bool vis[N][N],st[N];
bool dfs(int u) {
    for(int v=1;v<=n;v++) {
        if(!vis[u][v]||st[v]) continue;
        st[v]=true;
        if(match[v+n]==-1||dfs(match[v+n])) {
            match[v+n]=u;
            match[u]=v+n;
            return true;
        }
    }
    return false;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    int tot=0;
    while(~scanf("%d",&n)) {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) {
                scanf("%d",&vis[i][j]);
            }
        for(int i=1;i<=n<<1;i++) match[i]=-1;
        int res=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) st[j]=false;
            if(dfs(i)) res++;
        }
        if(res!=n) puts("-1");
        else {
            VPII ans;
            for(int i=1;i<=n;i++) {
                if(match[i]==i+n) continue;
                int j=match[i];
                swap(match[match[i+n]],match[i]);
                swap(match[i+n],match[j]);
                ans.EB(i,j-n);
            }
            printf("%d\n",SZ(ans));
            for(auto x:ans) printf("C %d %d\n",x.FI,x.SE);
        }
    }
    return 0;
}
