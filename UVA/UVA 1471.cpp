#include<bits/stdc++.h>
using namespace std;
int a[200001];
int f[200001];
int g[200001];
int main()
{
	int T;
	scanf("%d",&T);
	int n;
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		g[1]=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i]>a[i-1]) g[i]=g[i-1]+1;
			else g[i]=1;
		}
		f[n]=1;
		for(int i=n-1;i>=1;i--)
		{
			if(a[i]<a[i+1]) f[i]=f[i+1]+1;
			else f[i]=1;
		}
		set<pair<int,int> >s;
		s.insert(pair<int,int>(a[1],g[1]));
		int ans=1;
		for(int i=2;i<=n;i++) 
		{
			set< pair<int,int> >::iterator it=s.lower_bound(pair<int,int>(a[i],g[i]));
			if(it!=s.begin())
			{
			 	ans=max(ans,f[i]+(*(--it)).second);
				if((*it).second>=g[i]) continue;
			}
			pair<int,int>x(a[i],g[i]);
			s.erase(x),s.insert(x);
			for(it=++s.find(x);it!=s.end();it++)
			{
				if((*it).second<=x.second&&(*it).first>x.first) s.erase(it);
				else break;
			}
		}
		printf("%d\n",ans);
	} 
	return 0;
}