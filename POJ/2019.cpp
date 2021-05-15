#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=251;
int a[N][N],st1[N][N][8][8],st2[N][N][8][8];
void init(int n,int m) {
    int t1=log2(n);
    int t2=log2(m);
    for(int i=0;i<=t1;i++)
        for(int j=0;j<=t2;j++)
            for(int k=1;k<=n-(1<<i)+1;k++)
                for(int l=1;l<=m-(1<<j)+1;l++) {
                    if(!i&&!j) st1[k][l][i][j]=st2[k][l][i][j]=a[k][l];
                    else if(!i) {
                        st1[k][l][i][j]=max(st1[k][l][i][j-1],st1[k][l+(1<<j-1)][i][j-1]);
                        st2[k][l][i][j]=min(st2[k][l][i][j-1],st2[k][l+(1<<j-1)][i][j-1]);
                    }
                    else {
                        st1[k][l][i][j]=max(st1[k][l][i-1][j],st1[k+(1<<i-1)][l][i-1][j]);
                        st2[k][l][i][j]=min(st2[k][l][i-1][j],st2[k+(1<<i-1)][l][i-1][j]);
                    }
                }
}
int query(int x1,int y1,int x2,int y2) {
    int t1=log2(x2-x1+1);
    int t2=log2(y2-y1+1);
    int mx=max(max(st1[x1][y1][t1][t2],st1[x2-(1<<t1)+1][y1][t1][t2]),
               max(st1[x1][y2-(1<<t2)+1][t1][t2],st1[x2-(1<<t1)+1][y2-(1<<t2)+1][t1][t2]));
    int mn=min(min(st2[x1][y1][t1][t2],st2[x2-(1<<t1)+1][y1][t1][t2]),
               min(st2[x1][y2-(1<<t2)+1][t1][t2],st2[x2-(1<<t1)+1][y2-(1<<t2)+1][t1][t2]));
    return mx-mn;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,b,k;cin>>n>>b>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    init(n,n);
    while(k--) {
        int x,y;cin>>x>>y;
        cout<<query(x,y,x+b-1,y+b-1)<<'\n';
    }
    return 0;
}