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
const int N=205;
int fa[N];
struct E {
	int u,v;
	DB w;
	E() {}
	E(int u,int v,DB w):u(u),v(v),w(w) {}
	bool operator < (const E &a) const {
		return w<a.w;
	}
};
vector<E> e;
PII a[N];
DB dist(PII a,PII b) {
	return sqrt((a.FI-b.FI)*(a.FI-b.FI)+(a.SE-b.SE)*(a.SE-b.SE));
}
int find(int x) {
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n;
		scanf("%d",&n);
		e.clear();
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=n;i++) {
			int x,y;
			scanf("%d%d",&a[i].FI,&a[i].SE);
			for(int j=1;j<i;j++) e.PB(E(i,j,dist(a[i],a[j])));
		}
		sort(ALL(e));
    	DB res=0;
    	int tot=0;
    	for(auto o:e) {
    		int tx=find(o.u),ty=find(o.v);
    		if(tx==ty||o.w<10||o.w>1000) continue;
    		fa[tx]=ty;
    		res+=o.w;
    		tot++;
    	}
    	if(tot==n-1) printf("%.1f\n",res*100);
    	else puts("oh!"); 
	}
    return 0;
}