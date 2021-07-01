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
// head
const int N=1e6+5;
int mn[N];
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
void merge(int x,int y,int w) {
    int fx=find(x),fy=find(y);
    if(fx==fy) return;
    t-=w;
    fa[x]=fy;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,k;LL t;cin>>n>>m>>k>>t;
    for(int i=1;i<=n;i++) cin>>mn[i];
    for(int i=1;i<=k;i++) {
        int x;cin>>x;
        mn[x]=0;
    }
    for(int i=1;i<=n;i++) e.EB(n+1,i,mn[i]);
    for(int i=1;i<=m;i++) {
        int a,b,c;cin>>a>>b>>c;
        e.EB(a,b,c);
    }
    sort(ALL(e));
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=0;i<SZ(e);i++) {
        merge(e[i].u,e[i].v,e[i].w);
        if(t<0) return cout<<"No"<<'\n',0;
    }
    cout<<"Yes"<<'\n';
    return 0;
}