#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
const int maxn=1e6+5;
int a[maxn];
struct node
{
	int l;
	int r;
	ll sum;
	ll add;
	node():sum(0),add(0){}
}t[maxn*4];
void build(int p,int l,int r)
{
	t[p].l=l,t[p].r=r;
	if(l==r) {t[p].sum=a[l];return;}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
}
void spread(int p)
{
	if(t[p].add)
	{
		t[p*2].sum+=t[p].add*(t[p*2].r-t[p*2].l+1);
		t[p*2+1].sum+=t[p].add*(t[p*2+1].r-t[p*2+1].l+1);
		t[p*2].add+=t[p].add;
		t[p*2+1].add+=t[p].add;
		t[p].add=0;
	}
}
void update(int p,int l,int r,int x,int y,int v)
{
	if(l>=x&&r<=y)
	{
		t[p].sum+=v*(t[p].r-t[p].l+1);
		t[p].add+=v;
		return;
	}
	spread(p);
	int mid=(l+r)>>1;
	if(x<=mid) update(p*2,l,mid,x,y,v);
	if(y>mid) update(p*2+1,mid+1,r,x,y,v);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
}
ll query(int p,int l,int r,int x,int y)
{
	if(l>=x&&r<=y) return t[p].sum;
	spread(p);
	int mid=(l+r)>>1;
	ll val=0;
	if(x<=mid) val+=query(p*2,l,mid,x,y);
	if(y>mid) val+=query(p*2+1,mid+1,r,x,y);
	return val;
}
int main()
{
	int n,q;
	char s[5];
	int l,r,v;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);
	while(q--)
	{
		scanf("%s",s);
		if(s[0]=='C')	
		{
			scanf("%d%d%d",&l,&r,&v);
			update(1,1,n,l,r,v);
		}
		else 
		{
			scanf("%d%d",&l,&r);
			printf("%lld\n",query(1,1,n,l,r));
		}
	}	
	return 0;
}