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
const int N=1e3+5;
int cnt,tr[N][80],w[N];
bool st[N],vis[N][N];
VI g[N];
void insert(const string &s) {
    int u=1,pre=1;
    for(int i=0;s[i];i++) {
        int v=s[i]-'/';
        if(!tr[u][v]) tr[u][v]=++cnt;
        if(!v) {
            if(!vis[pre][u]) {
                vis[pre][u]=true;
                g[pre].PB(u);
            }
            pre=u;
        }
        u=tr[u][v];
    }
    vis[pre][u]=true;
    g[pre].PB(u);
}
void query(const string &s) {
    int u=1;
    for(int i=0;s[i];i++) {
        int v=s[i]-'/';
        if(!tr[u][v]) break;
        if(!v) st[u]=true;
        u=tr[u][v];
    }
}
void dfs(int u,int fa) {
    if(u!=1&&!st[u]) {w[u]=1;return;}
    w[u]=0;
    for(auto v:g[u]) dfs(v,u),w[u]+=w[v];
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=cnt;i++) st[i]=false,g[i].clear();
        for(int i=1;i<=cnt;i++)
            for(int j=1;j<=cnt;j++)
                vis[i][j]=false;
        memset(tr,0,sizeof tr);
        cnt=1;
        for(int i=1;i<=n;i++) {
            string s;
            cin>>s;
            insert(s);
        }
        for(int i=1;i<=m;i++) {
            string s;
            cin>>s;
            query(s);
        }
        dfs(1,0);
        printf("%d\n",w[1]);
    }
    return 0;
}