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
const int N=1005;
int n,match[N];
bool st[N],f[N][N];
bool dfs(int u) {
    for(int v=0;v<n;v++) {
        if(!f[u][v]||st[v]) continue;
        st[v]=true;
        if(match[v]==-1||dfs(match[v])) {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    while(~scanf("%d",&n)) {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                f[i][j]=false;
        for(int i=0;i<n;i++) {
            int u,k;
            scanf("%d: (%d)",&u,&k);
            for(int j=1;j<=k;j++) {
                int v;
                scanf("%d",&v);
                f[u][v]=true;
            }
        }
        int res=n;
        for(int i=0;i<n;i++) match[i]=-1;
        for(int i=0;i<n;i++) {
            if(match[i]!=-1) continue;
            for(int j=0;j<n;j++) st[j]=false;
            if(dfs(i)) res--;
        }
        printf("%d\n",res);
    }
    return 0;
}