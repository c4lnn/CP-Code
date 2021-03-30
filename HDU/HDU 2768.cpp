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
int n,a,b,match[N];
bool f[N][N],st[N];
PII p[N];
bool dfs(int u) {
    for(int v=1;v<=n;v++) {
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
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d%d%d",&a,&b,&n);
        for(int i=1;i<=n;i++) {
            char c;
            int d;
            scanf(" %c%d",&c,&d);
            p[i].FI=(c=='C'?d:d+a);
            scanf(" %c%d",&c,&d);
            p[i].SE=(c=='C'?d:d+a);
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=false;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(p[i].FI==p[j].SE||p[i].SE==p[j].FI)
                    f[i][j]=f[j][i]=true;
        for(int i=1;i<=n;i++) match[i]=-1;
        int res=n;
        for(int i=1;i<=n;i++) {
            if(match[i]!=-1) continue;
            for(int j=1;j<=n;j++) st[j]=false;
            if(dfs(i)) res--;
        }
        printf("%d\n",res);
    }
    return 0;
}