#include<bits/stdc++.h>
using namespace std;
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        if(m&1) puts("No");
        else if(n==1&&m==4) puts("Yes\n1 1");
        else {
            int t=sqrt(n);
            int c=n/t*2+(t-2)*2;
            if(m<4+c+((n-n/t*t)?2:0)||m>4*n) puts("No");
            else if(m>4+(n-1)*2) {
                puts("Yes");
                int cnt=(m-4-(n-1)*2)/2;
                for(int i=1;i<=n-cnt;i++) printf("0 %d\n",i);
                for(int i=1;i<=cnt;i++) printf("%d 0\n",2*i);
            }
            else {
                puts("Yes");
                int cnt=(m-4-c-((n-n/t*t)?2:0))/2;
                int d=n-n/t*t;
                if(d) {
                    for(int i=1;i<=max(1,d-cnt);i++) printf("%d %d\n",t+1,i);
                    for(int i=1;i<=min(cnt,d-1);i++) printf("%d 1\n",t+1+i);
                    cnt-=d-1;
                    if(cnt<0) cnt=0;
                }
                int a=cnt/(n/t-1),b=cnt%(n/t-1);
                for(int i=1;i<=t;i++)
                    for(int j=1;j<=n/t;j++) {
                        if(j==2&&i>t-a) break;
                        if(t-a==i&&j>n/t-b) break;
                        printf("%d %d\n",i,j);
                    }
                for(int i=1;i<=cnt;i++) printf("%d 1\n",1-i);
            }
        }
    }
    return 0;
}