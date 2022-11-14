#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=8005;
int m=13;
int n;
int a[maxn];
int b[maxn];
int c[maxn]={0};
int lowbit(int x)
{
    return x&(-x);
}
void update(int x,int v)
{
    while(x<=n)
    {
        c[x]+=v;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int ans=0,res=0;
    for(int i=m;i>=0;i--)
        if(ans+(1<<i)<=n&&res+c[ans+(1<<i)]<=a[x]) ans+=(1<<i),res+=c[ans];
    update(ans+1,-1);
    return ans+1;
}
int main()
{
    scanf("%d",&n);
    a[1]=0;
    for(int i=2;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) update(i,1);
    for(int i=n;i>=1;i--) b[i]=query(i);
    for(int i=1;i<=n;i++) printf("%d\n",b[i]);
    return 0;
}