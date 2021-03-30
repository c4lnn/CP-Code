#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1001;
int v[maxn];
int prime[maxn];
int phi[maxn];
int m=0;
void euler()
{
	memset(v,0,sizeof v);
	for(int i=2;i<=maxn;i++)
	{
		if(!v[i]) v[i]=i,prime[++m]=i,phi[i]=i-1;
		for(int j=1;j<=m;j++)
		{
			if(prime[j]>v[i]||prime[j]*i>maxn) break;
			v[i*prime[j]]=prime[j];
			phi[i*prime[j]]=i%prime[j]?phi[i]*(prime[j]-1):phi[i]*prime[j];
			
		}
	} 
}
int main()
{
	euler();
	int T;
	scanf("%d",&T);
	int n;
	for(int k=1;k<=T;k++)
	{
		scanf("%d",&n);
		int ans=0;
		for(int i=2;i<=n;i++) ans+=phi[i];
		printf("%d %d %d\n",k,n,ans*2+3);
	}	
	return 0;
}