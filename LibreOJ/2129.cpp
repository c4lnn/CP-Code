#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int fa[maxn];
int b[maxn<<1];
struct node
{
	int x;
	int y;
	int e;
}a[maxn];
int cmp(node a,node b)
{
	return a.e>b.e;
}
int get(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
int main()
{
	int T;
	scanf("%d",&T);
	int n;
	while(T--)
	{
		scanf("%d",&n);
		int t=0;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(fa,0,sizeof fa);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].e);
			b[t++]=a[i].x,b[t++]=a[i].y;
		}
		sort(b,b+t);
		int num=unique(b,b+t)-b;
		for(int i=1;i<=n;i++) a[i].x=lower_bound(b,b+num,a[i].x)-b,a[i].y=lower_bound(b,b+num,a[i].y)-b;
		for(int i=1;i<=num;i++) fa[i]=i;
		sort(a+1,a+1+n,cmp);
		int i;
		for(i=1;i<=n;i++)
		{
			int x=get(a[i].x);
			int y=get(a[i].y);
			if(a[i].e) fa[x]=y;
			else if(x==y){printf("NO\n");break;}
		}
		if(i>n) printf("YES\n");
	}
	return 0;
}