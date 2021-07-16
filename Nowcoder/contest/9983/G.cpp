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
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=1e6+5;
int n,m,fa[N],sz[N],mx[N];
void init() {
    for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
}
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y) {
    int tx=find(x),ty=find(y);
    if(tx==ty) return;
    fa[tx]=ty;
    sz[ty]+=sz[tx];
    sz[tx]=0;
    mx[ty]=max(mx[ty],mx[tx]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    init();
    for(int i=1;i<=n;i++) cin>>mx[i];
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        merge(u,v);
    }
    LL res=0;
    for(int i=1;i<=n;i++) if(sz[i]) res+=1ll*sz[i]*mx[i];
    cout<<res<<'\n';
    return 0;
}