#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
const int N=1e5+5;
int n,t,dep[N],fa[N],mx[N];
vi G[N];
bool st[N];
void dfs(int u) {
    dep[u]=dep[fa[u]]+1;
    for(auto v:G[u]) {
        if(v==fa[u]) continue;
        fa[v]=u;
        dfs(v);
    }
}
int find(int u) { // t 秒后 Groundhog 的位置
    for(int i=1;i<=t;i++) u=fa[u];
    return u;
}
void bfs() {
    int res=0;
    int s=find(1);
    queue<pii> q;
    q.push(mp(s,0));
    st[s]=true;
    while(q.size()) {
        auto x=q.front();
        q.pop();
        if(2*x.se>=dep[x.fi]-dep[n]) {res=max(res,x.se);continue;}
        else {
            bool f=false;
            for(auto v:G[x.fi]) if(!st[v]) f=true,st[v]=true,q.push(mp(v,x.se+1));
            if(!f) q.push(mp(x.fi,x.se+1));
        }
    }
    printf("%d\n",res);
}
int main() {
    scanf("%d%d",&n,&t);
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].pb(v);
        G[v].pb(u);
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    dfs(n);
    bfs();
    return 0;
}
/*
14 1
14 8
8 7
7 6
6 5
5 4
4 3
3 2
2 1
3 9
9 10
10 11
11 12
12 13
*/