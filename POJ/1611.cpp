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
const int N=30005;
int n,m,fa[N],sz[N];
int get(int x) {
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y) {
	int fa_x=get(x),fa_y=get(y);
	if(fa_x==fa_y) return;
	sz[fa_y]+=sz[fa_x];
	fa[fa_x]=fa[fa_y];
} 
int main() {
    while(~scanf("%d%d",&n,&m)) {
    	if(n==0&&m==0) return 0;
	    for(int i=0;i<n;i++) fa[i]=i,sz[i]=1;
	    for(int i=1;i<=m;i++) {
	    	int k,x;
	    	scanf("%d%d",&k,&x);
	    	for(int j=2;j<=k;j++) {
	    		int y;
	    		scanf("%d",&y);
	    		merge(x,y);
	    	}
	    }
	    printf("%d\n",sz[get(0)]);
	}
    return 0;
}