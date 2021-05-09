#include<bits/stdc++.h>

using namespace std;

#define DEBUG cout<<"DEBUG"<<endl

typedef long long ll;
typedef unsigned long long ull;

typedef pair<int,int>pii;
typedef pair<ll,ll>pll;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pii> vpii;

const int N=2e5+5;

int n,m;
int vis[N];
vi edge[N];
int cnt[3];

void init()
{
    cnt[1]=cnt[2]=0;
    for(int i=1;i<=n;i++) vis[i]=0,edge[i].clear();
}
void dfs(int u,int x)
{
    vis[u]=x;
    cnt[x]++;
    for(auto y:edge[u]) if(!vis[y]) dfs(y,3-x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("in.txt","r",stdin);
    int T;cin>>T;
    while(T--)
    {
        cin>>n>>m;
        init();
        for(int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,1);
        int t=cnt[1]<cnt[2]?1:2;
        cout<<cnt[t]<<endl;
        for(int i=1;i<=n;i++) if(vis[i]==t) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}