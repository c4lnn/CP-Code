#include <bits/stdc++.h>
using namespace std;
int s[5002][5002];
int main() {
    int n,r;
    int x,y,w;
    scanf("%d%d",&n,&r);
    int tx=r,ty=r;
    for(int i=0;i<n;i++) {
        scanf("%d%d%d",&x,&y,&w);
        s[++x][++y]=w;
        tx=max(tx,x);
        ty=max(ty,y);
    }
    int ans=0;
    for(int i=1;i<=tx;i++)
        for(int j=1;j<=ty;j++) {
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            if(i>=r&&j>=r) ans=max(ans,s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r]);
        }
    printf("%d\n",ans);
    return 0;
}