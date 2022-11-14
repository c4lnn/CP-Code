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
const int N=505;
int fa[N];
struct P {
    DB x,y;
}p[N];
struct E {
    int u,v;
    DB w;
    E() {}
    E(int u,int v,DB w):u(u),v(v),w(w) {}
    bool operator < (const E &a) const {
        return w<a.w;
    }
}e[N*N];
DB dist(P a,P b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++) fa[i]=i;
        int cnt=0;
        for(int i=1;i<=m;i++) {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            for(int j=1;j<i;j++) e[++cnt]=E(i,j,dist(p[i],p[j]));
        }
        sort(e+1,e+1+cnt);
        DB res=0;
        m-=n;
        for(int i=1;i<=cnt&&m;i++) {
            int tx=find(e[i].u),ty=find(e[i].v);
            if(tx==ty) continue;
            fa[tx]=ty;
            m--;
            res=max(res,e[i].w);
        }
        printf("%.2f\n",res);
    }
    return 0;
}