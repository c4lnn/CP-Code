#include<bits/stdc++.h>
using namespace std;
const int mod=1e6+3;
long long a[mod+1];
int main()
{
    a[1]=1;
    for(int i=2;i<mod;i++) a[i]=i*a[i-1]%mod;
    int n;
    while(~scanf("%d",&n))
    {
        if(n>=mod) printf("0\n");
        else printf("%lld\n",a[n]);
    }
    return 0;
}