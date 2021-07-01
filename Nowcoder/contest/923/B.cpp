#include<stdio.h>
typedef long long ll;
const int maxn=1e5+5;
const int mod=10000008;
int T;
int n,m;
ll t;
ll a,b;
ll fac[maxn];
int main()
{
    fac[0]=1;
    for(int i=1;i<=100000;i++)
        fac[i]=fac[i-1]*i%mod;
    scanf("%d",&T);
    while(T--)
    {
        a=b=1;
        scanf("%d%d",&n,&m);
        while(n--)
        {
            scanf("%lld",&t);
            a=a*fac[t]%mod;
        }
        while(m--)
        {
            scanf("%lld",&t);
            b=b*fac[t]%mod;
        }
        if(a==b) printf("equal\n");
        else printf("unequal\n");
    }
    return 0;
}