#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
const int N=1e4+5;
int n,m,fa[N],c[N];
struct R {
    int u,v,w;
    R() {}
    R(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator < (const R &T) const {
        return w<T.w;
    }
};
vector<R> e;
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool merge(int x,int y) {
    int fx=find(x),fy=find(y);
    if(fx==fy) return false;
    fa[fx]=fy;
    return true;
}
int kruskal() {
    sort(ALL(e));
    for(int i=1;i<=n;i++) fa[i]=i;
    int bst=0,cnt=1;
    for(int i=0;i<SZ(e);i++) {
        if(merge(e[i].u,e[i].v)) {
            bst+=e[i].w;
            ++cnt;
        }
        else if(e[i].w<0) bst+=e[i].w;
    }
    return cnt==n?bst:0x3f3f3f3f;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v,w;cin>>u>>v>>w;
        e.PB(R(u,v,w));
    }
    int t=kruskal();
    int mn=-1;
    for(int i=1;i<=n;i++) {
        cin>>c[i];
        if(c[i]==-1) continue;
        if(mn==-1||c[i]<c[mn]) mn=i;
    }
    if(mn!=-1) {
        for(int i=1;i<=n;i++) if(c[i]!=-1) {
            e.PB(R(mn,i,c[i]));
        }
        t=min(t,kruskal()+c[mn]);
    }
    cout<<t<<'\n';
    return 0;
}