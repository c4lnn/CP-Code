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
const int DIR[12][2]={-1,-2,-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2,-1,0,0,1,1,0,0,-1};
const int N=55;
int n,m,match[N*N],a[N][N];
bool st[N*N];
VI g[N*N];
bool valid(int x,int y) {
    if(x>=0&&x<n&&y>=0&&y<m&&a[x][y]!=-1) return true;
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
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int cs=0;
    while(~scanf("%d%d",&n,&m)) {
        if(!n&&!m) break;
        for(int i=0;i<n*m;i++) g[i].clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) {
                if(a[i][j]==-1) continue;
                for(int k=0;k<12;k++)
                    if((1<<k)&a[i][j]) {
                        int tx=i+DIR[k][0],ty=j+DIR[k][1];
                        if(!valid(tx,ty)) continue;
                        g[i*m+j].PB(tx*m+ty);
                        g[tx*m+ty].PB(i*m+j);
                    }
            }
        for(int i=0;i<n*m;i++) match[i]=-1;
        int res=0;
        for(int i=0;i<n*m;i++) {
            if(match[i]!=-1) continue;
            for(int j=0;j<n*m;j++) st[j]=false;
            if(dfs(i)) res++;
        }
        printf("%d. %d\n",++cs,res);
    }
    return 0;
}