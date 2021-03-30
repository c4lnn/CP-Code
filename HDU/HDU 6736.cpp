#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
 
const int N=3e6+5;
const int M=5e7+5;
const int mod=998244353;

int n,m;
int cnt;
int to[M];
int nxt[M];
int head[N];
int st[N];

ll ans;

void init() {
    ans=1;
    memset(st,0,sizeof st);
    cnt=0;
    memset(head,0,sizeof head);
}
void addedge(int a,int b) {
    cnt++;
    to[cnt]=b;
    nxt[cnt]=head[a];
    head[a]=cnt;
}
ll ksm(ll n,int a) {
    ll res=1;
    while(a)
    {
        if(a&1) res=res*n%mod;
        n=n*n%mod;
        a>>=1;
    }
    return res;
}
void dfs(int u,int pre) {
    st[u]=st[pre]+1;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(!st[v]) dfs(v,u);
        else if(st[v]>0&&v!=pre)
        {
            m-=st[u]-st[v]+1;
            ans=ans*(ksm(2,st[u]-st[v]+1)-1+mod)%mod;
        }
    }
    st[u]=-1;
}
int main() {
    int a,b;
    while(~scanf("%d%d",&n,&m)) {
        init();
        for(int i=0;i<m;i++) {
            scanf("%d%d",&a,&b);
            addedge(a,b);
            addedge(b,a);
        } 
        for(int i=1;i<=n;i++)
            if(!st[i])
                dfs(i,i);
        printf("%lld\n",ans*ksm(2,m)%mod);
    }
    return 0;
}
