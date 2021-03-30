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
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int DIR[8][2]={-1,-2,-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2};
const int N=205;
bool vis[N][N];
int n,m,match[N*N],dep[N*N];
VI p;
bool bfs() {
    queue<int> q;
    for(int i=0;i<n*n;i++) dep[i]=0;
    for(auto x:p) if(!vis[x/n][x%n]&&match[x]==-1) dep[x]=1,q.push(x);
    bool f=false;
    while(SZ(q)) {
        int u=q.front();
        q.pop();
        int x=u/n,y=u%n;
        for(int i=0;i<8;i++) {
            int tx=x+DIR[i][0],ty=y+DIR[i][1];
            if(tx<0||tx>=n||ty<0||ty>=n||vis[tx][ty]) continue;
            int v=tx*n+ty;
            if(dep[v]) continue;
            dep[v]=dep[u]+1;
            if(match[v]==-1) f=true;
            else dep[match[v]]=dep[v]+1,q.push(match[v]);
        }
    }
    return f;
}
bool dfs(int u) {
    int x=u/n,y=u%n;
    for(int i=0;i<8;i++) {
        int tx=x+DIR[i][0],ty=y+DIR[i][1];
        if(tx<0||tx>=n||ty<0||ty>=n||vis[tx][ty]) continue;
        int v=tx*n+ty;
        if(dep[v]!=dep[u]+1) continue;
        dep[v]=0;
        if(match[v]==-1||dfs(match[v])) {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int HK() {
    for(int i=0;i<n*n;i++) match[i]=-1;
    int res=0;
    while(bfs()) for(auto x:p) if(!vis[x/n][x%n]&&match[x]==-1&&dfs(x)) res++;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int x,y;
        cin>>x>>y;
        vis[x-1][y-1]=true;
    }
    for(int i=0;i<n*n;i++) if((i/n+i%n)&1&&!vis[i/n][i%n]) p.PB(i);
    cout<<n*n-m-HK()<<'\n';
    return 0;
}