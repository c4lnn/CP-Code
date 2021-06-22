#include<bits/stdc++.h>
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
const int N=105;
int fa[N];
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
int main() {
    int n;
    while(~scanf("%d",&n)&&n) {
        for(int i=1;i<=n;i++) fa[i]=i;
        e.clear();
        int m=n*(n-1)/2;
        for(int i=1;i<=m;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            e.PB(E(u,v,w));
        }
        sort(ALL(e));
        int res=0;
        for(auto o:e) {
            int tx=find(o.u),ty=find(o.v);
            if(tx==ty) continue;
            fa[tx]=ty;
            res+=o.w;
        }
        printf("%d\n",res);
    }
    return 0;
}