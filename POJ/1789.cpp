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
const int N=2e3+5;
int fa[N];
char s[N][10];
struct E {
	int u,v,w;
	E() {}
	E(int u,int v,int w):u(u),v(v),w(w) {}
	bool operator < (const E &a) const {
		return w<a.w;
	}
}e[N*N];
int find(int x) {
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main() {
    int n;
    while(~scanf("%d",&n)&&n) {
	    for(int i=1;i<=n;i++) fa[i]=i;
	    int cnt=0;
	    for(int i=1;i<=n;i++) {
	    	scanf("%s",s[i]);
	    	for(int j=1;j<i;j++) {
	    		int w=0;
	    		for(int k=0;k<7;k++) if(s[i][k]!=s[j][k]) w++;
	    		e[++cnt]=E(i,j,w);
	    	}
	    }
	    sort(e+1,e+1+cnt);
	    int res=0;
	    for(int i=1;i<=cnt;i++) {
	    	int tx=find(e[i].u),ty=find(e[i].v);
	    	if(tx==ty) continue;
	    	fa[tx]=ty;
	    	res+=e[i].w;
	    }
	    printf("The highest possible quality is 1/%d.\n",res);
	}
    return 0;
}