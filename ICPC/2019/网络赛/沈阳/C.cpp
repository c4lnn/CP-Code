#include<bits/stdc++.h>
using namespace std;
int n,m,p[1005],w[1005],f[10005];
int main() {
    while(~scanf("%d%d",&n,&m)) {
        memset(f,0x3f,sizeof f);
        f[0]=0;
        int res=0x3f3f3f3f,maxw=0;
        for(int i=0;i<n;i++) scanf("%d%d",&p[i],&w[i]);
        for(int i=0;i<n;i++)
            for(int j=w[i];j<=10000;j++) {
                f[j]=min(f[j],f[j-w[i]]+p[i]);
                if(j>=m) {
                    if(res>f[j]) res=f[j],maxw=j;
                    else if(res==f[j]&&j>maxw) maxw=j;
                }
            }
        printf("%d %d\n",res,maxw);
    }
    return 0;
}