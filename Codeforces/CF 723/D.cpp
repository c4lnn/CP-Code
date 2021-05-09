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
const int DIR[4][2]={0,1,0,-1,1,0,-1,0};
const int N=55;
int tot[N*N],cnt,n,m,k,f[N][N];
bool ff,vis[N*N];
char s[N][N];
VPII a;
void dfs(int x,int y) {
    f[x][y]=cnt;
    if(x==1||x==n||y==1||y==m) ff=true;
    ++tot[cnt];
    for(int i=0;i<4;i++) {
        int tx=x+DIR[i][0],ty=y+DIR[i][1];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!f[tx][ty]&&s[tx][ty]=='.') {
            dfs(tx,ty);
        }
    }
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>s[i]+1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!f[i][j]&&s[i][j]=='.') {
                ++cnt;
                ff=false;
                dfs(i,j);
                if(!ff) a.EB(tot[cnt],cnt);
            }
    sort(ALL(a));
    int res=0;
    for(int i=0;i<SZ(a)-k;i++) vis[a[i].SE]=true,res+=a[i].FI;
    cout<<res<<'\n';
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(vis[f[i][j]]) cout<<'*';
            else cout<<s[i][j];
        }
        cout<<'\n';
    }
    return 0;
}