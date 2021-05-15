#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18+1; 
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int f(int n,int m)
{
    int i=n;
    int cnt=m;
    while(cnt) if(gcd(n,++i)==1) cnt--;
    return i;
} 
signed main()
{
    int T;
    scanf("%lld",&T);
    int k;
    int m;
    while(T--)
    {
        scanf("%lld%lld",&k,&m);
        int ans=inf;
        for(int i=1;i<=1000;i++)
        {
            int n=i^k;
            if(n&&f(n,m)==i+n) ans=min(ans,n);
        }
        if(ans==inf) printf("-1\n");
        else printf("%lld\n",ans);
    }
    return 0;
}