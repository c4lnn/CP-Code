#include <cstdio>
#include<algorithm>

using namespace std;

const int maxn=1e5+4;

int n,f; 
int a[maxn];
double s[maxn];

int main()
{
	scanf("%d%d",&n,&f);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	double l=0,r=2000;
	while(r-l>1e-6)
	{
		double mid=(l+r)/2;
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i]-mid;
		double minV=1e10;
		double ans=-1e10;
		for(int i=f;i<=n;i++)
		{
			minV=min(minV,s[i-f]);
			ans=max(ans,s[i]-minV);
		}
		if(ans>=0) l=mid;
		else r=mid;
	}
	printf("%d\n",(int)(r*1000));
	return 0;
}