#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const int INF=0x3f3f3f3f;
const int maxn=20005;
int n;
int s; 
int m; 
int edge[maxn][maxn];
int dis[maxn];
bool vis[maxn];
void init()
{
    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=n;j++)
            edge[i][j]=INF;
        dis[i]=INF;
        vis[i]=false;
    }
    s=1;
    dis[s]=0;    
}
void SPFA()
{
    queue<int>q;
    q.push(s);//??
    vis[s]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=false;
        if(u==n) continue;
        for(int i=1;i<=n;i++)//????
            if(i!=u)
                if(dis[u]<INF&&dis[i]>dis[u]+edge[u][i])
                {
                    dis[i]=dis[u]+edge[u][i];
                    if(!vis[i]) q.push(i),vis[i]=true;
                    
                }
        
    }
}

int main()
{
    int a,b,c;
    while(~scanf("%d%d",&n,&m)&&n)
    {
        init();
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            edge[a][b]=edge[b][a]=c;
        }
        SPFA();
        printf("%d\n",dis[n]); 
    }
}