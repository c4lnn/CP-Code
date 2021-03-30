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
int n,m,fa[N],res;
int get(int x) {
	if(x==fa[x]) return x;
	return fa[x]=get(fa[x]);
}
void merge(int x,int y) {
	int tx=get(x),ty=get(y);
	if(tx==ty) return;
	fa[tx]=ty;
	res--;
} 
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) fa[i]=i;
		res=n;
		for(int i=1;i<=m;i++) {
			int x,y;
			scanf("%d%d",&x,&y);
			merge(x,y);
		}
		printf("%d\n",res);
	}
    return 0;
}