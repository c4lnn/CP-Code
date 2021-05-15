#include <iostream>
#include<cmath>

using namespace std;

typedef long long ll;
const ll mod=9901;

ll qPow(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll sum(ll a,ll n)
{
	if(n==0) return 1;
	else if(n&1) return (qPow(a,n/2+1)+1)*sum(a,n/2)%mod;
	else return ((qPow(a,n/2)+1)*sum(a,n/2-1)%mod+qPow(a,n))%mod;
	
}
int main()
{
	ll a,b;
	cin>>a>>b;
	if(!a)
	{
		cout<<0;
		return 0;
	}
	ll ans=1;
	ll t=a;
	for(ll i=2;i<=sqrt(t);i++)
		if(t%i==0)
		{
			ll cnt=0;
			while(t%i==0)
			{
				cnt++;
				t/=i;	
			}
			ans=ans*sum(i,cnt*b)%mod; 
		}
	if(t>1) ans=ans*sum(t,b)%mod;
	cout<<ans<<endl;
	return 0;
}