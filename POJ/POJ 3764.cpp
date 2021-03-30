#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ull,ull> pull;
//head
const int N=2e5+5;
int cnt,t;
int to[N];
int val[N];
int nxt[N];
int head[N];
int d[N];
int vis[N];
int trie[N*32][2];

void init()
{
    cnt=0;
    t=0;
    memset(head,0,sizeof head);
    memset(vis,0,sizeof vis);
    memset(trie,0,sizeof trie);
}
void addEdge(int a,int b,int v)
{
    cnt++;
    to[cnt]=b;
    val[cnt]=v;
    nxt[cnt]=head[a];
    head[a]=cnt;
}
void dfs(int node)
{
    vis[node]=1;
    for(int i=head[node];i;i=nxt[i])
    {
        if(!vis[to[i]])
        {
            d[to[i]]=val[i]^d[node];
            dfs(to[i]);
        }
    }
}
void insert(int a)
{
    int pre=0;
    for(int i=30;i>=0;i--)
    {
        int now=(a>>i)&1;
        if(!trie[pre][now]) trie[pre][now]=++t;
        pre=trie[pre][now];
    }
}
int search(int a)
{
    int pre=0;
    int res=0;
    for(int i=30;i>=0;i--)
    {
        int now=(a>>i)&1;
        if(trie[pre][now^1]) res|=(1<<i),pre=trie[pre][now^1];
        else pre=trie[pre][now];
    }
    return res;
}
int main()
{
    int n,u,v,w;
    while(~scanf("%d",&n))
    {
        init();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
            addEdge(v,u,w);
        }
        dfs(0);
        int res=0;
        for(int i=0;i<n;i++)
        {
            res=max(res,search(d[i]));
            insert(d[i]);
        }
        printf("%d\n",res);

    }
    return 0;
}