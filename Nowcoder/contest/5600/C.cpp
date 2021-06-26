#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e5+5;
int n,a[N],fa[N],sz[N],res;
char s[N];
VI g[N];
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y) {
    int tx=find(x),ty=find(y);
    if(tx==ty) return;
    sz[ty]+=sz[tx];
    fa[tx]=ty;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d%s",&n,s);
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1,a[i]=s[i-1]=='W'?1:0;
    for(int i=1;i<n;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
        if(a[u]&a[v]) merge(u,v);
    }
    for(int i=1;i<=n;i++) {
        if(a[i]) continue;
        int t=1;
        for(auto v:g[i]) if(a[v]) t+=sz[find(v)];
        res=max(res,t);
    }
    if(!res) res=n;
    printf("%d\n",res);
    return 0;
}