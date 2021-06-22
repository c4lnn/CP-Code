#include<bits/stdc++.h>

using namespace std;

const int N=105;

int n,m;
int s[N][N];

int calc(int a,int b,int c,int d) {
    return s[c][d]-s[a-1][d]-s[c][b-1]+s[a-1][b-1];
}
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;cin>>T;
    while(T--) {
        cin>>m>>n;
        int now=0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                int x;
                cin>>x;
                now+=x*(i-1+j-1);
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;
            }
        }
        int res=0x3f3f3f3f;
        for(int i=1;i<=n;i++) {
            for(int j=1,t=now;j<=m;j++) {
                res=min(res,t);
                t+=calc(1,1,n,j)-calc(1,j+1,n,m);
            }
            now+=calc(1,1,i,m)-calc(i+1,1,n,m);
        }
        cout<<res<<endl;
    }
    return 0;
}