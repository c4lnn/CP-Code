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
const int N=1e5+5;
int n,m,fa[N];
LL res;
bool st[N];
struct E {
    int u,v,w;
    E() {}
    E(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator < (const E &T) const {
        return w>T.w;
    }
};
vector<E> e;
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y,int v) {
    int tx=find(x),ty=find(y);
    if(st[tx]&&st[ty]) return;
    res+=v;
    if(st[tx]&&!st[ty]) fa[ty]=tx;
    else if(!st[tx]&&st[ty]) fa[tx]=ty;
    else if(tx==ty) st[tx]=true;
    else fa[tx]=ty;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int k,u,v,w;
        cin>>k>>u;
        if(k==2) cin>>v;
        cin>>w;
        if(k==1) e.EB(u,u,w);
        else e.EB(u,v,w);
    }
    sort(ALL(e));
    for(int i=1;i<=n;i++) fa[i]=i;
    for(auto x:e) merge(x.u,x.v,x.w);
    cout<<res<<'\n';
    return 0;
}