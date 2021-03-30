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
const int N=200005;
int n,m,fa[N],w[N];
int find(int x) {
	if(x==fa[x]) return x;
	int root=find(fa[x]);
	w[x]+=w[fa[x]];
	return fa[x]=root;
}
int main() {
    while(~scanf("%d%d",&n,&m)) {
    	for(int i=0;i<=n;i++) fa[i]=i,w[i]=0;
    	int res=0;
	    for(int i=1;i<=m;i++) {
	    	int x,y,s;
	    	scanf("%d%d%d",&x,&y,&s);
	    	x--;
	    	int tx=find(x),ty=find(y);
	    	if(tx==ty) {
	    		if(w[x]-w[y]!=s) 
	    			res++;
	    	}
	    	else {
	    		fa[tx]=ty;
	    		w[tx]=w[y]-w[x]+s;
	    	}
	    }
	    printf("%d\n",res);
	}
    return 0;
}