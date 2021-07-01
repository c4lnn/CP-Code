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
const int N=1e6+6;
int n,m,s,t,l,r,fa[N];
struct E {
    int u,v,w;
    E() {}
    E(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator < (const E &a) const {
        return w<a.w;
    }
};
vector<E> e;
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y) {
    int tx=find(x),ty=find(y);
    if(tx==ty) return;
    fa[tx]=ty;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        e.EB(u,v,w);
    }
    sort(ALL(e));
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=SZ(e)-1;i>=0;i--) {
        merge(e[i].u,e[i].v);
        if(find(s)==find(t)) {l=e[i].w;break;}
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=0;i<SZ(e);i++) {
        if(e[i].w<l) continue;
        merge(e[i].u,e[i].v);
        if(find(s)==find(t)) {r=e[i].w;break;}
    }
    cout<<l<<' '<<r<<'\n';
    return 0;
}