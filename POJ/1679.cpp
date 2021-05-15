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
const int N=105;
struct E {
	int u,v,w;
	E() {}
	E(int u,int v,int w):u(u),v(v),w(w) {}
	bool operator < (const E &a) const {
		return w<a.w;
	}
}e[N*N];
int n,m,fa[N],cnt;
int find(int x) {
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void kruskal() {
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+1+cnt);
	e[++cnt]=E(0,0,0);
	bool f=true;
	int res=0,tail=0,sum1=0,sum2=0;
	for(int i=1;i<=cnt;i++) {
		if(i>tail) {
			if(sum1!=sum2) {f=false;break;}
			sum1=0;
			for(int j=i;j<=cnt;j++) {
				if(e[j].w!=e[i].w) {tail=j-1;break;}
				if(find(e[j].u)!=find(e[j].v)) sum1++;
			}
			sum2=0;
		}
		if(i>cnt) break;
		int tx=find(e[i].u),ty=find(e[i].v);
		if(tx==ty) continue;
		fa[tx]=ty;
		res+=e[i].w;
		sum2++;
	}
	if(f) printf("%d\n",res);
	else puts("Not Unique!");
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
    	scanf("%d%d",&n,&m);
    	cnt=0;
    	for(int i=1;i<=m;i++) {
    		int u,v,w;
    		scanf("%d%d%d",&u,&v,&w);
    		e[++cnt]=E(u,v,w);
    	}
    	kruskal();
    }
    return 0;
}