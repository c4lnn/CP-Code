#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
signed main()
{
    int T;
    scanf("%lld",&T);
    int a,b;
    while(T--)
    {
        scanf("%lld%lld",&a,&b);
        int ans=a&b;
        if(ans) printf("%lld\n",ans);
        else printf("1\n");
    }
    return 0;
}