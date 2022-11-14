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
typedef pair<double,int>pdi;

const int maxn=1005;

int n,r;
int a,b;
int pre[maxn];
int fa[maxn];
int vis[maxn];
int son[maxn];
int val[maxn];
int ans;
priority_queue<pdi>q;

int get(int x)
{
    if(x==fa[x]) return x;
    else return fa[x]=get(fa[x]);
}
void init()
{
    for(int i=1;i<=n;i++) vis[i]=0,son[i]=1,fa[i]=i;
    ans=0;
}
int main()
{
    while(~scanf("%d%d",&n,&r)&&n&&r)
    {
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&val[i]);
            ans+=val[i];
            if(i!=r) q.push(make_pair(val[i],i));
        }
        for(int i=1;i<n;i++) scanf("%d%d",&a,&b),pre[b]=a;
        while(!q.empty())
        {
            pdi u=q.top();
            q.pop();
            if(vis[u.second]) continue;
            vis[u.second]=1;
            int f=get(pre[u.second]);
            ans+=son[f]*val[u.second];
            val[f]+=val[u.second];
            son[f]+=son[u.second];
            if(f!=r)q.push(make_pair((double)val[f]/son[f],f));
            fa[u.second]=f;
        }
        printf("%d\n",ans);
    }
    return 0;
}