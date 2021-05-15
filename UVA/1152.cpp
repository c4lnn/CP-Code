#include<bits/stdc++.h>
using namespace std;
const int maxn=4005;
int a[maxn];
int b[maxn];
int c[maxn];
int d[maxn];
int p[maxn*maxn];
int main()
{
	int t;
	scanf("%d",&t);
	int n;
	for(int k=1;k<=t;k++)
	{
		scanf("%d",&n);
		int ans=0;
		for(int i=0;i<n;i++) 
			scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		int tp=0;
		for(int i=0;i<n;i++) 
			for(int j=0;j<n;j++)
				p[tp++]=a[i]+b[j];
		sort(p,p+tp);
		for(int i=0;i<n;i++) 
			for(int j=0;j<n;j++)
			{
				int key=-c[i]-d[j];
				int l=0;
				int r=tp-1;
				while(l<r)
				{
					int mid=(l+r)>>1;
					if(p[mid]<key) l=mid+1;
					else r=mid;	
				}
				while(p[l]==key&&l<tp) ans++,l++;
			}
		printf("%d\n",ans);
		if(k<t) printf("\n");
	}
	return 0;
}