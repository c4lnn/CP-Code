#include<cstdio>
#include<iostream>
using namespace std;
//#define lowbit(x) x&-x
const int maxn=5e4+5;
int n,q;
int a[maxn];
int mx[maxn];
int mn[maxn];
int lowbit(int x)
{
    return x&-x;
}
void update(int x)
{
    while(x<=n)
    {
        mx[x]=mn[x]=a[x];
        int lx=lowbit(x);
        for(int i=1;i<lx;i<<=1) mx[x]=max(mx[x],mx[x-i]),mn[x]=min(mn[x],mn[x-i]);
        x+=lx;
    }
}
int query(int x,int y)
{
    int maxx=a[y],minn=a[y];
    while(y!=x)
    {
        for(--y;y-lowbit(y)>=x;y-=lowbit(y)) maxx=max(mx[y],maxx),minn=min(mn[y],minn);
        maxx=max(a[y],maxx),minn=min(a[y],minn);
    }
    return maxx-minn;
}
int main()
{
    int l,r;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        update(i);
    }
    while(q--)
    {
        scanf("%d%d",&l,&r);
        printf("%d\n",query(l,r));
    }
    return 0;
}