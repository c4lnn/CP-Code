#include <bits/stdc++.h>

using namespace std;

const int maxn=2e5+4;

int n,m;
int a[maxn];
int b[maxn*3];
int t;
int sum[maxn];

struct node
{
	int id;
	int a;
	int b;
	int cnt_a;
	int cnt_b;
}res[maxn];

bool cmp(node a,node b)
{
	return a.cnt_a>b.cnt_a||a.cnt_a==b.cnt_a&&a.cnt_b>b.cnt_b;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[t++]=a[i];
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d",&res[i].a),b[t++]=res[i].a;
	for(int i=1;i<=m;i++) scanf("%d",&res[i].b),b[t++]=res[i].b;
	sort(b,b+t);
	int cnt=unique(b,b+t)-b;
	for(int i=1;i<=n;i++) sum[lower_bound(b,b+cnt,a[i])-b]++;
	for(int i=1;i<=m;i++)  res[i].id=i,res[i].cnt_a=sum[lower_bound(b,b+cnt,res[i].a)-b],res[i].cnt_b=sum[lower_bound(b,b+cnt,res[i].b)-b];
	sort(res+1,res+1+m,cmp);
	printf("%d",res[1].id);
	return 0;
}