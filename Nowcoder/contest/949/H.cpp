#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) x&(-x)
const int maxn=1e5+5;
int a[maxn];
int b[maxn];
int c[maxn];
int n,m;
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
void add(int x,int v)
{
    while(x<=n)
    {
        c[x]+=v;
        x+=lowbit(x);
    }
}
int ask(int x)
{
    int res=0;
    while(x)
    {
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}
struct node
{
    int l;
    int r;
    int max_bv;
    int max_gcd;
}t[maxn*4];
void build(int p,int l,int r)
{
    t[p].l=l,t[p].r=r;
    if(l==r){t[p].max_bv=b[l],t[p].max_gcd=b[l];return;}
    int mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p].max_bv=max(abs(t[p*2].max_bv),abs(t[p*2+1].max_bv));
    t[p].max_gcd=gcd(t[p*2].max_gcd,t[p*2+1].max_gcd);
}
void update(int p,int l,int r,int x,int v)
{
    if(l==r) {t[p].max_bv+=v,t[p].max_gcd+=v;return;}
    int mid=(l+r)>>1;
    if(x<=mid) update(p*2,l,mid,x,v);
    else update(p*2+1,mid+1,r,x,v);
    t[p].max_bv=max(abs(t[p*2].max_bv),abs(t[p*2+1].max_bv));
    t[p].max_gcd=gcd(t[p*2].max_gcd,t[p*2+1].max_gcd);
}
int query_max_bv(int p,int l,int r,int x,int y)
{
    if(l>=x&&r<=y) return abs(t[p].max_bv);
    int mid=(l+r)>>1;
    if(y<=mid) return query_max_bv(p*2,l,mid,x,y);
    if(x>mid) return query_max_bv(p*2+1,mid+1,r,x,y);
    return max(query_max_bv(p*2,l,mid,x,y),query_max_bv(p*2+1,mid+1,r,x,y));
}
int query_max_gcd(int p,int l,int r,int x,int y)
{
    if(l>=x&&r<=y) return t[p].max_gcd;
    int mid=(l+r)>>1;
    if(y<=mid) return query_max_gcd(p*2,l,mid,x,y);
    if(x>mid) return query_max_gcd(p*2+1,mid+1,r,x,y);
    return gcd(query_max_gcd(p*2,l,mid,x,y),query_max_gcd(p*2+1,mid+1,r,x,y));
}
int main()
{
    a[0]=0;
    memset(c,0,sizeof c);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i]-a[i-1];
    }
    build(1,1,n);
    int opt,l,r,x;
    while(m--)
    {
        scanf("%d",&opt);
        if(opt==1)
        {
            scanf("%d%d%d",&l,&r,&x);
            add(l,x);
            add(r+1,-x);
            update(1,1,n,l,x);
            if(r<n) update(1,1,n,r+1,-x);
        }
        else if(opt==2)
        {
            scanf("%d%d",&l,&r);
            if(l==r) printf("0\n");
            else printf("%d\n",abs(query_max_bv(1,1,n,l+1,r)));
        }
        else if(opt==3)
        {
            scanf("%d%d",&l,&r);
            if(l==r) printf("%d\n",abs(a[l]+ask(l)));
            else printf("%d\n",gcd(abs(a[l]+ask(l)),abs(query_max_gcd(1,1,n,l+1,r))));
        }
    }
    return 0;
}