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

const int N=2e5+5;
const double INF=0x3f3f3f3f;

struct node
{
	double x;
	double y;
	int type;
	bool operator < (const node &a) const 
	{
		return x < a.x;
	}
}points[N],temp[N];
double dist(node a,node b)
{
	if(a.type==b.type) return INF;
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void merge(int l,int mid,int r)
{
	int k=l,i=l,j=mid+1;
	while(i<=mid&&j<=r) 
		if(points[i].y<points[j].y) temp[k++]=points[i++];
		else temp[k++]=points[j++];
	while(i<=mid) temp[k++]=points[i++];
	while(j<=r) temp[k++]=points[j++];
	for(int i=l;i<=r;i++) points[i]=temp[i];
}
double solve(int l,int r)
{
	if(l>=r) return INF;
	int mid=l+r>>1;
	double mid_x=points[mid].x;
	double res=min(solve(l,mid),solve(mid+1,r));
	merge(l,mid,r);
	int k=0;
	for(int i=l;i<=r;i++)
		if(points[i].x>=mid_x-res&&points[i].x<=mid_x+res)
			temp[k++]=points[i];
	for(int i=0;i<k;i++)
		for(int j=i-1;j>=0&&temp[i].y-temp[j].y<res;j--)
			res=min(res,dist(temp[i],temp[j]));
	return res;
}
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%lf%lf",&points[i].x,&points[i].y),points[i].type=0;
	 	for(int i=n;i<n+n;i++) scanf("%lf%lf",&points[i].x,&points[i].y),points[i].type=1;
	 	sort(points,points+n+n);
	 	printf("%.3f\n",solve(0,2*n-1));
	} 
    return 0;
}