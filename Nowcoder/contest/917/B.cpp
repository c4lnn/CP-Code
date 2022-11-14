#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    long long  n;
    while(t--)
    {
        scanf("%lld",&n);
        int ans=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0) ans+=2;
            if(i*i==n) ans--;
        }
        printf("%d\n",ans);
    }
    return 0;
}