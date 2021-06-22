#include<bits/stdc++.h>

using namespace std;

int n;
int dp[2100][11];
int dist[11][11];

struct node {
    int x,y;
}pap[11];
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        int row,col;
        cin>>row>>col;
        cin>>pap[0].x>>pap[0].y;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>pap[i].x>>pap[i].y;
        for(int i=0;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                dist[j][i]=dist[i][j]=abs(pap[j].x-pap[i].x)+abs(pap[j].y-pap[i].y);
        int lim=(1<<(n+1))-1;
        memset(dp,0x3f,sizeof dp);
        dp[1][0]=0;
        for(int i=1;i<=lim;i++)
            for(int j=0;j<=n;j++)
                if(i&(1<<j))
                    for(int k=0;k<=n;k++)
                        if((i-(1<<j))&(1<<k))
                            dp[i][j]=min(dp[i][j],dp[i-(1<<j)][k]+dist[k][j]);
        int res=0x3f3f3f3f;
        for(int i=1;i<=n;i++) res=min(res,dp[lim][i]+dist[0][i]);
        cout<<"The shortest path has length "<<res<<endl;
    }
    return 0;
}