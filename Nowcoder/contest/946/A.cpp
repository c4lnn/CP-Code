#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fi first
#define se second

#define lowbit(x) x&(-x)
#define mem(arr,val) memset(arr,val,sizeof arr)

typedef pair<int,int>pii;

const int maxn=2e5+5;
const int mod=1e9+7;
struct fs
{
    ll x;
    ll y;
}a[maxn];
bool cmp(fs a,fs b)
{
    return a.x*b.y>b.x*a.y;
}
ll ksm(ll x,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=res*x%mod;
        x=x*x%mod;
        b>>=1;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld%lld",&a[i].y,&a[i].x);
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {
        ll ans=a[i].x*ksm(a[i].y,mod-2)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}