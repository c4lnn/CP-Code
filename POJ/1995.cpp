#include<cstdio>
using namespace std;
#define ll long long
ll a,b,mod;
ll ksm(ll x,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=(res*x)%mod;
		x=x*x%mod;
		b>>=1;
	}
	return res%mod;
}
int main()
{
	int t,tt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&mod,&tt);
		ll ans=0;
		while(tt--)
		{
			scanf("%d%d",&a,&b);
			ans=(ans+ksm(a,b))%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}