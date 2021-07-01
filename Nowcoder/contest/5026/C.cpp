#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
int f[15][30][30][30][30];
int st[15];
int tot[15];
int cnt;
vi g[15];
void dfs(int u,int cnt) {
    st[u]=cnt;
    tot[cnt]++;
    for(auto v:g[u]) {
        if(st[v]) continue;
        dfs(v,cnt);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,d,m;
    cin>>a>>b>>c>>d>>m;
    for(int i=1;i<=m;i++) {
        int x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    for(int i=1;i<=12;i++) if(!st[i]) dfs(i,++cnt);
    f[0][a][b][c][d]=1;
    for(int x=1;x<=cnt;x++)
        for(int i=a;i>=0;i--)
            for(int j=b;j>=0;j--)
                for(int k=c;k>=0;k--)
                    for(int l=d;l>=0;l--) {
                        f[x][i][j][k][l]=f[x-1][i+tot[x]][j][k][l]+f[x-1][i][j+tot[x]][k][l]+f[x-1][i][j][k+tot[x]][l]+f[x-1][i][j][k][l+tot[x]];
                    }
    cout<<f[cnt][0][0][0][0]<<endl;
    return 0;
}