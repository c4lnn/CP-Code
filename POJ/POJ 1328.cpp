#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;

int n,d;
int x,y;
pdd a[1005];
int flag;

void solve(int x,int y,int i)
{
	if(d<y) {flag=1;return;}
	double t=sqrt(d*d-y*y);
	a[i]=make_pair(x-t,x+t);
}
bool cmp(pdd a,pdd b)
{
	return a.second<b.second;
}
int main()
{
	for(int k=1;;k++)
	{
		scanf("%d%d",&n,&d);
		if(n==0&&d==0) return 0;
		flag=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			solve(x,y,i);
		}
		if(flag){printf("Case %d: -1\n",k);continue;}
		sort(a+1,a+1+n,cmp);
		int res=1;
		double pos=a[1].second;
		for(int i=2;i<=n;i++) if(a[i].first>pos) res++,pos=a[i].second;
	    printf("Case %d: %d\n",k,res);
	}
	return 0;
}