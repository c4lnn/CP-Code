#include<bits/stdc++.h>
using namespace std;
const int N=205;
long long a[N][N],s[N][N];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%lld",&a[i][j]);
        double res=0;
        for(int j=1;j<=m;j++)
            for(int i=1;i<=n;i++) {
                s[i][j]=s[i-1][j]+a[i][j];
                res=max(res,(double)s[i][j]/a[i][j]);
            }
        printf("%.8f\n",res);
    }
    return 0;
}