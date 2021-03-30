#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) x&(-x) 
typedef long long ll;
const int maxn=50002;
int a[maxn];
int N;
void update(int x,int v)
{
    while(x<=N)
    {
        a[x]+=v;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int res=0;
    while(x)
    {
        res+=a[x];
        x-=lowbit(x);
    }
    return res;
}
int main()
{
    int T;
    scanf("%d",&T);
    int z;
    char s[15];
    int m,n;
    for(int i=1;i<=T;i++)
    {
        memset(a,0,sizeof a);
        scanf("%d",&N);
        for(int j=1;j<=N;j++)
        {
            scanf("%d",&z);
            update(j,z);
        }
        printf("Case %d:\n",i);
        while(~scanf("%s",s)&&s[0]!='E')
        {
            scanf("%d%d",&m,&n);
            if(s[0]=='Q') printf("%d\n",query(n)-query(m-1));
            else if(s[0]=='A') update(m,n);
            else if(s[0]=='S') update(m,-n);
        }
    }
    return 0;
}