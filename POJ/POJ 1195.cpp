#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
#define lowbit(x) x&(-x) 
int S[1025][1025];
int c[1025][1025];
void update(int x,int y,int v,int s)
{
	while(x<=s)
	{
		int my=y;
		while(my<=s)
		{
			c[x][my]+=v;
			my+=lowbit(my);
		}
		x+=lowbit(x);
	}
}
ll query(int x,int y)
{
	ll res=0;
	while(x)
	{
		int my=y;
		while(my)
		{
			res+=c[x][my];
			my-=lowbit(my);
		}
		x-=lowbit(x);
	}
	return res;
}
ll range_query(int x1,int y1,int x2,int y2)
{
	return query(x2,y2)-query(x2,y1-1)-query(x1-1,y2)+query(x1-1,y1-1);
}
int main()
{
	int T;
	int s;
	int x,y,a;
	int l,b,r,t;
	while(~scanf("%d",&T)&&T!=3)
	{
		if(T==0)
		{
			scanf("%d",&s);
			for(int i=0;i<s;i++)
				for(int j=0;j<s;j++)
					S[i][j]=0,c[i][j]=0;
		}
		else if(T==1) 
		{
			scanf("%d%d%d",&x,&y,&a);
			update(x+1,y+1,a,s);
		}
		else if(T==2)
		{
			scanf("%d%d%d%d",&l,&b,&r,&t);
			printf("%lld\n",range_query(l+1,b+1,r+1,t+1));
		}
	}
	return 0;
}