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
const int dir[4][2]={-1,0,1,0,0,-1,0,1};
int n,m,match[N*N];
bool st[N*N],f[N][N];
VI g[N*N];
bool valid(int x,int y) {
    if(x>=0&&x<n&&y>=0&&y<m&&!f[x][y]) return true;
    return false;
}
bool dfs(int u) {
    for(auto v:g[u]) {
        if(st[v]) continue;
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
    while(~scanf("%d%d",&n,&m)) {
        if(!n&&!m) break;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                f[i][j]=false,g[i*m+j].clear();
        int t;
        scanf("%d",&t);
        for(int i=1;i<=t;i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            f[x-1][y-1]=true;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) {
                if(f[i][j]) continue;
                for(int k=0;k<4;k++) {
                    int tx=i+dir[k][0],ty=j+dir[k][1];
                    if(valid(tx,ty)) g[i*m+j].PB(tx*m+ty);
                }
            }
        int res=0;
        for(int i=0;i<n*m;i++) match[i]=-1;
        for(int i=0;i<n*m;i++) {
            if(f[i/m][i%m]||match[i]!=-1) continue;
            for(int j=0;j<n*m;j++) st[j]=false;
            if(dfs(i)) res++;
        }
        printf("%d\n",res);
        for(int i=0;i<n*m;i++) {
            if(match[i]!=-1) {
                printf("(%d,%d)--(%d,%d)\n",i/m+1,i%m+1,match[i]/m+1,match[i]%m+1);
                match[match[i]]=-1;
            }
        }
        puts("");
    }
    return 0;
}