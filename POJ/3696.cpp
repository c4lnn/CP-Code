#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define int long long 
using namespace std;
int inf=0x7fffffff;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int phi(int n)
{
	int res=n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i!=0) continue;
		while(n%i==0) n/=i;
		res=res/i*(i-1);
	}
	if(n>1) res=res/n*(n-1);
	return res;
}
int qMul(int n,int a,int mod)
{
	n%=mod,a%=mod;
	int res=0;
	while(a)
	{
		if(a&1) res=(res+n)%mod;
		n=(n+n)%mod;
		a>>=1;	
	}	
	return res;
} 
int qPow(int n,int a,int mod)
{
	int res=1;
	while(a)
	{
		if(a&1) res=qMul(res,n,mod);
		n=qMul(n,n,mod);
		a>>=1;
	}
	return res;
}
signed main()
{
	int l;
	int cnt=1;
	while(~scanf("%lld",&l)&&l)
	{
		int d=gcd(8,l);
		int q=9*l/d;
		int t=phi(q);
		int res=inf;
		for(int i=1;i*i<=t;i++)
		{
			if(t%i!=0) continue;
			if(qPow(10,i,q)==1) res=min(res,i);
			if(qPow(10,t/i,q)==1) res=min(res,t/i);
		}
		if(res==inf) printf("Case %lld: 0\n",cnt++);
		else printf("Case %lld: %lld\n",cnt++,res);
	}
	return 0;
}