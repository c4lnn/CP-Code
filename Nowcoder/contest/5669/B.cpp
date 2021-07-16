#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
const int N=1e6+5;
long long mx[N];
long long get(long long x,long long c) {
    if(mx[x]==1) return c;
    return c*get(mx[x],c)%MOD;
}
int main() {
    for(long long i=500000;i>=1;i--)
        for(long long j=2;j*i<=1000000;j++)
            if(!mx[i*j]) mx[i*j]=i;
    int T;
    scanf("%d",&T);
    while(T--) {
        long long n,c;
        scanf("%lld%lld",&n,&c);
        if(n==1) puts("1");
        else printf("%lld\n",get(n,c));
    }
    return 0;
}
