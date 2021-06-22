#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    int a,b,c;
    int t1,t2;
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&c);
        t1=t2=0;
        t1=min(a,b>>1);
        if(b-t1*2) t2=min(b-t1*2,c/2);
        int ans=(t1+t2)*3;
        t1=t2=0;
        t1=min(b,c>>1);
        if(b-t1) t2=min((b-t1)/2,a);
        ans=max(ans,(t1+t2)*3);
        printf("%d\n",ans);
     }
    return 0;
}