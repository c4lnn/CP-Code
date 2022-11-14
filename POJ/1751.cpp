#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<climits>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=800;
int fa[N];
PII a[N];
struct E {
    int u,v,w;
    E() {}
    E(int u,int v,int w):u(u),v(v),w(w) {}
    bool operator < (const E &a) const {
        return w<a.w;
    }
}e[N*N];
int dist(PII a,PII b) {
    return (a.FI-b.FI)*(a.FI-b.FI)+(a.SE-b.SE)*(a.SE-b.SE);
}
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) fa[i]=i;
    int cnt=0;
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&a[i].FI,&a[i].SE);
        for(int j=1;j<i;j++) e[++cnt]=E(i,j,dist(a[i],a[j]));
    }
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        int tx=find(u),ty=find(v);
        if(tx!=ty) fa[tx]=ty;
    }
    sort(e+1,e+1+cnt);
    VPII res;
    for(int i=1;i<=cnt;i++) {
        int tx=find(e[i].u),ty=find(e[i].v);
        if(tx==ty) continue;
        fa[tx]=ty;
        res.PB(MP(e[i].u,e[i].v));
    }
    for(int i=0;i<SZ(res);i++) printf("%d %d\n",res[i].FI,res[i].SE);
    return 0;
}