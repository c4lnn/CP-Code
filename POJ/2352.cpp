#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define lowbit(x) x&(-x)
const int maxn=32005;
int level[maxn];
int c[maxn];
void update(int x)
{
    while(x<maxn)
    {
        c[x]++;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int res=0;
    while(x)
    {
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}
int main()
{
    int n;
    int x;
    int y;
    while(~scanf("%d",&n))
    {
        memset(level,0,sizeof level);
        memset(c,0,sizeof c);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            level[query(++x)]++;
            update(x);
        }
        for(int i=0;i<n;i++)
            printf("%d\n",level[i]);
    }
    return 0;
}