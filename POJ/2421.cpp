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
int n,m,fa[N];
struct E {
	int u,v,w;
	E() {}
	E(int u,int v,int w):u(u),v(v),w(w) {}
	bool operator < (const E &a) const {
		return w>a.w;
	}
};
int find(int x) {
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main() {
    scanf("%d",&n);
	for(int i=1;i<=n;i++) fa[i]=i;
	priority_queue<E> q;
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++) {
			int w;
			scanf("%d",&w);
			if(j<=i) continue;
			q.push(E(i,j,w));
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		int tx=find(u),ty=find(v);
		if(tx!=ty) fa[tx]=ty;
	}
	int res=0;
	while(!q.empty()) {
		int x=q.top().u,y=q.top().v,w=q.top().w;
		q.pop();
		int tx=find(x),ty=find(y);
		if(tx==ty) continue;
		fa[tx]=ty;
		res+=w;
	}
	printf("%d\n",res);
    return 0;
}