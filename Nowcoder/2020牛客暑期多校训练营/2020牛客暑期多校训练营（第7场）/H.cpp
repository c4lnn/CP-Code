#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
int main() {
    long long n,k;
    scanf("%lld%lld",&n,&k);
    long long res=0;
    if(k>n) res=(k-n)%MOD,k=n;
    res=((res-1+n)%MOD+k)%MOD;
    n--;
    for(long long l=2,r;l<=k;l=r+1) {
        if(n/l) r=min(k,n/(n/l));
        else r=k;
        res=(res+((r-l+1)%MOD*((n/l)%MOD))%MOD)%MOD;
    }
    n++;
    for(long long l=2,r;l<=k;l=r+1) {
        if(n/l) r=min(k,n/(n/l));
        else r=k;
        res=(res+((r-l+1)%MOD*((n/l)%MOD))%MOD)%MOD;
    }
    printf("%lld\n",res);
    return 0;
}