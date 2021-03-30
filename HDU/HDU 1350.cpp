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
const int N=505;
int m,match[N],t[N],x1[N],x2[N],y1[N],y2[N];
bool st[N],f[N][N];
bool dfs(int u) {
    for(int v=1;v<=m;v++) {
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
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d",&m);
        for(int i=1;i<=m;i++) {
            int a,b;
            scanf("%d:%d",&a,&b);
            t[i]=a*60+b;
            scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
        }
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                f[i][j]=false;
        for(int i=1;i<=m;i++)
            for(int j=i+1;j<=m;j++)
                if(t[j]-(t[i]+abs(x1[i]-x2[i])+abs(y1[i]-y2[i]))>abs(x1[j]-x2[i])+abs(y1[j]-y2[i]))
                    f[i][j]=true;
        for(int i=1;i<=m;i++) match[i]=-1;
        int res=m;
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=m;j++) st[j]=false;
            if(dfs(i)) res--;
        }
        printf("%d\n",res);
    }
    return 0;
}