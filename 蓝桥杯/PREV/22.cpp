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
int fa[N];
struct R {
    int u,v,w;
    R() {}
    R(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator < (const R &T) const {
        return w>T.w;
    }
};
vector<R> e;
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool merge(int x,int y) {
    int tx=find(x),ty=find(y);
    if(tx==ty) return false;
    fa[tx]=ty;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int u,v,w;cin>>u>>v>>w;
        e.PB(R(u,v,w));
    }
    sort(ALL(e));
    int pre=-1,t=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=0;i<SZ(e);i++) {
        if(merge(e[i].u,e[i].v)) {
            if(e[i].w!=pre) ++t;
            pre=e[i].w;
        }
    }
    cout<<t<<'\n';
    return 0;
}