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
int n,fa[N];
struct G {
	DB x,y,z,r;
	G() {}
	G(DB x,DB y,DB z,DB r):x(x),y(y),z(z),r(r) {}
}g[N];
struct R {
	int x,y;
	DB w;
	R() {}
	R(int x,int y,DB w):x(x),y(y),w(w) {}
	bool operator < (const R &a) const {
		return w>a.w;
	}
};
DB check(G a,G b) {
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)<=(a.r+b.r)*(a.r+b.r)?0:sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z))-a.r-b.r;
}
int find(int x) {
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main() {
    while(~scanf("%d",&n)&&n) {
    	for(int i=1;i<=n;i++) fa[i]=i;
    	priority_queue<R> q;
    	for(int i=1;i<=n;i++) {
    		DB x,y,z,r;
    		scanf("%lf%lf%lf%lf",&x,&y,&z,&r);
    		g[i]=G(x,y,z,r);
    		for(int j=1;j<i;j++) q.push(R(i,j,check(g[i],g[j])));
    	}
    	DB res=0;
    	while(!q.empty()) {
    		int x=q.top().x,y=q.top().y;
    		DB w=q.top().w;
    		q.pop();
    		int tx=find(x),ty=find(y);
    		if(tx==ty) continue;
    		fa[tx]=ty;
    		res+=w;
    	}
    	printf("%.3f\n",res);
    }
    return 0;
}