#include<bits/stdc++.h>

using namespace std;

const int N=305;

int n,m;
int w[N];
int dp[N][N];
vector<int>son[N];

void dfs(int u) {
    for(auto x:son[u]) {
        dfs(x);
        for(int t=m;t;t--)
            for(int j=1;j<=t;j++)//当u为0时，u不占体积，因此j可以等于t
                dp[u][t]=max(dp[u][t],dp[u][t-j]+dp[x][j]);
    }
    if(u) for(int t=m;t;t--) dp[u][t]=dp[u][t-1]+w[u];//当u不为0时，u占一格体积
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        son[a].push_back(i);
        w[i]=b;
    }
    dfs(0);
    cout<<dp[0][m]<<endl;
    return 0;
}