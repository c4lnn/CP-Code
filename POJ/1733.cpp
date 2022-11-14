#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5005;
int n,m;
int a[maxn],b[maxn],c[maxn];
char opt[10];
int t=0;
int d[maxn<<1]={0};
int fa[maxn<<1];
int v[maxn<<1];
int get(int x)
{
    if(x==fa[x]) return x;
    int root=get(fa[x]);
    v[x]^=v[fa[x]];
    return fa[x]=root;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%s",&a[i],&b[i],opt);
        c[i]=opt[0]=='e'?0:1;
        d[++t]=a[i]-1,d[++t]=b[i];
    }
    sort(d+1,d+1+t);
    int cnt=unique(d+1,d+1+t)-d-1;
    for(int i=1;i<=cnt;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x=lower_bound(d+1,d+1+cnt,a[i]-1)-d;
        int y=lower_bound(d+1,d+1+cnt,b[i])-d;
        int p=get(x),q=get(y);
        if(p==q)
        {
            if(v[x]^v[y]!=c[i]){printf("%d",i-1);return 0;}
        }
        else
        {
            fa[p]=q;
            v[p]=v[x]^v[y]^c[i];
        }
    }
    printf("%d",m);
    return 0;
}