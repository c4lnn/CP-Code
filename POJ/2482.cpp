#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
int n,w,h;
struct node
{
    float x;
    float y1;
    float y2;
    int c;
    node(){}
    node(float x,float y1,float y2,int c):x(x),y1(y1),y2(y2),c(c){}
    bool operator < (const node&a) const {return x<a.x;}
}a[700005];
float b[700005];
int t,tt;
struct Seg
{
    int maxn;
    int add;
    int l;
    int r;
    Seg():maxn(0),add(0){}
}tree[700000];
void init()
{
    memset(a,0,sizeof a);
    t=0;
    tt=0;
    memset(tree,0,sizeof tree);
}
void build(int p,int l,int r)
{
    tree[p].l=l,tree[p].r=r;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
}
void update(int p,int l,int r,int x,int y,int v)
{
    if(x<=l&&y>=r)
    {
        tree[p].maxn+=v;
        tree[p].add+=v;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) update(p*2,l,mid,x,y,v);
    if(y>mid) update(p*2+1,mid+1,r,x,y,v);
    tree[p].maxn=tree[p].add+max(tree[p*2].maxn,tree[p*2+1].maxn);
}
signed main()
{
    float x,y;
    int z;
    while(~scanf("%lld%lld%lld",&n,&w,&h))
    {
        init();
        for(int i=0;i<n;i++)
        {
            scanf("%f%f%lld",&x,&y,&z);
        //    x-=0.5,y-=0.5;
            a[t++]=node(x,y,y+h,z);
            a[t++]=node(x+w,y,y+h,-z);
            b[tt++]=y,b[tt++]=y+h;
        }
        sort(a,a+t);
        sort(b,b+tt);
        int num=unique(b,b+tt)-b;
        for(int i=0;i<t;i++)
        {
            a[i].y1=lower_bound(b,b+num,a[i].y1)-b+1;
            a[i].y2=lower_bound(b,b+num,a[i].y2)-b+1;
        }
        build(1,1,num-1);
        int ans=0;
        for(int i=0;i<t;i++) update(1,1,num-1,a[i].y1,a[i].y2-1,a[i].c),ans=max(ans,tree[1].maxn);
        printf("%lld\n",ans);
    }
    return 0;
}