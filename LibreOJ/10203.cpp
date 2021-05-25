#include<bits/stdc++.h>
#define int long long
using namespace std;
int ps[]={2,3,5,7,11,13,17,19,23,29};
int n;
int ans=0;
int maxn=0;
int qpow(int n,int c)
{
    int res=1;
    while(c)
    {
        if(c&1) res*=n;
        n*=n;
        c>>=1;
    }
    return res;
}
void dfs(int num,int ci,int res,int cnt)
{
    if(num==9)
    {
        if(cnt>maxn) maxn=cnt,ans=res;
        else if(cnt==maxn) ans=min(ans,res);
        return;
    }
    for(int j=0;j<=ci;j++)
    {
        if(res*qpow(ps[num],j)>n) break;
        dfs(num+1,j,res*qpow(ps[num],j),cnt*(j+1));
    }
}
signed main()
{
    scanf("%lld",&n);
    dfs(0,log(n)/log(2),1,1);
    printf("%lld",ans);
    return 0;
}