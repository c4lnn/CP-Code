#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

const int N=1e6+5;

int n;
ll s[N];
ll sum;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&s[i]),sum+=s[i];
    ll t=sum/n;
    for(int i=1;i<=n;i++) s[i]+=s[i-1]-t;
    sort(s+1,s+1+n);
    ll mid=s[1+n>>1];
    ll ans=0;
    for(int i=1;i<=n;i++) ans+=abs(s[i]-mid);
    printf("%lld\n",ans);
    return 0;
}